#include "Function.h"
#include "Instruction.h"

Function::Function(std::string name_, DataType rtype_, std::deque<ProgramValue> floatList_, std::deque<ProgramValue> intList_, std::deque<std::string> params_)
{
    funcName = name_;
    rtype = rtype_;
    floatList = floatList_;
    intList = intList_;
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
    for(int i=0; i < params_.size(); i++)
    {
        ProgramValue p = {VAR, dtypeMap.at(params_[i]).dtype, params_[i], 0};
        params.push_back(p);
    }
    
    // only ints are assigned to argument registers
    for(int i=0; i < params.size(); i++)
    {
        if(params[i].dtype==INT)
        {
            std::string p = params_[i];
            Register * r = new Register(A, i);
            (*argumentRegisters)[p] = r;
        }

    }
}

void Function::addInstruction(Instruction* instr)
{
    for(std::map<std::string, Register*>::iterator it = argumentRegisters->begin(); it != argumentRegisters->end(); it++)
    {
        instr->setRegisterAssignment(it->first, it->second);
    }

    //std::cout << *instr << std::endl;
    instructions->push_back(instr);
    ++instr_count;
}

////// keep this
void Function::addBranchTarget(std::string bTarget)
{
    branchTargetsId[bTarget] = instr_count;
}

void Function::addBranchTarget(std::string labelText, Instruction* targetInst)
{
    //std::cout << "Function::addBranchTarget" << std::endl;
    brLabelToTargetInst->insert( {labelText, targetInst} );
    //toFromBrInst.insert( {} )
}

bool Function::isinScope(std::string name)
{
    if(dtypeMap.find(name) != dtypeMap.end())
        return true;
    else
        return false;

}

void Function::addBranchSrc(std::string labelText, Instruction* srcInst)
{
    //std::cout << "Function::addBranchSrc" << std::endl;
    brLabelToSrcInst->insert( {labelText, srcInst} );
}

Instruction* Function::getBrSrcInst(std::string label)
{
    //std::cout << "Function::getBrSrcInst" << std::endl;
    // If key/label DNE
    if ( brLabelToSrcInst->find(label) == brLabelToSrcInst->end() )
    {
        return nullptr;
    }
    else
    {
        //std::cout << "Function::getBrSrcInst - here" << std::endl;
        return brLabelToSrcInst->at(label);
    }
}