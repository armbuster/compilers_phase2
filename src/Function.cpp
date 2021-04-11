#include "Function.h"

Function::Function(std::string name_, DataType rtype_, std::deque<ProgramValue> floatList_, std::deque<ProgramValue> intList_)
{
    name = name_;
    rtype = rtype_;
    floatList = floatList_;
    intList = intList_;
    instr_count = 0;

    //std::cout << "FUNCTION: " << name << std::endl;

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


void Function::addInstruction(Instruction* instr)
{
    //std::cout << *instr << std::endl;
    instructions->push_back(instr);
    ++instr_count;
}

void Function::addBranchTarget(std::string bTarget)
{
    branchTargetsId[bTarget] = instr_count;
}

void Function::addBranchTarget(std::string labelText, Instruction* targetInst)
{
    std::cout << "Function::addBranchTarget" << std::endl;
    brLabelToTargetInst->insert( {labelText, targetInst} );
    //toFromBrInst.insert( {} )
}

void Function::addBranchSrc(std::string labelText, Instruction* srcInst)
{
    std::cout << "Function::addBranchSrc" << std::endl;
    brLabelToSrcInst->insert( {labelText, srcInst} );
}

Instruction* Function::getBrSrcInst(std::string label)
{
    std::cout << "Function::getBrSrcInst" << std::endl;
    // If key/label DNE
    if ( brLabelToSrcInst->find(label) == brLabelToSrcInst->end() )
    {
        return nullptr;
    }
    else
    {
        std::cout << "Function::getBrSrcInst - here" << std::endl;
        return brLabelToSrcInst->at(label);
    }
}