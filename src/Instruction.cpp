#include "Instruction.h"


// Forward declarations
const char* getValueTypeString(const ValType vtype);
const char* getDataTypeString(const DataType dataType);
const char* getInstOpTypeString(const InstOpType instOpType);
std::ostream& operator<<(std::ostream& out, const ValType vtype);
std::ostream& operator<<(std::ostream& out, const DataType dataType);
std::ostream& operator<<(std::ostream& out, const InstOpType instOpType);

//***************************************************************************************************
// Base
Instruction::Instruction(InstOpType instOpType_, std::vector<ProgramValue> define_, std::vector<ProgramValue> use_)
{
    instOpType = instOpType_;
    define = define_;
    use = use_;
    leader = false;
    branchTarget = false;
    registerAssignments = new std::map<std::string, Register *>();
    in = new std::set<ProgramValue>;
    out = new std::set<ProgramValue>;
}

bool Instruction::addSuccessor(Instruction* successor)
{
    // If not already in the list, then add
    if (std::find(successors_->begin(), successors_->end(), successor) == successors_->end())
    {
        successors_->push_back(successor);
        return true;
    }
    return false;
}

bool Instruction::addPredecessor(Instruction* predecessor)
{
    // If not already in the list, then add
    if (std::find(predecessors_->begin(), predecessors_->end(), predecessor) == predecessors_->end())
    {
        predecessors_->push_back(predecessor);
        return true;
    }
    return false;
}

void Instruction::printSuccessors()
{
    printf("Successors: ");
    for (Instruction* inst : *successors_)
    {
        printf("%d ", inst->getId());
    }
}

void Instruction::printPredecessors()
{
    printf("Predecessors: ");
    for (Instruction* inst : *predecessors_)
    {
        printf("%d ", inst->getId());
    }
}

void Instruction::printParent()
{
    printf("ParentBasicBlock: %d", parent_->getId());
    printf("\n");
}

void Instruction::printIn()
{
    printf("\t inSet: ");
    for(ProgramValue p : *in)
        std::cout << p.value << " ";
    std::cout << std::endl;
}


void Instruction::printOut()
{
    printf("\t outSet: ");
    for(ProgramValue p : *out)
        std::cout << p.value << " ";
    std::cout << std::endl;
}



void Instruction::updateInSet()
{
    *in = *out;
    for(ProgramValue e : define)
        in->erase(e);
    for(ProgramValue e : use)
    {
        if(e.vtype==VAR)
            in->insert(e);
    }
}

bool checkSetEquality(std::set<ProgramValue> * a, std::set<ProgramValue> * b)
{
    if(a->size() != b->size())
        return false;
    for(ProgramValue p : *a)
    {
        if(b->find(p) == b->end())
            return false;
    }
    return true;
}



bool Instruction::updateOutSet()
{
    std::set<ProgramValue>* out_ = out;
    out = new std::set<ProgramValue>;

    InstContainer* successors = getSuccessors();
    for(Instruction* instr : *successors)
    {
        for(ProgramValue p : *instr->getInSet())
            out->insert(p);
    }
    return !checkSetEquality(out_, out);
}


BasicBlockContainer* Instruction::getSuccessorsParents()
{
    BasicBlockContainer* successorsParents = new BasicBlockContainer();
    IR::BasicBlock* nextParent = nullptr;

    for (Instruction* nextInst : *successors_)
    {
        nextParent = nextInst->getParent();
        // If the parents of this and next are not equal, an edge is needed
        if (nextParent != parent_)
        {
            successorsParents->push_back(nextParent);
        }
        // If instruction is branch and nextParent._parent==_parent
        if ( instParentIsSelf(nextParent) )
        {
            successorsParents->push_back(parent_);
        }
    }
    return successorsParents;
}

void Instruction::setRegisterAssignment(std::string name, Register* reg)
{
    // this check prevents us from overwriting function argument register assignments
    if(registerAssignments->find(name) == registerAssignments->end())
        (*registerAssignments)[name]=reg;
}

