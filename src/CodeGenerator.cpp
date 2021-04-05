#include "CodeGenerator.h"
#include "FunctionWriter.h"

CodeGenerator::CodeGenerator(Module * m)
{
    programModule = m;
    std::vector<std::string>* funcNames = programModule->getFunctionNames();

    // make sure there is a main function
    std::vector<std::string>::iterator it = std::find(funcNames->begin(), funcNames->end(), "main");
    assert(it != funcNames->end());
    
    mainWriter = nullptr;
    Function* mainFunc = programModule->getFunction("main");
    mainWriter = new FunctionWriter(this, mainFunc);
    completeFuncs.push_back(mainWriter);
    for(std::string fName : *funcNames)
    {
        if (fName != "main")
        {
            FunctionWriter* fWriter = new FunctionWriter(this, programModule->getFunction(fName));
            completeFuncs.push_back(fWriter);
        }
    }





    



}