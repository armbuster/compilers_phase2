
#include "IntraBlockAllocation.h"

void intraBlockAllocation(std::vector<IR::CFG*>* cfgList)
{
    for(IR::CFG* cfg : *cfgList)
    {
        for(IR::BasicBlock* bb : *cfg->getBasicBlocks())
        {
            blockAllocation(bb, cfg->getFunction());
        }
    }
}

void blockAllocation(IR::BasicBlock* bb, Function* func)
{
    std::map<std::string, int>* counts = getUseCounts(bb);
    std::vector<std::pair<std::string, int>>* sortedCounts = sortUseCounts(counts);
    std::map<std::string, Register*>* assignments = getAssignments(sortedCounts, func);
    setAssignments(bb, assignments);
}

std::map<std::string, int>* getUseCounts(IR::BasicBlock* bb)
{
    std::map<std::string, int>* counts = new std::map<std::string, int>;
    for (Instruction* inst : *bb->getInstructions())
    {
        for(ProgramValue p : *inst->getUse())
        {
            if(p.vtype==VAR)
                (*counts)[p.value]+=1;
        }
        
        for(ProgramValue p : *inst->getDefine())
        {
            if(p.vtype==VAR)
                (*counts)[p.value]+=1;
        }
    }
    return counts;
}

bool cmp(std::pair<std::string, int> a, std::pair<std::string, int> b)
{
    return a.second > b.second;
}



std::vector<std::pair<std::string, int>>* sortUseCounts(std::map<std::string, int>* counts)
{
    std::vector<std::pair<std::string, int>>* useCounts = new std::vector<std::pair<std::string, int>>;
    for(auto& it : *counts)
        useCounts->push_back(it);
    sort(useCounts->begin(), useCounts->end(), cmp);
    return useCounts;
}

std::map<std::string, Register*>* getAssignments(std::vector<std::pair<std::string, int>>* sortedCounts, Function* func)
{
    std::vector<Register> currentFloatRegisters;
    std::vector<Register> currentIntRegisters;
    std::map<std::string, Register*>* registerAssignments = new std::map<std::string, Register*>;

    for(int i = 3; i < 32; i++)
        currentFloatRegisters.push_back(Register(F,i));
    for(int i = 3; i < 10; i++)
        currentIntRegisters.push_back(Register(T,i));
    for(int i = 0; i < 8; i++)
        currentIntRegisters.push_back(Register(S,i));


    int floatCounter = 0;
    int intCounter = 0;
    for(auto& it : *sortedCounts)
    {

        DataType dtype;
        if(func->isinScope(it.first))
            dtype = func->getDtype(it.first).dtype;
        else
            continue;

        Register* r;
        if(dtype == FLOAT)
        {
            if(floatCounter < currentFloatRegisters.size())
            {
                r = new Register(currentFloatRegisters[floatCounter]);
                (*registerAssignments)[it.first]=r;
                floatCounter++;
            }

        }
        else if (dtype == INT)
        {
            if(intCounter < currentIntRegisters.size())
            {
                r = new Register(currentIntRegisters[intCounter]);
                (*registerAssignments)[it.first]=r;
                intCounter++;
            }
        }
        else
            assert(false);
    }
    
    return registerAssignments;
}

void setAssignments(IR::BasicBlock* bb, std::map<std::string, Register*>* registerMap)
{
    InstContainer* instructions = bb->getInstructions();
    for(auto& instr : *instructions)
    {
        for(auto& it : *registerMap)
            instr->setRegisterAssignment(it.first, it.second);
    }
}