#include "Instruction.h"



std::ostream& operator<<(std::ostream& out, const ValType vtype)
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
    return out << s;
}


std::ostream& operator<<(std::ostream& out, const InstructionType instr)
{
    const char* s=0;
    #define PROCESS_VAL(p) case(p): s = #p; break;
    switch(instr)
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
    return out << s;
}

std::ostream& operator<<(std::ostream& out, const Instruction& instr)
{
    out << instr.instruction << ", DEFINE: ";
    for(ProgramValue p : instr.define)
        out << "(" << p.vtype << "," << p.value << ") ";
    out << "   USE: ";
    for(ProgramValue p : instr.use)
        out << "(" << p.vtype << "," << p.value << ") ";
    
    return out;
}

Instruction::Instruction(InstructionType instruction_, std::vector<ProgramValue> define_, std::vector<ProgramValue> use_)
{
    instruction = instruction_;
    define = define_;
    use = use_;
    registerAssignments = new std::map<std::string, Register *>();
}

InstructionType Instruction::getInstructionType()
{
    return instruction;
}

std::vector<ProgramValue> Instruction::getDefined()
{
    return define;
}

std::vector<ProgramValue> Instruction::getUse()
{
    return use;
}


bool Instruction::isUsed(std::string name)
{
    for(std::vector<ProgramValue>::iterator it = use.begin(); it != use.end(); it++)
    {
        if(it->value==name)
            return true;
    }
    return false;
}

bool Instruction::isDefined(std::string name)
{
    for(std::vector<ProgramValue>::iterator it = define.begin(); it != define.end(); it++)
    {
        if(it->value==name)
            return true;
    }
    return false;
}



// check if name is in define/use for this instruction
// if so, store the register assignment
// keep this
void Instruction::setRegisterAssignment(std::string name, Register* reg)
{

        (*registerAssignments)[name]=reg;
}


void AssignInstruction::setOperands(ProgramValue lhs_, ProgramValue rhs_)
{
    lhs = lhs_;
    rhs = rhs_;
}

void BinaryInstruction::setOperands(ProgramValue lhs_, ProgramValue rhs1_, ProgramValue rhs2_, InstructionType instrType_)
{
    lhs = lhs_;
    rhs1 = rhs1_;
    rhs2 = rhs2_;
    switch (instrType_)
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



void BranchInstruction::setOperands(std::string label_, ProgramValue lval_, ProgramValue rval_)
{
    lval = lval_;
    rval = rval_;
    label = label_;
}

void ReturnInstruction::setOperands(ProgramValue returnVal_)
{
    returnVal = returnVal_;
}


void CallInstruction::setOperands(std::string funcname_, std::deque<ProgramValue> args_, ProgramValue rval_)
{
    funcname = funcname_;
    args = args_;
    returnVal = rval_;
}

void ArrayInstruction::setOperands(ProgramValue arrayName_, ProgramValue value_, ProgramValue index_)
{
    arrayName = arrayName_;
    index = index_;
    value = value_;
}

void GotoInstruction::setOperands(std::string label_)
{
    label=label_;
}

void LabelInstruction::setOperands(std::string label_)
{
    label=label_;
}

////// keep these
std::map<std::string, Register*>* Instruction::getRegisterAssignments()
{
    return registerAssignments;
}