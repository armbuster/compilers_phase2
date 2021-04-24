#ifndef _SRC_INTRA_BLOCK_ALLOCATION_H
#define _SRC_INTRA_BLOCK_ALLOCATION_H

#include "CFG.h"
#include "Register.h"
#include "Instruction.h"
#include "Function.h"

#include <map>
#include <vector>



void intraBlockAllocation(std::vector<IR::CFG*>*);
void blockAllocation(IR::BasicBlock* bb, Function* func);
std::map<std::string, int>* getUseCounts(IR::BasicBlock* bb);
std::vector<std::pair<std::string, int>>* sortUseCounts(std::map<std::string, int>*);
std::map<std::string, Register*>* getAssignments(std::vector<std::pair<std::string, int>>*, Function*);
void setAssignments(IR::BasicBlock* bb, std::map<std::string, Register*>*);


#endif /* _SRC_INTRA_BLOCK_ALLOCATION_H */