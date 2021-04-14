
#pragma once

#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <map>
#include <unordered_map>

#include "Register.h"
#include "IrEnums.h"
#include "typedefs.h"

class Function {
    std::string funcName;
    DataType rtype;
    InstContainer* instructions = new InstContainer();              // vector of IR instructions in program order
    InstByStringMap* brLabelToTargetInst = new InstByStringMap();
    InstByStringMap* brLabelToSrcInst = new InstByStringMap();
    InstByInstMap* targetToBrSrcInst = new InstByInstMap();
    std::map<std::string, int> branchTargetsId;                     // maps each label in IR to the index of the following instruction
    FunctionContainer subroutines;                                  // any functions called by this function
    Function* caller;                                               // function that calls this function (NULL in the case of main)
    std::deque<ProgramValue> floatList;                             // float variables used (comes from float-list in IR)
    std::deque<ProgramValue> intList;                               // int variables used
    std::map<std::string, ProgramValue> dtypeMap;
    std::map<std::string, Register*>* argumentRegisters;
    std::deque<std::string> params;
    int instr_count;

    public:
        Function(std::string name_, DataType rtype_, std::deque<ProgramValue> floatList_, std::deque<ProgramValue> intList_, std::deque<std::string> params_);

        void addInstruction(Instruction* instr);
        void addBranchTarget(std::string label);
        void addBranchTarget(std::string labelText, Instruction* inst);
        void addBranchSrc(std::string labelText, Instruction* inst);
        Instruction* getBrSrcInst(std::string label);
        InstContainer* getInstructions() { return instructions; }
        ProgramValue getDtype(std::string) { return dtypeMap.at(name); };
        std::map<std::string, ProgramValue>* getDtypeMap() { return &dtypeMap; };
        std::string getName() { return funcName; };

};