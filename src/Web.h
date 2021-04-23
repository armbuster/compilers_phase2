#ifndef _SRC_WEB_H
#define _SRC_WEB_H


#include <string>
#include <set>
#include <vector>
#include <stack>

#include "Register.h"
#include "CFG.h"
#include "Instruction.h"


class Web {
    
private:
    int webId;
    std::string var;
    std::set<int> instrIds;
    std::set<Instruction*> instrPtrs;
    int defs;
    int uses;
    std::set<Web*> interference;
    int spillCost;
    bool isIntVar;
    int color;
    bool isColored_=false;
    bool merged = false;
    Register r;

public:
    Web(std::string, int, bool);
    //void setWebId(int id) { webId = id; }
    std::string getName() { return var; }
    int getWebId() { return webId; }
    int getDefs() { return defs; }
    int getUses() { return uses; }
    void incUses(int n=1) { uses+=n; }
    void incDefs(int n=1) { defs+=n; }
    void print();
    void merge(Web*);
    bool isMerged() { return merged; }
    void addInterference(Web* w){ interference.insert(w); }
    void addInstrId(int id) { instrIds.insert(id); }
    void addInstrPtr(Instruction* ptr) { instrPtrs.insert(ptr); }
    int size() { return instrIds.size(); }
    void updateSpillCost() { spillCost = uses*2 + defs;}
    int getSpillCost() { return spillCost; }
    bool isInt() { return isIntVar; }
    int getDegree() { return interference.size(); }
    std::set<Web*>* getNeighbors() { return &interference; }
    int getColor() { return color; }
    void setColor(int c) { color = c; isColored_ = true;}
    bool isColored(){ return isColored_; }
    void setRegister(Register reg);
    Register getRegister(){ return r; }
    //std::set<Register*>* getInstrPtrs() { return instrPtrs; }

    //bool operator() (Web *a, Web *b) const { return a->getSpillCost() < b->getSpillCost(); }

};







#endif // _SRC_WEB_H