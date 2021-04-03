#pragma once

#include "Function.h"


class Module {

   FunctionContainer functionSeq;

    public:
        Function* getFunction(std::string name);
        FunctionContainer getFunctions() { return functionSeq; };
        void addFunction(Function* f);

};