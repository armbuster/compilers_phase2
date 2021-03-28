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