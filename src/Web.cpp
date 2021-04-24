#include "Web.h"


Web::Web(std::string var_, int id_, bool isInt_)
{
    var=var_;
    defs=1;
    webId=id_;
    isIntVar=isInt_;
}


void Web::print()
{
    printf("WEB: %s, ID %d \n", var.c_str(), webId);
    printf("\tINSTRUCTIONS: ");
    for(int i : instrIds)
        printf("%d, ", i);
    printf("\n");
    printf("\tINTERFERENCE: ");
    for(Web* w : interference)
    {
        printf("%d, ", w->getWebId());
    }
    printf("\n");
    if(isColored())
    {
        printf("\tCOLOR: %d", color);
    }
    else
        printf("\tSPILLED");
    printf("\n\n");
}


void Web::setRegister(Register reg)
{
    r=reg;
    Register * _reg = new Register(reg.getRegisterClass(), reg.getRegisterIndex());
    for(Instruction * instr : instrPtrs)
        instr->setRegisterAssignment(var, _reg);
}


void Web::merge(Web* other)
{
    merged=true;
    
    // combine interferences
    for(Web* n : interference)
        other->addInterference(n);
    
    // combine instructions
    for(Instruction* instr : instrPtrs)
    {
        other->addInstrId(instr->getId());
        other->addInstrPtr(instr);
    }
    other->incDefs(defs);
    other->incUses(uses);
}