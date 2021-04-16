#include "CodeGenerator.h"
#include "Instruction.h"

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
    genPrinti();
    genPrintf();
    
    // process main function first and then the rest
    Function* mainFunc = programModule->getFunction("main");
    genFunction(mainFunc);
    for(std::string fName : *funcNames)
    {
        if (fName != "main")
            genFunction(programModule->getFunction(fName));
    }
}

void CodeGenerator::genPrinti()
{
    *outStream << ".data" << std::endl;
    *outStream << "newline: .asciiz \"\\n\"" << std::endl;
    *outStream << ".text" << std::endl;
    *outStream << "printi:" << std::endl;
    *outStream << "    li $v0, 1" << std::endl;
    *outStream << "    syscall" << std::endl;
    *outStream << "    li $v0, 4" << std::endl;
    *outStream << "    la $a0, newline" << std::endl;
    *outStream << "    syscall" << std::endl;
    *outStream << "    jr $ra" << std::endl;
    *outStream << "\n\n\n";
}

void CodeGenerator::genPrintf()
{
    *outStream << "printf:" << std::endl;
    *outStream << "    mtc1 $a0, $f12" << std::endl;
    *outStream << "    li $v0, 2" << std::endl;
    *outStream << "    syscall" << std::endl;
    *outStream << "    li $v0, 4" << std::endl;
    *outStream << "    la $a0, newline" << std::endl;
    *outStream << "    syscall" << std::endl;
    *outStream << "    jr $ra" << std::endl;
    *outStream << "\n\n\n";
}





std::map<std::string, MemoryLocation>* CodeGenerator::stackSetup(Function* func)
{
    // map from varnames to ProgramValue structs
    std::map<std::string, ProgramValue>* variables = nullptr;
    variables = func->getDtypeMap();

    int maxArgs = getSubroutineMaxArguments(func);

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

    if(maxArgs > 0)
    {
        dataSectionOffsets["_ra"] = dataOffset;
        dataOffset+=4;
        for(int i = 0; i < maxArgs; i++)
        {
            dataSectionOffsets["_arg" + std::to_string(i)] = dataOffset;
            dataOffset+=4;
        }

    }

    // move $sp to bottom of data section
    write3Op("addiu", Register(SP), Register(SP), -1*dataOffset);
    currentStackSize = dataOffset;

    // assign each variable an offset relative to $sp
    for(std::map<std::string, int>::iterator it = dataSectionOffsets.begin(); it != dataSectionOffsets.end(); it++)
    {
        storageLocations->insert(std::make_pair(it->first, MemoryLocation(dataOffset - it->second, Register(SP))));
    }

    // immediately spill all floating point registers to memory
    std::deque<ProgramValue>* params = func->getParams();
    for(int i = 0; i < params->size(); i++)
    {
        if((*params)[i].dtype == FLOAT)
            write2Op("sw", Register(A, i), storageLocations->at((*params)[i].value));
    }




    return storageLocations;
}





void CodeGenerator::genFunction(Function* func)
{
    std::map<std::string, MemoryLocation>* storageLocations = stackSetup(func);
    if(func -> getName() == "main")
        setGlobalMap(storageLocations);
    setCurrentFunction(func);
    
    std::vector<Instruction*>* instructions = func->getInstructions();
    for(std::vector<Instruction*>::iterator it = instructions->begin(); it != instructions->end(); it++)
    {
        genInstruction(*it, storageLocations);
    }
}




