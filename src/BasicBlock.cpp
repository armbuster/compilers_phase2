#include "BasicBlock.h"

IR::BasicBlock::BasicBlock()
{}

bool IR::BasicBlock::addInstruction(Instruction* inst)
{
	instructions_->push_back(inst);
	return true;
}

void IR::BasicBlock::addSuccessor(BasicBlock* bb)
{
	successors_->push_back(bb);
}

void IR::BasicBlock::addPredecessor(BasicBlock* bb)
{
	predecessors_->push_back(bb);
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