#ifndef _SRC_CFG_H
#define _SRC_CFG_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include "Module.h"
#include "BasicBlock.h"


namespace IR {

typedef std::vector<BasicBlock*> BasicBlockContainer;

class CFG
{
 public:
 	CFG(Function* function);
 	~CFG(){};

 	void build();
 	void print();

 private:
 	Function* function_;
 	BasicBlockContainer basicBlocks_;
 	bool isFirstInstruction_;
 	bool isPrevInstructionBr_;
 	unsigned int bbCount_;

 	bool markIfFirstInst(Instruction* inst);
 	bool markIfPrevInstBr(Instruction* inst);
 	bool markIfBrTarget(Instruction* inst);
 	bool addBasicBlock(BasicBlock* bb);
 	bool resolveBasicBlock(BasicBlock* bb);
};

}  // namespace IR


#endif /* _SRC_CFG_H */