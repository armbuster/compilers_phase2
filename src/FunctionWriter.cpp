#include "FunctionWriter.h"


FunctionWriter::FunctionWriter(CodeGenerator * codeGen_, Function * func_)
{
    codeGen = codeGen_;
    func = func_;
    stackSetup();
}


void FunctionWriter::stackSetup()
{
    // case 1 - no subroutines
    std::map<std::string, ProgramValue>* variables = func->getDtypeMap();

    // write label for function
    writeLabel(func->getName());
    
    // offset from the start (top) of the data section
    int dataOffset = 0;
    std::map<std::string, int> dataSectionOffsets;
    
    for(std::map<std::string, ProgramValue>::iterator it = variables->begin(); it != variables->end(); it++)
    {

        assert(it->second.vtype == VAR || it->second.vtype==ARRAY);
        dataSectionOffsets[it->first] = dataOffset;
        dataOffset += std::max(1, it->second.size) * 4;
    }

    writeInstruction("addiu $sp, $sp,(-"+std::to_string(dataOffset)+")");


}


void FunctionWriter::writeLabel(std::string label)
{
    std::cout << label + ":" << std::endl;
    mipsInstructions.push_back(label + ":");
}

void FunctionWriter::writeInstruction(std::string instruction)
{
    std::cout << "    " + instruction << std::endl;
    mipsInstructions.push_back("    " + instruction);
}



