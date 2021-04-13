#include "Function.h"

Function::Function(std::string name_, DataType rtype_, std::deque<ProgramValue> floatList_, std::deque<ProgramValue> intList_, std::deque<std::string> params_)
{
    funcName = name_;
    rtype = rtype_;
    floatList = floatList_;
    intList = intList_;
    params = params_;
    instr_count = 0;
    instructions = new std::vector<Instruction*>();
    argumentRegisters = new std::map<std::string, Register*>();

    
    ////// keep this
    for(int i = 0; i < floatList.size(); i++)
    {
        //std::cout << name_ <<": adding " << floatList[i].value << "to floatlist" << std::endl;
        floatList[i].dtype = FLOAT;
        dtypeMap[floatList[i].value] = floatList[i];
    }
    ////// keep this
    for(int i = 0; i < intList.size(); i++)
    {
        //std::cout << name_ <<": adding " << intList[i].value << "to intlist" << std::endl;
        intList[i].dtype = INT;
        dtypeMap[intList[i].value] = intList[i];
    }
    ////// keep this
    for(int i=0; i < params.size(); i++)
    {
        std::string p = params[i];
        Register * r = new Register(A, i);
        (*argumentRegisters)[p] = r;
    }


}

////// keep this
void Function::addInstruction(Instruction * instr)
{
    for(std::map<std::string, Register*>::iterator it = argumentRegisters->begin(); it != argumentRegisters->end(); it++)
    {
        instr->setRegisterAssignment(it->first, it->second);
    }

    instructions->push_back(instr);
    instr_count+=1;
}

////// keep this
void Function::addBranchTarget(std::string bTarget)
{
    branchTargets[bTarget] = instr_count;
}

////// keep this
std::string Function::getName()
{
    return funcName;
}

////// keep this
std::map<std::string, ProgramValue>* Function::getDtypeMap()
{
    return &dtypeMap;
}

////// keep this
std::vector<Instruction*>* Function::getInstructions()
{
    return instructions;
}

////// keep this
ProgramValue Function::getDtype(std::string name)
{
    return dtypeMap.at(name);
}