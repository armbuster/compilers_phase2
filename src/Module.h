#pragma once

#include "Function.h"



class Module {

    std::vector<Function*> functionSeq;

    public:
        Function* getFunction(std::string name);
        void addFunction(Function* f);

};