void CodeGenerator::setCurrentFunction(Function* func)
{
    currentFunction=func;
}
Function* CodeGenerator::getCurrentFunction()
{
    return currentFunction;
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


template<typename op1>
void CodeGenerator::write1Op(std::string mipsOp, op1 operand1)
{
    *outStream << "    "; // indentation for ops
    *outStream << mipsOp;
    *outStream << ", ";
    *outStream << operand1;
    *outStream << std::endl;
}




void CodeGenerator::writeLabel(std::string label)
{
    *outStream << label << ":" << std::endl;
}


void CodeGenerator::genInstruction(Instruction * inst, std::map<std::string, MemoryLocation>* storageLocations)
{
    InstOpType instType = inst->getInstOpType();
    switch(instType){
        case ASSIGN: genAssign(inst, storageLocations); break;
        case CALL: genCall(inst, storageLocations); break;
        case CALLR: genCall(inst, storageLocations); break;
        case ADD: genBinary(inst, storageLocations); break;
        case SUB: genBinary(inst, storageLocations); break;
        case MULT: genBinary(inst, storageLocations); break;
        case DIV: genBinary(inst, storageLocations); break;
        case AND: genBinary(inst, storageLocations); break;
        case OR: genBinary(inst, storageLocations); break;
        case BREQ: genBranch(inst, storageLocations); break;
        case BRNEQ: genBranch(inst, storageLocations); break;
        case BRGT: genBranch(inst, storageLocations); break;
        case BRGEQ: genBranch(inst, storageLocations); break;
        case BRLT: genBranch(inst, storageLocations); break;
        case BRLEQ: genBranch(inst, storageLocations); break;
        case GOTO: genGoto(inst, storageLocations); break;
        case LABEL: genLabel(inst, storageLocations); break;
        case RETURN_VOID: genReturn(inst, storageLocations); break;
        case RETURN_NONVOID: genReturn(inst, storageLocations); break;
        case ARRAY_LOAD: genArrayAccess(inst, storageLocations); break;
        case ARRAY_STORE: genArrayAccess(inst, storageLocations); break;
        case ARRAY_ASSIGN: genArrayAssign(inst, storageLocations); break;
    }
    

}

int CodeGenerator::getSubroutineMaxArguments(Function* func)
{
    int maxArguments = 0;
    std::vector<Instruction*>* instructions = func->getInstructions();
    for(std::vector<Instruction*>::iterator it = instructions->begin(); it != instructions->end(); it++)
    {
        if ((*it)->getInstOpType() == CALL || (*it)->getInstOpType() == CALLR)
        {
            CallInstruction * instr = (CallInstruction*) (*it);
            maxArguments = std::max(maxArguments, (int) (instr->args).size());
        }
    }
    return maxArguments;
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
        else if (name.dtype==FLOAT)
            return Register(F,0);
        else
        {
            assert(false);
        }

    }
        
}

bool CodeGenerator::isAssignedRegister(std::string valName, Instruction * inst)
{
        // if name is assigned a register, return assigned register
    std::map<std::string, Register*>* registerAssignments = inst->getRegisterAssignments();
    if (registerAssignments->find(valName) != registerAssignments->end())
        return true;
    else
        return false;

}


Register CodeGenerator::getAssignedRegister(std::string valName, Instruction * inst)
{
        // if name is assigned a register, return assigned register
    std::map<std::string, Register*>* registerAssignments = inst->getRegisterAssignments();
    return *(registerAssignments->at(valName));
}





Register CodeGenerator::getLoadReg(ProgramValue name, Instruction * inst, int defaultRegisterIndex, std::map<std::string, MemoryLocation>* storageLocations)
{
    if(name.vtype==LITERAL)
    {
        if(name.dtype == INT)
        {
            write2Op("li", Register(T, defaultRegisterIndex), name.value);
            return Register(T, defaultRegisterIndex);
        }
        else if(name.dtype == FLOAT)
        {
            write2Op("li.s", Register(F, defaultRegisterIndex), name.value);
            return Register(F, defaultRegisterIndex);
        }
        else
            assert(false);
    }
    else
    {
        if(isAssignedRegister(name.value, inst))
            return getAssignedRegister(name.value, inst);
        
        // else load variable into default register and return
        else
        {
            MemoryLocation variableLoc(0,Register(T,0));
            if(storageLocations->find(name.value) != storageLocations->end())
                variableLoc = storageLocations->at(name.value);
            else if(globalMap->find(name.value) != globalMap->end())
                variableLoc = globalMap->at(name.value);
            else
                assert(false);

            if(name.dtype==INT)
            {
                write2Op("lw", Register(T, defaultRegisterIndex), variableLoc);
                return Register(T, defaultRegisterIndex);
            }
            else if(name.dtype==FLOAT)
            {
                write2Op("l.s", Register(F, defaultRegisterIndex), variableLoc);
                return Register(F, defaultRegisterIndex);
            }
            else
                assert(false);

        }
    }

}

