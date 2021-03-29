#include "Function.h"

Function::Function(std::string name_, DataType rtype_, std::deque<ProgramValue> floatList_, std::deque<ProgramValue> intList_)
{
    name = name_;
    rtype = rtype_;
    floatList = floatList_;
    intList = intList_;

    //std::cout << "function constructor: " << name << std::endl;

    for(int i = 0; i < floatList.size(); i++)
    {
        // TODO : make sure this wont cause segfault
        floatList[i].dtype = FLOAT;
        dtypeMap[floatList[i].value] = floatList[i];
    }
     
    for(int i = 0; i < intList.size(); i++)
    {
        // TODO : make sure this wont cause segfault
        intList[i].dtype = INT;
        dtypeMap[intList[i].value] = intList[i];
    }
}


void Function::addInstruction(Instruction * instr)
{
    instructions.push_back(instr);
}