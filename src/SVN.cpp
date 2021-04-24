#include "SVN.h"

// Public
IR::SVN::SVN(CFG* cfg)
{
	cfg_ = cfg;

	if (cfg == nullptr)
	{
		printf("WARNING: IR::SVN::SVN - CFG added is null.");
	}
}

// Private
void IR::SVN::getEbbsFromCfg()
{
	BasicBlock* nextBB;

	// Get first BB from CFG
	BasicBlock* firstBB = cfg_->getBasicBlocks()->front();
	extendedBasicBlocks_->push_back( getNextEbb(firstBB) );

	// Iterate over CFG until all basic blocks have been visited and EBBs formed
	while ( !cfg_->allBlocksVisisted() )
	{
		nextBB = cfg_->getNextUnvisited();
		extendedBasicBlocks_->push_back( getNextEbb(nextBB) );
	}
}

BasicBlockContainer* IR::SVN::getNextEbb(BasicBlock* parent)
{
	BasicBlockContainer* ebb = new BasicBlockContainer();
	visitSuccessors(parent, ebb);

	return ebb;
}

void IR::SVN::visitSuccessors(BasicBlock* parent, BasicBlockContainer* ebb)
{
	if (parent==nullptr)
	{
		return;
	}
	else
	{
		parent->setVisited();
		ebb->push_back(parent);
	}

	// if parent has no more than one predecessor
	if ( parent->getPredecessors()->size() <= 1 )
	{
		// recursive call to each successor
		for ( BasicBlock* successor : *parent->getSuccessors() )
		{
			visitSuccessors(successor, ebb);
		}
	}
	else // EBB is done
	{
		return;
	}
}