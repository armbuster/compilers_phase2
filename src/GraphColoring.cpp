


#include "GraphColoring.h"


std::map<int, Register> intRegisters = {
    {0, Register(T,3)},
    {1, Register(T,4)},
    {2, Register(T,5)},
    {3, Register(T,6)},
    {4, Register(T,7)},
    {5, Register(T,8)},
    {6, Register(T,9)},
    {7, Register(S,0)},
    {8, Register(S,1)},
    {9, Register(S,2)},
    {10, Register(S,3)},
    {11, Register(S,4)},
    {12, Register(S,5)},
    {13, Register(S,6)},
    {14, Register(S,7)},
};

std::map<int, Register> floatRegisters = {
    {0, Register(F,3)},
    {1, Register(F,4)},
    {2, Register(F,5)},
    {3, Register(F,6)},
    {4, Register(F,7)},
    {5, Register(F,8)},
    {6, Register(F,9)},
    {7, Register(F,10)},
    {8, Register(F,11)},
    {9, Register(F,12)},
    {10, Register(F,13)},
    {11, Register(F,14)},
    {12, Register(F,15)},
    {13, Register(F,16)},
    {14, Register(F,17)},
    {15, Register(F,18)},
    {16, Register(F,19)},
    {17, Register(F,20)},
    {18, Register(F,21)},
    {19, Register(F,22)},
    {20, Register(F,23)},
    {21, Register(F,24)},
    {22, Register(F,25)},
    {23, Register(F,26)},
    {24, Register(F,27)},
    {25, Register(F,28)},
    {26, Register(F,29)},
    {27, Register(F,30)},
    {28, Register(F,31)}
};




bool comparator(Web* lhs, Web* rhs)
{ return lhs->getSpillCost() < rhs->getSpillCost(); }


void colorNode(Web* w, int K)
{
    std::set<int> colors;
    for(int i=0; i<K; i++)
        colors.insert(i);
    for(Web* n : *w->getNeighbors())
    {
        if (n->isColored())
            colors.erase(n->getColor());
    }
    if (colors.size()>0)
    {
        w->setColor(*colors.begin());
        if(w->isInt())
            w->setRegister(intRegisters.at(w->getColor()));
        else
            w->setRegister(floatRegisters.at(w->getColor()));
    }
        
    else
        printf("SPILL: %d \n", w->getWebId());
}




void graphColor(std::vector<Web*>* webs, int K)
{
    std::stack<Web*> webStack;
    std::vector<int> toErase;
    
    // push nodes onto stack with degree less than k
    for(int i = 0; i < webs->size(); i++)
    {
        Web* w = webs->at(i);
        if (w->getDegree() < K)
        {
            webStack.push(w);
            toErase.push_back(i);
        }
    }

    // get rid of nodes that were pushed onto stack
    for (int i=0; i < toErase.size(); i++)
    {
        int ind = toErase[i];
        webs->erase(webs->begin()+ind-i);
    }
    
    // sort remaining nodes
    std::sort(webs->begin(), webs->end(), &comparator);
    
    // push onto stack in order of ascending cost
    for(Web* w : *webs)
    {
        webStack.push(w);
    }

    // color each node
    while(webStack.size() > 0)
    {
        Web* w = webStack.top();
        webStack.pop();
        colorNode(w, K);
    }
    
}



void printWebs(std::vector<Web*>* webs)
{
    for(Web* w : *webs)
        w->print();
}

void calcSpillCost(std::vector<Web*>* webs)
{
    for(Web* w : *webs)
    {
        w->updateSpillCost();
        //printf("spillcost: %d \n", w->getSpillCost());
    }
        
}

void briggsGraphColoring(std::vector<IR::CFG*>* cfgList)
{
    for(IR::CFG* cfg : *cfgList)
    {
        liveliness(cfg);
        std::vector<Web*>* webs = buildWebs(cfg);
        calcSpillCost(webs);


        // TODO: use vector here, because the keys we sort on need to be unique
        std::vector<Web*>* floatWebs = new std::vector<Web*>;
        std::vector<Web*>* intWebs = new std::vector<Web*>;
        for(Web* w : *webs)
        {
            if(w->isInt())
                intWebs->push_back(w);
            else
                floatWebs->push_back(w);
        }
        graphColor(floatWebs, 29);
        graphColor(intWebs, 15);
        //printWebs(webs);
    }
            
        
}

void liveliness(IR::CFG* cfg)
{
    BasicBlockContainer* basicBlocks = cfg->getBasicBlocks();
    BasicBlockContainer::iterator it = basicBlocks->begin();

    bool updates=true;
    while(updates)
    {
        updates=false;
        std::vector<IR::BasicBlock*>* endNodes = computeInSets(*it);
        for(IR::BasicBlock* ptr : *endNodes)
        {
            updates |= computeOutSets(ptr);
        }
    }


}

