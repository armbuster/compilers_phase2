#ifndef _SRC_BASIC_BLOCK_H
#define _SRC_BASIC_BLOCK_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>

#include "Function.h"
#include "Instruction.h"

namespace IR {

class BasicBlock;

typedef std::vector<BasicBlock*> BasicBlockContainer;

class BasicBlock
{
 public:
 	BasicBlock();
 	~BasicBlock(){};

 	bool addInstruction(Instruction* inst);
 	void addSuccessor(BasicBlock* bb);
 	void addPredecessor(BasicBlock* bb);
 	void print();

 	void setId(unsigned int id) { id_ = id; };
 	unsigned int getId() { return id_; };

 private:
 	InstContainer* instructions_ = new InstContainer();
 	BasicBlockContainer* successors_ = new BasicBlockContainer();
 	BasicBlockContainer* predecessors_ = new BasicBlockContainer();
 	unsigned int id_;
 	std::vector<ProgramValue> inSet_; 	// in set - UPDATED BY LIVELINESS ANALYSIS
    std::vector<ProgramValue> outSet_; 	// out set - UPDATED BY LIVELINESS ANALYSIS


};

}  // namespace ir


#endif /* _SRC_BASIC_BLOCK_H */