#ifndef _SRC_CFG_H
#define _SRC_CFG_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include "Module.h"


namespace IR {

class CFG
{
 private:
 	Module* module_;
 	bool isFirstInstruction;
 	bool isPrevInstructionBr;

 public:
 	CFG(Module*);
 	~CFG(){};

 	//TODO: implement this
 	void printCfg(){};

 private:
 	bool buildCfg();
 	bool isFirstInst(Instruction* inst);
 	bool isPrevInstBr(Instruction* inst);
};

}  // namespace IR


#endif /* _SRC_CFG_H */