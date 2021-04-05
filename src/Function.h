
#pragma once

#include <string>
#include <vector>
#include <deque>
#include <iostream>

#include "Instruction.h"


class Function {
    std::string name; // function name
    DataType rtype;
    std::vector<Instruction*> instructions; // vector of IR instructions in program order
    std::map<std::string, int> branchTargets; // maps each label in IR to the index of the following instruction
    std::vector<Function*> subroutines; // any functions called by this function
    Function* caller; // function that calls this function (NULL in the case of main)
    std::deque<ProgramValue> floatList; // float variables used (comes from float-list in IR)
    std::deque<ProgramValue> intList; // int variables used
    std::map<std::string, ProgramValue> dtypeMap;
    int instr_count;

    public:
        Function(std::string name_, DataType rtype_, std::deque<ProgramValue> floatList_, std::deque<ProgramValue> intList_);
        void addInstruction(Instruction* instr);
        void addBranchTarget(std::string label);
        std::string getName();
        std::vector<Instruction*>* getInstructions();
        std::map<std::string, ProgramValue>* getDtypeMap();

};