void CodeGenerator::saveRegisters(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations)
{
    std::map<std::string, Register*>* rAssignments = instr->getRegisterAssignments();
    for(std::map<std::string, Register*>::iterator it = rAssignments->begin(); it != rAssignments->end(); it++)
    {
        MemoryLocation memLoc = storageLocations->at(it->first);
        write2Op("sw", *(it->second), memLoc);
    }

}

void CodeGenerator::loadRegisters(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations)
{
    std::map<std::string, Register*>* rAssignments = instr->getRegisterAssignments();
    for(std::map<std::string, Register*>::iterator it = rAssignments->begin(); it != rAssignments->end(); it++)
    {
        MemoryLocation memLoc = storageLocations->at(it->first);
        write2Op("lw", *(it->second), memLoc);
    }
}


void CodeGenerator::dumpToMemory(Register storeRegister, std::string valName, std::map<std::string, MemoryLocation>* storageLocations)
{
    
    // dump variable back to memory
    MemoryLocation variableLoc(0,Register(T,0));
    if(storageLocations->find(valName) != storageLocations->end())
        variableLoc = storageLocations->at(valName);
    else if(globalMap->find(valName) != globalMap->end())
        variableLoc = globalMap->at(valName);
    else
        assert(false);

    if(storeRegister.getRegisterClass() == T)
    {
        write2Op("sw", storeRegister, variableLoc);
    }
    else if(storeRegister.getRegisterClass() == F)
    {
        write2Op("s.s", storeRegister, variableLoc);
    }

}


void CodeGenerator::genBinary(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations)
{
    BinaryInstruction * binaryInstr = (BinaryInstruction*) instr;
    ProgramValue rhs1 = binaryInstr->rhs1;
    ProgramValue rhs2 = binaryInstr->rhs2;
    ProgramValue lhs = binaryInstr->lhs;

    Register storeRegister = getStoreReg(lhs, instr, storageLocations);
    Register loadRegister1 = getLoadReg(rhs1, instr, 1, storageLocations);
    Register loadRegister2 = getLoadReg(rhs2, instr, 2, storageLocations);

    //assert((loadRegister1.getRegisterClass() == loadRegister2.getRegisterClass()) && (loadRegister2.getRegisterClass() == storeRegister.getRegisterClass()));
    
    std::string instruction = binaryInstr->instrType;
    if(loadRegister2.getRegisterClass() == F)
        instruction+=".s";
    write3Op(instruction, storeRegister, loadRegister1, loadRegister2);
    if(!isAssignedRegister(lhs.value, instr))
        dumpToMemory(storeRegister, lhs.value, storageLocations);


}



void CodeGenerator::genCall(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations)
{
    write2Op("sw", Register(RA), storageLocations->at("_ra"));
    CallInstruction * callInstr = (CallInstruction*) instr;
    
    // spill allocated registers
    saveRegisters(instr, storageLocations);

    for(int i = 0; i < (callInstr->args).size(); i++)
    {
        if(i < 4)
        {
            ProgramValue arg = (callInstr->args)[i];
            if(arg.vtype==LITERAL)
            {
                if(arg.dtype==INT)
                    write2Op("li", Register(A,i), arg.value);
                if(arg.dtype==FLOAT)
                {
                    write2Op("li.s", Register(F,0), arg.value);
                    write2Op("mfc1", Register(A,i), Register(F,0));
                }

            }

                

            else if(arg.vtype==VAR)
            {
                if(!isAssignedRegister(arg.value, instr))
                {
                    MemoryLocation memLocation = storageLocations->at(arg.value);
                    write2Op("lw", Register(A, i), memLocation);
                }
                else if(Register(A, i) != getAssignedRegister(arg.value, instr))
                {
                    write2Op("copy", Register(A, i), getAssignedRegister(arg.value, instr));
                }
                    
            }
            else
                assert(false);
            
        }
        else
            assert(false);
    }

    write1Op("jal", callInstr->funcname);
    write2Op("lw", Register(RA), storageLocations->at("_ra"));
    
    // restore allocated registers
    loadRegisters(instr, storageLocations);

    
    // if there is a return val, copy it from $v0
    ProgramValue rval = callInstr->returnVal;
    if(rval.vtype != EMPTY)
    {
        assert(rval.vtype==VAR);
        Register storeReg = getStoreReg(rval, instr, storageLocations);
        
        if(storeReg.getRegisterClass()==T)
            write2Op("move", storeReg, Register(V, 0));
        else if(storeReg.getRegisterClass()==F)
            write2Op("mtc1", Register(V, 0), storeReg);
        else
            assert(false);


        if(!isAssignedRegister(rval.value, instr))
            dumpToMemory(storeReg, rval.value, storageLocations);
    }

}



