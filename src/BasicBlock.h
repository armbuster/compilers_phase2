#ifndef _SRC_BASIC_BLOCK_H
#define _SRC_BASIC_BLOCK_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>

#include "IrEnums.h"
#include "typedefs.h"

class Instruction;


namespace IR {



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
 	InstContainer* getInstructions() { return instructions_; }
 	void setSuccessors(BasicBlockContainer* successors) { successors_ = successors; }

 private:
 	InstContainer* instructions_ = new InstContainer();
 	BasicBlockContainer* successors_ = new BasicBlockContainer();
 	BasicBlockContainer* predecessors_ = new BasicBlockContainer();
 	unsigned int id_;
 	std::vector<ProgramValue> inSet_; 	// in set - UPDATED BY LIVELINESS ANALYSIS
    std::vector<ProgramValue> outSet_; 	// out set - UPDATED BY LIVELINESS ANALYSIS

    void printSuccessors();


};

}  // namespace ir


#endif /* _SRC_BASIC_BLOCK_H */