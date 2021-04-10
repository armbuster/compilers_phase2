#include "BasicBlock.h"

IR::BasicBlock::BasicBlock()
{}

bool IR::BasicBlock::addInstruction(Instruction* inst)
{
	instructions_.push_back(inst);
	return true;
}

void IR::BasicBlock::print()
{
	printf("BasicBlock:\n");
	printf("\t cfgId_=%d\n", cfgId_);
	for (Instruction* inst : instructions_)
	{
		printf("\t\t");
		inst->print();
	}
}