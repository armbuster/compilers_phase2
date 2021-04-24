#ifndef _SRC_GRAPH_COLORING_H
#define _SRC_GRAPH_COLORING_H

#include "CFG.h"
#include "Instruction.h"
#include "BasicBlock.h"
#include "Register.h"
#include "Web.h"

#include "assert.h"


void briggsGraphColoring(std::vector<IR::CFG*>*);
void liveliness(IR::CFG*);
std::vector<IR::BasicBlock*>* computeInSets(IR::BasicBlock*);
bool computeOutSets(IR::BasicBlock*);
std::vector<Web*>* buildWebs(IR::CFG*);
void _buildWeb(Web*, Instruction*);




#endif // _SRC_GRAPH_COLORING_H