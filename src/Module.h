#pragma once

#include "assert.h"
#include "Function.h"


class Module {

   FunctionContainer* functionSeq = new FunctionContainer();

    public:
        Function* getFunction(std::string name);
        FunctionContainer* getFunctions() { return functionSeq; };
        std::vector<std::string>* getFunctionNames();
        void addFunction(Function* f);

};