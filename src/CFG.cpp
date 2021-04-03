#include "CFG.h"


IR::CFG::CFG(Module* module)
{
	module_ = module;
	isFirstInstruction = true;
	isPrevInstructionBr = false;

	//buildCfg
}

bool IR::CFG::buildCfg()
{
	// A temp container to hold the instructions for each BB
	InstContainer* bbInstructions;
	bool isLeader;

	// Iterate over the instructions in the module
	for (Function* func : module_->getFunctions())
	{
		for (Instruction* inst : func->getInstructions())
		{
			isLeader = false;
			isLeader |= isFirstInst(inst);
			isLeader |= isPrevInstBr(inst);
			//check if br target.. how to do this??

			// If inst is leader
			//create new BB
			//	create new BB.. passing bbInstructions as an arg
			//	clear bbInstructions

			//else... continue to add inst to BB
			bbInstructions->push_back(inst);
		}
	}

	return true;
}

bool IR::CFG::isFirstInst(Instruction* inst)
{
	if (isFirstInstruction)
	{
		isFirstInstruction = false;
		inst->markAsLeader();
		return true;
	}
	return false;
}

bool IR::CFG::isPrevInstBr(Instruction* inst)
{
	if (isPrevInstructionBr)
	{
		inst->markAsLeader();
		isPrevInstructionBr = false;
		return true;
	}
	if ( inst->is(IR::InstType::BRANCH) )
	{
		isPrevInstructionBr = true;
	}
	return false;
}