std::map<std::string, Register*>* Instruction::getRegisterAssignments()
{
    return registerAssignments;
}

std::ostream& operator<<(std::ostream& out, const Instruction& instr)
{
    out << instr.instOpType << ", DEFINE: ";
    for(ProgramValue p : instr.define)
        out << "(" << p.vtype << "," << p.value << ") ";
    out << "   USE: ";
    for(ProgramValue p : instr.use)
        out << "(" << p.vtype << "," << p.value << ") ";
    
    return out;
}

bool Instruction::instParentIsSelf(IR::BasicBlock* nextParent)
{
    // If not a branch this inst can't target itself
    if ( this->is(IR::BRANCH) && nextParent == parent_ )
    {
        return true;
    }
    return false;
}

bool Instruction::isinDef(std::string var)
{
    for(ProgramValue p : define)
    {
        if (p.value==var)
            return true;
    }
    return false;
}

bool Instruction::isinUse(std::string var)
{
    for(ProgramValue p : use)
    {
        if (p.value==var)
            return true;
    }
    return false;
}

bool Instruction::isinOut(std::string var)
{
    for(ProgramValue p : *out)
    {
        if (p.value==var)
            return true;
    }
    return false;
}

bool Instruction::isinIn(std::string var)
{
    for(ProgramValue p : *in)
    {
        if (p.value==var)
            return true;
    }
    return false;
}










//***************************************************************************************************
// Assign
bool AssignInstruction::is(IR::InstType instType)
{
    return instType == IR::ASSIGN;
}

void AssignInstruction::print()
{
    printf("ID: %d ", id_);
    printf("ASSIGN: %s %s %s = %s %s %s ",
        getDataTypeString(lhs.dtype),
        getValueTypeString(lhs.vtype),
        lhs.value.c_str(),
        getDataTypeString(rhs.dtype),
        getValueTypeString(rhs.vtype),
        rhs.value.c_str());
    printSuccessors();
    printPredecessors();
    printParent();
    printIn();
    printOut();
    printf("\n");
}

void AssignInstruction::setOperands(ProgramValue lhs_, ProgramValue rhs_)
{
    lhs = lhs_;
    rhs = rhs_;
}


//***************************************************************************************************
// Binary
bool BinaryInstruction::is(IR::InstType instType)
{
    return instType == IR::BINARY;
}

void BinaryInstruction::print()
{
    printf("ID: %d ", id_);
    printf("BINARY: %s %s %s = %s %s %s, %s, %s %s %s ",
        getDataTypeString(lhs.dtype),
        getValueTypeString(lhs.vtype),
        lhs.value.c_str(),
        getDataTypeString(rhs1.dtype),
        getValueTypeString(rhs1.vtype),
        rhs1.value.c_str(),
        getInstOpTypeString(instOpType),
        getDataTypeString(rhs2.dtype),
        getValueTypeString(rhs2.vtype),
        rhs2.value.c_str());
    printSuccessors();
    printPredecessors();
    printParent();
    printIn();
    printOut();
    printf("\n");
}

void BinaryInstruction::setOperands(ProgramValue lhs_, ProgramValue rhs1_, ProgramValue rhs2_)
{
    lhs = lhs_;
    rhs1 = rhs1_;
    rhs2 = rhs2_;
    switch (instOpType)
    {
        case ADD: instrType="add"; break;
        case SUB: instrType="sub"; break;
        case MULT: instrType="mul"; break;
        case DIV: instrType="div"; break;
        case AND: instrType="and"; break;
        case OR: instrType="or"; break;
        default: assert(false);
    }
}

//***************************************************************************************************
// Branch
bool BranchInstruction::is(IR::InstType instType)
{
    return instType == IR::BRANCH;
}