std::vector<IR::BasicBlock*>* computeInSets(IR::BasicBlock* bb)
{
    std::vector<IR::BasicBlock*>* finalBlocks = new std::vector<IR::BasicBlock*>;
    if(bb->inSetsComputed)
        return finalBlocks;
    else
        bb->inSetsComputed=true;

    InstContainer* instructions = bb->getInstructions();
    for(Instruction* instr : *instructions)
    {
        instr->updateInSet();
    }
    
    BasicBlockContainer * successors = bb->getSuccessors();
    if(successors->size() == 0)
    {
        finalBlocks->push_back(bb);
        return finalBlocks;
    }
    else
    {
        for(IR::BasicBlock* s : *successors)
        {
            std::vector<IR::BasicBlock*>* finalBlocks_ = computeInSets(s);
            for (IR::BasicBlock* x : *finalBlocks_)
                finalBlocks->push_back(x);
        }
        return finalBlocks;
    }
}




bool computeOutSets(IR::BasicBlock* bb)
{

    bool updated = false;
    if(!bb->inSetsComputed)
        return updated;
    else
        bb->inSetsComputed=false;
    
    
    InstContainer* instructions = bb->getInstructions();
    for(int i=instructions->size()-1; i >= 0; i--)
    {
        Instruction* instr = instructions->at(i);
        updated |= instr->updateOutSet();
    }

    BasicBlockContainer* predecessors = bb->getPredecessors();
    
    if(predecessors->size()!=0)
    {
        for(IR::BasicBlock* p : *predecessors)
            updated |= computeOutSets(p);
    }
    return updated;
}

void _buildWeb(Web* w, Instruction* instr)
{
    std::string webVar = w->getName();
    if(instr->webExists(webVar))
    {
        if (instr->getWebId(webVar) == w->getWebId())
            return;
        else
        {
            Web* otherWeb = instr->getWebPtr(webVar);
            w->merge(otherWeb);
        }
    }

    // if variable is not being defined and is not in IN
    // if(!instr->isinDef(webVar) && !instr->isinIn(webVar))
    //    return;
    
    // variable is defined but never used
    // if(instr->isinDef(webVar) && !instr->isinOut(webVar))
    //    return;
    
    // variable is not used and is not used later
    if(!instr->isinUse(webVar) && !instr->isinOut(webVar))
      return;
    


    assert(instr->isinDef(webVar) || instr->isinIn(webVar));
    
    std::map<std::string, Web*>* otherWebs = instr->getWebPtrs();
    
    
    // webs interfere if they both pass through the same instruction
    for(std::map<std::string, Web*>::iterator it = otherWebs->begin(); it != otherWebs->end(); it++)
    {
        if(it->second->isInt() == w->isInt()) // only variables of matching dtype interfere
        {
            w->addInterference(it->second);
            it->second->addInterference(w);
        }
    }
    
    // add this web to this instruction
    instr->setWebId(webVar, w->getWebId());
    instr->setWebPtr(webVar, w);
    w->addInstrPtr(instr);
    w->addInstrId(instr->getId());
    if(instr->isinUse(webVar))
        w->incUses();
    
    if(!instr->isinOut(webVar))
        return;
    
    // if variable is being redefined here in terms of itself, edge case
    // TODO: see ir_test13, second web should be 2,3 4
    if(instr->isinDef(webVar) && instr->isinUse(webVar) && w->size()>1)
        return;

    // recurse on successors
    for(Instruction* s : *instr->getSuccessors())
    {
        if (instr->isinOut(webVar))
            _buildWeb(w, s);
    }
        
}


std::vector<Web*>* buildWebs(IR::CFG* cfg)
{
    std::vector<Web*>* webs = new std::vector<Web*>;
    int webId = 0;
    std::set<InstOpType> defineInstructions = {ASSIGN, ADD, SUB, MULT, DIV, AND, OR, CALLR, ARRAY_LOAD};
    for(IR::BasicBlock* bb : *cfg->getBasicBlocks())
    {
        for(Instruction* instr : *bb->getInstructions())
        {
            if (defineInstructions.find(instr->getInstOpType()) != defineInstructions.end())
            {
                std::vector<ProgramValue>* define = instr->getDefine();
                assert(define->size()==1);
                ProgramValue defineVar = define->at(0);
                assert(defineVar.vtype==VAR);
                std::string var = defineVar.value;
                Web * w = new Web(var, webId, defineVar.dtype==INT);
                webId++;
                if (instr->isinOut(var))
                    _buildWeb(w, instr);
                if(w->size() && !w->isMerged())
                    webs->push_back(w);
            }
        }
    }
    return webs;
}
