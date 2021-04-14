
#include "Module.h"

void Module::addFunction(Function* f)
{
    functionSeq->push_back(f);
}

std::vector<std::string>* Module::getFunctionNames()
{
    std::vector<std::string> * funcNames = new std::vector<std::string>();
    for (Function* f : *functionSeq)
        funcNames->push_back(f->getName());
    return funcNames;
}

Function* Module::getFunction(std::string name)
{

    Function* returnVal;
    returnVal = nullptr;
    for (Function* f : *functionSeq)
    {
        if(f->getName() == name)
            returnVal = f;
    }
    assert(returnVal);
    return returnVal;
}