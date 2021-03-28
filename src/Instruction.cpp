#include "Instruction.h"



Instruction::Instruction(InstructionType instruction_, std::vector<std::string> define_, std::vector<std::string> use_)
{
    instruction = instruction_;
    define = define_;
    use = use_;
}

void AssignInstruction::setOperands(std::string lhs_, std::string rhs_)
{
    lhs = lhs_;
    rhs = rhs_;
}