void BranchInstruction::print()
{
    printf("ID: %d ", id_);
    //TODO: this should be able to handle conditional branches
    printf("BRANCH: %s %s %s, %s, %s %s %s ",
        getDataTypeString(lval.dtype),
        getValueTypeString(lval.vtype),
        lval.value.c_str(),
        getInstOpTypeString(instOpType),
        getDataTypeString(rval.dtype),
        getValueTypeString(rval.vtype),
        rval.value.c_str());
    printSuccessors();
    printPredecessors();
    printParent();
    printIn();
    printOut();
    printf("\n");
}

void BranchInstruction::setOperands(std::string label_, ProgramValue lval_, ProgramValue rval_)
{
    lval = lval_;
    rval = rval_;
    label = label_;
}

//***************************************************************************************************
// Goto
void GotoInstruction::setOperands(std::string label_)
{
    label=label_;
}

bool GotoInstruction::is(IR::InstType instType)
{
    return instType == IR::BRANCH;
}

void GotoInstruction::print()
{
    printf("ID: %d ", id_);
    //TODO: this should be able to handle conditional branches
    printf("BRANCH - GOTO: %s ",
        label.c_str());
    printSuccessors();
    printPredecessors();
    printParent();
    printIn();
    printOut();
    printf("\n");
}

//***************************************************************************************************
// Return
bool ReturnInstruction::is(IR::InstType instType)
{
    return instType == IR::RETURN;
}

void ReturnInstruction::print()
{
    printf("ID: %d ", id_);
    printf("RETURN: %s %s %s ",
        getDataTypeString(returnVal.dtype),
        getValueTypeString(returnVal.vtype),
        returnVal.value.c_str());
    printSuccessors();
    printPredecessors();
    printParent();
    printIn();
    printOut();
    printf("\n");
}

void ReturnInstruction::setOperands(ProgramValue returnVal_)
{
    returnVal = returnVal_;
}

//***************************************************************************************************
// Call
bool CallInstruction::is(IR::InstType instType)
{
    return instType == IR::CALL;
}

void CallInstruction::print()
{
    printf("ID: %d ", id_);
    printf("CALL: %s %s = %s(",
        getDataTypeString(returnVal.dtype),
        getValueTypeString(returnVal.vtype),
        funcname.c_str());
    //print args
    unsigned int numArgs = args.size();
    ProgramValue argVal;
    for (unsigned int arg=0; arg<numArgs; ++arg)
    {
        argVal = args.at(arg);
        // if the last argument
        if (arg == numArgs-1)
        {
            printf("%s %s", 
                getDataTypeString(argVal.dtype),
                getValueTypeString(argVal.vtype));
        }
        else
        {
            printf("%s %s, ", 
                getDataTypeString(argVal.dtype),
                getValueTypeString(argVal.vtype));
        }
    }
    printf(") ");
    printSuccessors();
    printPredecessors();
    printParent();
    printIn();
    printOut();
    printf("\n");
}

void CallInstruction::setOperands(std::string funcname_, std::deque<ProgramValue> args_, ProgramValue returnVal_)
{
    funcname = funcname_;
    args = args_;
    returnVal = returnVal_;
}

//***************************************************************************************************
// Array
bool ArrayInstruction::is(IR::InstType instType)
{
    return instType == IR::ARRAY;
}

