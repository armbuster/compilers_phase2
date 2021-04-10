
#pragma once

#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <unordered_map>

#include "Instruction.h"

//TODO: move this to a IrTypes file??
class Function; //used in typedefs

typedef std::vector<Instruction*> InstContainer;
typedef std::vector<Function*> FunctionContainer;

class Function {
    std::string name; // function name
    DataType rtype;
    InstContainer instructions; // vector of IR instructions in program order
    std::unordered_map<std::string, Instruction*> branchTargetsInst;
    std::map<std::string, int> branchTargetsId; // maps each label in IR to the index of the following instruction
    FunctionContainer subroutines; // any functions called by this function
    Function* caller; // function that calls this function (NULL in the case of main)
    std::deque<ProgramValue> floatList; // float variables used (comes from float-list in IR)
    std::deque<ProgramValue> intList; // int variables used
    std::map<std::string, ProgramValue> dtypeMap;
    int instr_count;

    public:
        Function(std::string name_, DataType rtype_, std::deque<ProgramValue> floatList_, std::deque<ProgramValue> intList_);
        void addInstruction(Instruction* instr);
        void addBranchTarget(std::string label);
        void addBranchTarget(std::string labelText, Instruction* inst);
        InstContainer getInstructions() { return instructions; }

};