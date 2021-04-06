#include "CodeGenerator.h"
//#include "FunctionWriter.h"

CodeGenerator::CodeGenerator(Module* m, std::ostream * out)
{
    
    outStream = out;
    
    // get all function names
    programModule = m;
    std::vector<std::string>* funcNames = programModule->getFunctionNames();

    // make sure there is a main function
    std::vector<std::string>::iterator it = std::find(funcNames->begin(), funcNames->end(), "main");
    assert(it != funcNames->end());
    
    // process main function first and then the rest
    Function* mainFunc = programModule->getFunction("main");
    genFunction(mainFunc);
    for(std::string fName : *funcNames)
    {
        if (fName != "main")
            genFunction(programModule->getFunction(fName));
    }
}

std::map<std::string, MemoryLocation>* CodeGenerator::stackSetup(Function* func)
{
    // map from varnames to ProgramValue structs
    std::map<std::string, ProgramValue>* variables = func->getDtypeMap();

    writeLabel(func->getName());

    // offset from the start (top) of the data section
    int dataOffset = 0;
    std::map<std::string, int> dataSectionOffsets;

    std::map<std::string, MemoryLocation>* storageLocations = new std::map<std::string, MemoryLocation>();
    
    // give each variable a place in the data section of the stack (from top to bottom / low to high memory addresses)
    for(std::map<std::string, ProgramValue>::iterator it = variables->begin(); it != variables->end(); it++)
    {
        assert(it->second.vtype == VAR || it->second.vtype==ARRAY);
        dataSectionOffsets[it->first] = dataOffset;
        dataOffset += std::max(1, it->second.size) * 4;
    }

    // move $sp to bottom of data section
    write3Op("addiu", Register(SP), Register(SP), -1*dataOffset);

    // assign each variable an offset relative to $sp
    for(std::map<std::string, int>::iterator it = dataSectionOffsets.begin(); it != dataSectionOffsets.end(); it++)
    {
        storageLocations->insert(std::make_pair(it->first, MemoryLocation(dataOffset - it->second, Register(SP))));
    }

    return storageLocations;
}





void CodeGenerator::genFunction(Function* func)
{
    std::map<std::string, MemoryLocation>* storageLocations = stackSetup(func);
    if(func -> getName() == "main")
        setGlobalMap(storageLocations);
}



void CodeGenerator::setGlobalMap(std::map<std::string, MemoryLocation>* varMap)
{
    // copy $sp into $fp
    // $fp will stay at the bottom of main's stack frame
    write2Op("move", Register(FP), Register(SP));
    
    // change memory location of each variable from being relative to $sp to $fp
    for(std::map<std::string, MemoryLocation>::iterator it = varMap->begin(); it != varMap->end(); it++)
    {
        it->second = MemoryLocation((it->second).offset, Register(FP));
    }
    
    
    globalMap = varMap;
}




template<typename op1, typename op2, typename op3>
void CodeGenerator::write3Op(std::string mipsOp, op1 operand1, op2 operand2, op3 operand3)
{
    *outStream << "    "; // indentation for ops
    *outStream << mipsOp;
    *outStream << ", ";
    *outStream << operand1;
    *outStream << ", ";
    *outStream << operand2;
    *outStream << ", ";
    *outStream << operand3;
    *outStream << std::endl;
}


template<typename op1, typename op2>
void CodeGenerator::write2Op(std::string mipsOp, op1 operand1, op2 operand2)
{
    *outStream << "    "; // indentation for ops
    *outStream << mipsOp;
    *outStream << ", ";
    *outStream << operand1;
    *outStream << ", ";
    *outStream << operand2;
    *outStream << std::endl;
}


void CodeGenerator::writeLabel(std::string label)
{
    *outStream << label << ":" << std::endl;
}