void ArrayInstruction::print()
{
    printf("ID: %d ", id_);
    if (instOpType==ARRAY_STORE)
    {
        printf("ARRAY - STORE: %s %s %s[%s %s %s] = %s %s %s ",
            getDataTypeString(arrayName.dtype),
            getValueTypeString(arrayName.vtype),
            arrayName.value.c_str(),
            getDataTypeString(index.dtype),
            getValueTypeString(index.vtype),
            index.value.c_str(),
            getDataTypeString(value.dtype),
            getValueTypeString(value.vtype),
            value.value.c_str());
    }
    else if (instOpType==ARRAY_LOAD)
    {
        printf("ARRAY - LOAD: %s %s %s = %s %s %s[%s %s %s] ",
            getDataTypeString(value.dtype),
            getValueTypeString(value.vtype),
            value.value.c_str(),
            getDataTypeString(arrayName.dtype),
            getValueTypeString(arrayName.vtype),
            arrayName.value.c_str(),
            getDataTypeString(index.dtype),
            getValueTypeString(index.vtype),
            index.value.c_str());
    }
    else //instOpType==ARRAY_ASSIGN
    {
        printf("ARRAY - ASSIGN: %s %s %s = %s %s %s ",
            getDataTypeString(arrayName.dtype),
            getValueTypeString(arrayName.vtype),
            arrayName.value.c_str(),
            getDataTypeString(value.dtype),
            getValueTypeString(value.vtype),
            value.value.c_str());
    }
    printSuccessors();
    printPredecessors();
    printParent();
    printIn();
    printOut();
    printf("\n");
}



void ArrayInstruction::setOperands(ProgramValue arrayName_, ProgramValue value_, ProgramValue index_)
{
    arrayName = arrayName_;
    index = index_;
    value = value_;
}


//***************************************************************************************************
// Label
void LabelInstruction::setOperands(std::string label_)
{
    label=label_;
}

bool LabelInstruction::is(IR::InstType instType)
{
    return instType == IR::LABEL;
}

void LabelInstruction::print()
{
    //TODO: add to this
}

//***************************************************************************************************
// Print helpers
const char* getValueTypeString(const ValType vtype)
{
    const char* s=0;
    #define PROCESS_VAL(p) case(p): s = #p; break;
    switch(vtype)
    {
        PROCESS_VAL(VAR);
        PROCESS_VAL(ARRAY);
        PROCESS_VAL(LITERAL);
        PROCESS_VAL(EMPTY);
    }

    #undef PROCESS_VAL
    return s;
}

const char* getDataTypeString(const DataType dataType)
{
    const char* s=0;
    #define PROCESS_VAL(p) case(p): s = #p; break;
    switch(dataType)
    {
        PROCESS_VAL(FLOAT);
        PROCESS_VAL(INT);
        PROCESS_VAL(VOID);
        PROCESS_VAL(UNKNOWN);
    }

    #undef PROCESS_VAL
    return s;
}

const char* getInstOpTypeString(const InstOpType instOpType)
{
    const char* s=0;
    #define PROCESS_VAL(p) case(p): s = #p; break;
    switch(instOpType)
    {
        PROCESS_VAL(ASSIGN);
        PROCESS_VAL(ADD);
        PROCESS_VAL(SUB);
        PROCESS_VAL(MULT);
        PROCESS_VAL(DIV);
        PROCESS_VAL(AND);
        PROCESS_VAL(OR);
        PROCESS_VAL(GOTO);
        PROCESS_VAL(BREQ);
        PROCESS_VAL(BRNEQ);
        PROCESS_VAL(BRLT);
        PROCESS_VAL(BRGT);
        PROCESS_VAL(BRLEQ);
        PROCESS_VAL(BRGEQ);
        PROCESS_VAL(RETURN_VOID);
        PROCESS_VAL(RETURN_NONVOID);
        PROCESS_VAL(CALL);
        PROCESS_VAL(CALLR);
        PROCESS_VAL(ARRAY_STORE);
        PROCESS_VAL(ARRAY_LOAD);
        PROCESS_VAL(ARRAY_ASSIGN);
        PROCESS_VAL(LABEL);
    }

    #undef PROCESS_VAL
    return s;
}

std::ostream& operator<<(std::ostream& out, const ValType vtype)
{
    return out << getValueTypeString(vtype);
}

std::ostream& operator<<(std::ostream& out, const DataType dataType)
{
    return out << getDataTypeString(dataType);
}

std::ostream& operator<<(std::ostream& out, const InstOpType instOpType)
{
    return out << getInstOpTypeString(instOpType);
}