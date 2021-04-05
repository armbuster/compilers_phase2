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
}

void AssignInstruction::setOperands(ProgramValue lhs_, ProgramValue rhs_)
{
    lhs = lhs_;
    rhs = rhs_;
}

void BinaryInstruction::setOperands(ProgramValue lhs_, ProgramValue rhs1_, ProgramValue rhs2_)
{
    lhs = lhs_;
    rhs1 = rhs1_;
    rhs2 = rhs2_;
}



void BranchInstruction::setOperands(std::string label, ProgramValue lval_, ProgramValue rval_)
{
    lval = lval_;
    rval = rval_;
}

void ReturnInstruction::setOperands(ProgramValue returnVal_)
{
    returnVal = returnVal_;
}


void CallInstruction::setOperands(std::string funcname_, std::deque<ProgramValue> args_, ProgramValue rval_)
{
    args = args_;
}

void ArrayInstruction::setOperands(ProgramValue arrayName_, ProgramValue value_, ProgramValue index_)
{
    arrayName = arrayName_;
    index = index_;
    value = value_;
}
