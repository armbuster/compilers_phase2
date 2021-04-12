#include "CFG.h"
#include "Function.h"
#include "Instruction.h"

// Public
IR::CFG::CFG(Function* function) : bbCount_(0)
{
	function_ = function;
	isFirstInstruction_ = true;
	isPrevInstructionBr_ = false;
	
}

void IR::CFG::build()
{
	BasicBlock* bb = nullptr;

	// Iterate over the instructions in the function
	for ( Instruction* inst : *function_->getInstructions() )
	{
		// Check the three conditions for an instruction to be a leader
		markIfFirstInst(inst);
		markIfPrevInstBr(inst);
		markIfBrTarget(inst);

		if ( inst->isLeader() )
		{
			// Resolve the current basic block
			resolveBasicBlock(bb);

			// Create a new basic block
			bb = new BasicBlock();
		}

		//TODO: if inst is a call... create recursive call to the CFG

		// Add the instruction to the basic block
		bb->addInstruction(inst);
		inst->setParent(bb);
	}

	// Resolve the last basic block
	resolveBasicBlock(bb);

	//TODO: add edges between BBs
}

void IR::CFG::print()
{
	printf("CFG:\n");
	for (BasicBlock* bb : basicBlocks_)
	{
		printf("\t");
		bb->print();
	}
	printf("\n");
}


// Private
bool IR::CFG::markIfFirstInst(Instruction* inst)
{
	if (isFirstInstruction_)
	{
		isFirstInstruction_ = false;
		inst->markAsLeader();
		return true;
	}
	return false;
}

bool IR::CFG::markIfPrevInstBr(Instruction* inst)
{
	if (isPrevInstructionBr_)
	{
		inst->markAsLeader();
		isPrevInstructionBr_ = false;
		return true;
	}
	if ( inst->is(IR::InstType::BRANCH) )
	{
		isPrevInstructionBr_ = true;
	}
	return false;
}

bool IR::CFG::markIfBrTarget(Instruction* inst)
{
	// Branch targets marked as leaders in the irVisitor class
	return inst->isLeader();
}

bool IR::CFG::addBasicBlock(BasicBlock* bb)
{
	bb->setId(bbCount_);
	basicBlocks_.push_back(bb);
	bbCount_ += 1;
	return true;
}

bool IR::CFG::resolveBasicBlock(BasicBlock* bb)
{
	if ( bb==nullptr )
	{
		return false;
	}
	addBasicBlock(bb);
	return true;
}

void IR::CFG::addEdges()
{
	for (BasicBlock* bb : basicBlocks_)
	{

	}


}