void CodeGenerator::genAssign(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations)
{
    AssignInstruction * assignInstr = (AssignInstruction*) instr;
    ProgramValue lhs = assignInstr->lhs;
    ProgramValue rhs = assignInstr->rhs;
    
    if(lhs.vtype!=LITERAL && currentFunction->isinScope(lhs.value))
        lhs=currentFunction->getDtype(lhs.value);
    if(rhs.vtype!=LITERAL && currentFunction->isinScope(lhs.value))
        rhs=currentFunction->getDtype(rhs.value);

    Register storeRegister = getStoreReg(lhs, instr, storageLocations);
    
    if(lhs.vtype != ARRAY)
    {
        Register loadRegister = getLoadReg(rhs, instr, 1, storageLocations);
        
        if (storeRegister.getRegisterClass() == F && loadRegister.getRegisterClass()==F)
            write2Op("mov.s", storeRegister, loadRegister);
        else if(storeRegister.getRegisterClass() == F && loadRegister.getRegisterClass()!=F)
        {
            write2Op("mtc1", loadRegister, storeRegister);
            write2Op("cvt.s.w", storeRegister, storeRegister);
        }

        else
            write2Op("move", storeRegister, loadRegister);


        if(!isAssignedRegister(lhs.value, instr))
            dumpToMemory(storeRegister, lhs.value, storageLocations);
    }
    else
    {
        MemoryLocation rhsAddr = storageLocations->at(rhs.value);
        MemoryLocation lhsAddr = storageLocations->at(lhs.value);
        for(int i=0; i<rhs.size; i++)
        {
            write2Op("lw", Register(T,0), rhsAddr);
            write2Op("sw", Register(T,0), lhsAddr);
            rhsAddr.offset-=4;
            lhsAddr.offset-=4;
        }
    }


}



void CodeGenerator::genBranch(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations)
{
    BranchInstruction * branchInstr = (BranchInstruction*) instr;
    ProgramValue lhs = branchInstr->lval;
    ProgramValue rhs = branchInstr->rval;
    
    Register lhsRegister = getLoadReg(lhs, instr, 1, storageLocations);
    Register rhsRegister = getLoadReg(rhs, instr, 2, storageLocations);
    InstOpType branchType = instr->getInstOpType();
    std::string branch;
    
    switch(branchType)
    {
        case BREQ : branch = "breq"; break;
        case BRGEQ : branch = "brgeq"; break;
        case BRGT : branch = "brgt"; break;
        case BRLEQ : branch = "brleq"; break;
        case BRLT : branch = "brlt"; break;
        case BRNEQ : branch = "brneq"; break;
        default : assert(false);
    }
    
    if(lhsRegister.getRegisterClass() == F)
        assert(rhsRegister.getRegisterClass() == F);
    if(rhsRegister.getRegisterClass() == F)
        assert(lhsRegister.getRegisterClass() == F);

    if(lhsRegister.getRegisterClass()==F)
    {
        if(branchType==BREQ)
            write2Op("c.eq.s", lhsRegister, rhsRegister);
        else if(branchType==BRNEQ)
            write2Op("c.ne.s", lhsRegister, rhsRegister);
        else if(branchType==BRLT)
            write2Op("c.lt.s", lhsRegister, rhsRegister);
        else if(branchType==BRGEQ)
            write2Op("c.ge.s", lhsRegister, rhsRegister);
        else if(branchType==BRGT)
            write2Op("c.gt.s", lhsRegister, rhsRegister);
        else if(branchType==BRLEQ)
            write2Op("c.le.s", lhsRegister, rhsRegister);
        write1Op("bc1t", branchInstr->label);
    }
    else
    {
        if(branchType==BREQ)
        {
            write3Op("beq", lhsRegister, rhsRegister, branchInstr->label);
        }
        else if(branchType==BRNEQ)
        {
            write3Op("bne", lhsRegister, rhsRegister, branchInstr->label);
        }
        else
        {
            if(branchType==BRLT || branchType==BRGEQ)
            {
                write3Op("slt", Register(T,0), lhsRegister, rhsRegister);
            }
            else
            {
                write3Op("slt", Register(T,0), rhsRegister, lhsRegister);
            }
            if(branchType==BRLT || branchType==BRGT)
            {
                write3Op("bne", Register(T,0), "$0", branchInstr->label);
            }
            else
            {
                write3Op("beq", Register(T,0), "$0", branchInstr->label);
            }
        }
    }

}


