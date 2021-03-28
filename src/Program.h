#pragma once

#include "Function.h"



class Program {

    std::vector<Function *> functionSeq;

    public:
        Function * getFunction(std::string name);
        void addFunction(Function * f);

};