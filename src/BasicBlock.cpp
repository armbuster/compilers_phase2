#include "BasicBlock.h"
#include "Instruction.h"

IR::BasicBlock::BasicBlock() : id_(0)
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
	printSuccessors();
	printf("\n\n");
}

// Private
void IR::BasicBlock::printSuccessors()
{
	printf("\t");
	printf("BasicBlockSuccessors: ");
	for (BasicBlock* successor : *successors_)
	{
		printf("%d ", successor->getId());
	}
}