void CodeGenerator::genGoto(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations)
{
    GotoInstruction * gotoInstr = (GotoInstruction*) instr;
    write1Op("j", gotoInstr->label);
}

void CodeGenerator::genLabel(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations)
{
    LabelInstruction * labelInstr = (LabelInstruction*) instr;
    writeLabel(labelInstr->label);
}


void CodeGenerator::genReturn(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations)
{
    ReturnInstruction * labelInstr = (ReturnInstruction*) instr;
    ProgramValue rval = labelInstr ->returnVal;
    
    if(rval.vtype!=EMPTY)
    {
        Register tmpRegister = getLoadReg(rval, instr, 1, storageLocations);
        if(tmpRegister.getRegisterClass()==F)
            write2Op("mfc1", Register(V, 0), tmpRegister);
        else
            write2Op("move", Register(V, 0), tmpRegister);
    }
    write3Op("addiu", Register(SP), Register(SP), currentStackSize);
    write1Op("jr", Register(RA));
}


void CodeGenerator::genArrayAccess(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations)
{
    ArrayInstruction* arrInstr = (ArrayInstruction*) instr;

    ProgramValue ndx = arrInstr->index;
    ProgramValue arrName = arrInstr->arrayName;
    ProgramValue val = arrInstr->value;
    
    
    // compute offset
    //assert(ndx.vtype==LITERAL);
    
    
    Register offsetRegister(T,1);
    if(ndx.vtype==LITERAL)
        write2Op("li", Register(T,1), ndx.value);
    else if (ndx.vtype==VAR)
    {
        offsetRegister=getLoadReg(ndx, instr, 1, storageLocations);
    }

    write2Op("li", Register(T,2), "4");
    write3Op("mul", offsetRegister, offsetRegister, Register(T,2));

    // relative to SP
    MemoryLocation addr = storageLocations->at(arrName.value);

    // load array offset from stack pointer into temp
    write2Op("li", Register(T,2), addr.offset);
    
    // add stack pointer
    write3Op("add", Register(T,2), Register(T,2), Register(SP));

    // add to offset register
    write3Op("sub", offsetRegister, Register(T,2), offsetRegister);
    MemoryLocation elementAddr = MemoryLocation(0, offsetRegister);

    if(instr->getInstOpType() == ARRAY_LOAD)
    {
        Register valReg = getStoreReg(val, instr, storageLocations);
        write2Op("lw", valReg, elementAddr);
        dumpToMemory(valReg, val.value, storageLocations);
    }
    else
    {
        Register valReg = getLoadReg(val, instr, 2, storageLocations);
        write2Op("sw", valReg, elementAddr);
    }
}



void CodeGenerator::genArrayAssign(Instruction* instr, std::map<std::string, MemoryLocation>* storageLocations)
{
    ArrayInstruction* arrInstr = (ArrayInstruction*) instr;

    std::string arr = (arrInstr->arrayName).value;
    Function* currentFunc = getCurrentFunction();
    ProgramValue arrName = currentFunc->getDtype(arr);
    
    
    MemoryLocation addr = storageLocations->at(arrName.value);
    assert(arrName.vtype==ARRAY);

    ProgramValue val = arrInstr->value;
    
    Register valReg = getLoadReg(val, instr, 1, storageLocations);
    for(int i=0; i<arrName.size; i++)
    {
        write2Op("sw", valReg, addr);
        addr.offset-=4;
    }

    
    
    //write2Op("sw", valReg, addr);


}