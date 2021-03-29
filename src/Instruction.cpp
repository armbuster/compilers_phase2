#include "Instruction.h"



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