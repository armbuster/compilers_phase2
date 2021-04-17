#ifndef _SRC_CFG_H
#define _SRC_CFG_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include "IrEnums.h"
#include "typedefs.h"
#include "BasicBlock.h"


namespace IR {

class CFG
{
 public:
 	CFG(Function* function);
 	~CFG(){};

 	void build();
 	void print();

 	void setId(unsigned int id) { id_ = id; }

 private:
 	Function* function_;
 	BasicBlockContainer* basicBlocks_ = new BasicBlockContainer();
 	bool isFirstInstruction_;
 	bool isPrevInstructionBr_;
 	unsigned int bbCount_;
 	unsigned int id_;

 	bool markIfFirstInst(Instruction* inst);
 	bool markIfPrevInstBr(Instruction* inst);
 	bool markIfBrTarget(Instruction* inst);
 	bool addBasicBlock(BasicBlock* bb);
 	bool resolveBasicBlock(BasicBlock* bb);
 	void addEdges();
};

}  // namespace IR


#endif /* _SRC_CFG_H */