#pragma once

#include "assert.h"
#include "Function.h"



class Module {

    std::vector<Function *> functionSeq;

    public:
        Function * getFunction(std::string name);
        std::vector<std::string>* getFunctionNames();
        void addFunction(Function * f);

};