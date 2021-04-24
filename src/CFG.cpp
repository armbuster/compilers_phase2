#include "CFG.h"
#include "Function.h"
#include "Instruction.h"

// Public
IR::CFG::CFG(Function* function) : bbCount_(1)
{
	function_ = function;
	isFirstInstruction_ = true;
	isPrevInstructionBr_ = false;
	
}

void IR::CFG::build()
{
	BasicBlock* bb = nullptr;

	// Assign id per function
	id_ = function_->getId();

	// std::cout << "CFG::build - 1" << std::endl;
	// Iterate over the instructions in the function
	for ( Instruction* inst : *function_->getInstructions() )
	{
		// Skip if label... even though labels are not instructions,
		// it makes the code gen easier.
		if ( inst->is(IR::LABEL) )
		{
			continue;
		}

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

		//if interprocedural is desired, then a recursive call to CFG would be needed

		// Add the instruction to the basic block
		bb->addInstruction(inst);
		inst->setParent(bb);
	}

	// Resolve the last basic block
	resolveBasicBlock(bb);

	// Add edges between BBs
	addEdges();
}

void IR::CFG::print()
{
	printf("CFG: ID: %d\n", id_);
	for (BasicBlock* bb : *basicBlocks_)
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
	bb->markFinalInstruction();
	basicBlocks_->push_back(bb);
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
	BasicBlockContainer* parents;

	for (BasicBlock* bb : *basicBlocks_)
	{
		InstContainer* instructions = bb->getInstructions();
		for (Instruction* inst : *instructions)
		{
			parents = inst->getSuccessorsParents();
			if ( parents->empty() )
			{
				continue;
			}
			else //add forward and backward edges
			{
				// forward edges
				bb->setSuccessors(parents);
				
				// backward edges
				for(IR::BasicBlock* successor : *parents)
				{
					successor->addPredecessor(bb);
				}
			}
		}
	}
}