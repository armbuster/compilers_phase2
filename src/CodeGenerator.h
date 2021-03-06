#pragma once


#include "Module.h"
#include "assert.h"
#include "Register.h"
#include "MemoryLocation.h"

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>

class CodeGenerator{
    Module * programModule;
    //std::vector<FunctionWriter*> completeFuncs;
    std::ostream * outStream;
    std::map<std::string, MemoryLocation>* globalMap;
    Function* currentFunction;
    int currentStackSize;
    RegisterAllocation registerAllocation;

    public:
        CodeGenerator(Module * m, std::ostream * out, RegisterAllocation rAllocation);
        

        template<typename op1, typename op2, typename op3>
        void write3Op(std::string mipsOp, op1 operand1, op2 operand2, op3 operand3);
        
        template<typename op1, typename op2>
        void write2Op(std::string mipsOp, op1 operand1, op2 operand2);

        template<typename op1>
        void write1Op(std::string mipsOp, op1 operand);
        void writeLabel(std::string label);

        


        void setCurrentFunction(Function* func);
        Function* getCurrentFunction();
        std::map<std::string, MemoryLocation>* stackSetup(Function* func);

        int getSubroutineMaxArguments(Function* func);

        void setGlobalMap(std::map<std::string, MemoryLocation>* varMap);
        
        
        void dumpToMemory(Register reg, std::string valName, std::map<std::string, MemoryLocation>* storageLocations);
        //void saveRegisters(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations);
        //void loadRegisters(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations);
        void spillRegisters(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations);
        
        bool isAssignedRegister(std::string valName, Instruction * inst);
        Register getAssignedRegister(std::string valName, Instruction * inst);
        RegisterAllocation getRegisterAllocationStrategy() { return registerAllocation; }



        Register getStoreReg(ProgramValue name, Instruction * inst, std::map<std::string, MemoryLocation>* storageLocations);
        Register getLoadReg(ProgramValue name, Instruction * inst, int defaultRegisterIndex, std::map<std::string, MemoryLocation>* storageLocations);
        
        void genFunction(Function* func);
        void genReturn(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations);
        void genInstruction(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations);
        void genBranch(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations);
        void genAssign(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations);
        void genCall(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations);
        void genBinary(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations);
        void genGoto(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations);
        void genLabel(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations);
        void genArrayAccess(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations);
        void genArrayAssign(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations);
        void genPrinti();
        void genPrintf();



        
        
        
        
        // find main
        // call FunctionWriter(main)
        // call FunctionWriter(f) for rest of functions f


};