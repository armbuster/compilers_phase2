#include "SVN.h"

// Public
IR::SVN::SVN(CFG* cfg)
{
	cfg_ = cfg;
	if (cfg == nullptr)
	{
		printf("WARNING: IR::SVN::SVN - CFG added is null.");
	}

	getEbbsFromCfg();
}

//only for testing that the EBBs are correct
void IR::SVN::printEbbs()
{
	unsigned int ebbCount = 0;
	for (auto ebb : *extendedBasicBlocks_)
	{
		++ebbCount;
		printf("\t EBB #%d: ", ebbCount);
		for (BasicBlock* bb : *ebb)
		{
			printf("BB%d ", bb->getId());
		}
		printf("\n");
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
	//parent->setVisited();
	visitSuccessors(parent, ebb);

	return ebb;
}

void IR::SVN::visitSuccessors(BasicBlock* parent, BasicBlockContainer* ebb)
{
	if (parent==nullptr)
	{
		return;
	}

	// if parent has no more than one predecessor continue traversing
	if ( parent->getPredecessors()->size() <= 1 )
	{
		parent->setVisited();
		ebb->push_back(parent);

		// recursive call to each successor
		for ( BasicBlock* successor : *parent->getSuccessors() )
		{
			visitSuccessors(successor, ebb);
		}
	}
	else // end EBB
	{
		// create degenerate EBB if it hasn't been created already
		if ( !parent->hasBeenVisited() )
		{
			BasicBlockContainer* degenerateEbb = new BasicBlockContainer();
			degenerateEbb->push_back(parent);
			extendedBasicBlocks_->push_back( degenerateEbb );
		}
		parent->setVisited();
		return;
	}
}