#pragma once


#include "Module.h"
#include "assert.h"
//#include "FunctionWriter.h"
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

    public:
        CodeGenerator(Module * m, std::ostream * out);
        

        template<typename op1, typename op2, typename op3>
        void write3Op(std::string mipsOp, op1 operand1, op2 operand2, op3 operand3);
        
        template<typename op1, typename op2>
        void write2Op(std::string mipsOp, op1 operand1, op2 operand2);
        
        void writeLabel(std::string label);

        void genFunction(Function* func);

        std::map<std::string, MemoryLocation>* stackSetup(Function* func);

        void setGlobalMap(std::map<std::string, MemoryLocation>* varMap);
        
        // find main
        // call FunctionWriter(main)
        // call FunctionWriter(f) for rest of functions f


};