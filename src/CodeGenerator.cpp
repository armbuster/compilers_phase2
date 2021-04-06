#include "CodeGenerator.h"
//#include "FunctionWriter.h"

CodeGenerator::CodeGenerator(Module* m, std::ostream * out)
{
    
    outStream = out;
    
    // get all function names
    programModule = m;
    std::vector<std::string>* funcNames = programModule->getFunctionNames();

    // make sure there is a main function
    std::vector<std::string>::iterator it = std::find(funcNames->begin(), funcNames->end(), "main");
    assert(it != funcNames->end());
    
    // process main function first and then the rest
    Function* mainFunc = programModule->getFunction("main");
    genFunction(mainFunc);
    for(std::string fName : *funcNames)
    {
        if (fName != "main")
            genFunction(programModule->getFunction(fName));
    }
}

std::map<std::string, MemoryLocation>* CodeGenerator::stackSetup(Function* func)
{
    // map from varnames to ProgramValue structs
    std::map<std::string, ProgramValue>* variables = func->getDtypeMap();

    writeLabel(func->getName());

    // offset from the start (top) of the data section
    int dataOffset = 0;
    std::map<std::string, int> dataSectionOffsets;

    std::map<std::string, MemoryLocation>* storageLocations = new std::map<std::string, MemoryLocation>();
    
    // give each variable a place in the data section of the stack (from top to bottom / low to high memory addresses)
    for(std::map<std::string, ProgramValue>::iterator it = variables->begin(); it != variables->end(); it++)
    {
        assert(it->second.vtype == VAR || it->second.vtype==ARRAY);
        dataSectionOffsets[it->first] = dataOffset;
        dataOffset += std::max(1, it->second.size) * 4;
    }

    // move $sp to bottom of data section
    write3Op("addiu", Register(SP), Register(SP), -1*dataOffset);

    // assign each variable an offset relative to $sp
    for(std::map<std::string, int>::iterator it = dataSectionOffsets.begin(); it != dataSectionOffsets.end(); it++)
    {
        storageLocations->insert(std::make_pair(it->first, MemoryLocation(dataOffset - it->second, Register(SP))));
    }

    return storageLocations;
}





void CodeGenerator::genFunction(Function* func)
{
    std::map<std::string, MemoryLocation>* storageLocations = stackSetup(func);
    if(func -> getName() == "main")
        setGlobalMap(storageLocations);
    
    std::vector<Instruction*>* instructions = func->getInstructions();
    for(std::vector<Instruction*>::iterator it = instructions->begin(); it != instructions->end(); it++)
    {
        genInstruction(*it, storageLocations);
    }

}



void CodeGenerator::setGlobalMap(std::map<std::string, MemoryLocation>* varMap)
{
    // copy $sp into $fp
    // $fp will stay at the bottom of main's stack frame
    write2Op("move", Register(FP), Register(SP));

    std::map<std::string, MemoryLocation>* globalMap_ = new std::map<std::string, MemoryLocation>();
    
    // change memory location of each variable from being relative to $sp to $fp
    for(std::map<std::string, MemoryLocation>::iterator it = varMap->begin(); it != varMap->end(); it++)
    {
        globalMap_->insert(std::make_pair(it->first, MemoryLocation((it->second).offset, Register(FP))));
    }
    globalMap = globalMap_;
}



template<typename op1, typename op2, typename op3>
void CodeGenerator::write3Op(std::string mipsOp, op1 operand1, op2 operand2, op3 operand3)
{
    *outStream << "    "; // indentation for ops
    *outStream << mipsOp;
    *outStream << ", ";
    *outStream << operand1;
    *outStream << ", ";
    *outStream << operand2;
    *outStream << ", ";
    *outStream << operand3;
    *outStream << std::endl;
}


template<typename op1, typename op2>
void CodeGenerator::write2Op(std::string mipsOp, op1 operand1, op2 operand2)
{
    *outStream << "    "; // indentation for ops
    *outStream << mipsOp;
    *outStream << ", ";
    *outStream << operand1;
    *outStream << ", ";
    *outStream << operand2;
    *outStream << std::endl;
}


void CodeGenerator::writeLabel(std::string label)
{
    *outStream << label << ":" << std::endl;
}


void CodeGenerator::genInstruction(Instruction * inst, std::map<std::string, MemoryLocation>* storageLocations)
{
    InstructionType instType = inst->getInstructionType();
    if (instType == ASSIGN)
    {
        genAssign(inst, storageLocations);
    }

}


Register CodeGenerator::getStoreReg(ProgramValue name, Instruction * inst, std::map<std::string, MemoryLocation>* storageLocations)
{
    // if name is assigned a register, return assigned register
    std::map<std::string, Register*>* registerAssignments = inst->getRegisterAssignments();
    if (registerAssignments->find(name.value) != registerAssignments->end())
        return *(registerAssignments->at(name.value));
    
    // else return $t0
    else
    {   
        if (name.dtype==INT)
            return Register(T,0);
        else
            return Register(F,0);

    }
        
}

Register CodeGenerator::getLoadReg(ProgramValue name, Instruction * inst, int defaultRegisterIndex, std::map<std::string, MemoryLocation>* storageLocations)
{
    // if name is assigned a register, return assigned register
    std::map<std::string, Register*>* registerAssignments = inst->getRegisterAssignments();
    if (registerAssignments->find(name.value) != registerAssignments->end())
        return *(registerAssignments->at(name.value));
    
    // else load variable into default register and return
    else
    {
        // TODO: to handle loads from global memory, we cant assume the variable will always be here
        
        if(name.dtype==INT)
        {
            MemoryLocation variableLoc = storageLocations->at(name.value);
            write2Op("lw", Register(T, defaultRegisterIndex), variableLoc);
            return Register(T, defaultRegisterIndex);
        }
        else
        {
            MemoryLocation variableLoc = storageLocations->at(name.value);
            write2Op("l.s", Register(F, defaultRegisterIndex), variableLoc);
            return Register(F, defaultRegisterIndex);
        }

    }
}


void CodeGenerator::genAssign(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations)
{
    AssignInstruction * assignInstr = (AssignInstruction*) instr;
    ProgramValue lhs = assignInstr->lhs;
    ProgramValue rhs = assignInstr->rhs;
    Register storeRegister = getStoreReg(lhs, instr, storageLocations);
    
    if(rhs.vtype != LITERAL)
    {
        Register loadRegister = getLoadReg(rhs, instr, 1, storageLocations);
        write2Op("move", storeRegister, loadRegister);
    }
    else
    {
        if(rhs.dtype == INT)
            write2Op("li", storeRegister, rhs.value);
        else if(rhs.dtype == FLOAT)
            write2Op("li.s", storeRegister, rhs.value);
        else
            assert(false);

    }

    if(storeRegister == Register(T,0))
    {
        MemoryLocation memLocation = storageLocations->at(lhs.value);
        write2Op("sw", storeRegister, memLocation);
    }

    




}