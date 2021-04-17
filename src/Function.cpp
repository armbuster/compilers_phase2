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

void Function::addBranchTarget(std::string label, Instruction* targetInst)
{
    //std::cout << "Function::addBranchTarget" << std::endl;
    //If label dne then add
    if ( brLabelToTargetInst->find(label) == brLabelToTargetInst->end() )
    {
        brLabelToTargetInst->insert( {label, targetInst} );
    }

    //if srcInst has already been traversed by the visitor then add edges...
    Instruction* srcInst = getBrSrcInst(label);
    if ( srcInst != nullptr )
    {
        srcInst->addSuccessor(targetInst);
        targetInst->addPredecessor(srcInst);
    }
}

bool Function::isinScope(std::string name)
{
    if(dtypeMap.find(name) != dtypeMap.end())
        return true;
    else
        return false;

}

void Function::addBranchSrc(std::string label, Instruction* srcInst)
{
    //If label dne then add..
    if ( brLabelToSrcInst->find(label) == brLabelToSrcInst->end() )
    {
        brLabelToSrcInst->insert( {label, srcInst} );
    }
    
    //if targetInst has already been traversed by the visitor then add edges...
    Instruction* targetInst = getBrTargetInst(label);
    if ( targetInst != nullptr )
    {
        srcInst->addSuccessor(targetInst);
        targetInst->addPredecessor(srcInst);
    }
}

Instruction* Function::getBrSrcInst(std::string label)
{
    // If key/label DNE
    if ( brLabelToSrcInst->find(label) == brLabelToSrcInst->end() )
    {
        return nullptr;
    }
    else
    {
        return brLabelToSrcInst->at(label);
    }
}

Instruction* Function::getBrTargetInst(std::string label)
{
    // If key/label DNE
    if ( brLabelToTargetInst->find(label) == brLabelToTargetInst->end() )
    {
        return nullptr;
    }
    else
    {
        return brLabelToTargetInst->at(label);
    }
}