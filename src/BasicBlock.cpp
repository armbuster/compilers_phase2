#include "BasicBlock.h"

IR::BasicBlock::BasicBlock()
{}

bool IR::BasicBlock::addInstruction(Instruction* inst)
{
	instructions_->push_back(inst);
	return true;
}

void IR::BasicBlock::print()
{
	printf("BasicBlock: ID: %d\n", id_);
	for (Instruction* inst : *instructions_)
	{
		printf("\t\t");
		inst->print();
	}
}