#pragma once


#include "Module.h"
#include "assert.h"
#include "FunctionWriter.h"

#include <vector>
#include <string>
#include <algorithm>



class CodeGenerator{
    Module * programModule;
    std::vector<FunctionWriter*> completeFuncs;
    FunctionWriter* mainWriter;

    public:
        CodeGenerator(Module * m);
        
        
        // find main
        // call FunctionWriter(main)
        // call FunctionWriter(f) for rest of functions f


};