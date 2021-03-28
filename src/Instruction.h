#pragma once

#include <string>
#include <vector>
#include <map>
#include "StorageLocation.h"

enum ValType {VAR, ARRAY, LITERAL};
enum DataType {FLOAT, INT, VOID, UNKNOWN};

struct ProgramValue {
    ValType vtype;
    DataType dtype;
    std::string value;
    int size;
};


enum InstructionType {
    ASSIGN,
    ADD,
    SUB,
    MULT,
    DIV,
    AND,
    OR,
    GOTO,
    BREQ,
    BRNEQ,
    BRLT,
    BRGT,
    BRLEQ,
    BRGEQ,
    RETURN_VOID,
    RETURN_NONVOID,
    CALL,
    CALLR,
    ARRAY_STORE,
    ARRAY_LOAD,
    ARRAY_ASSIGN
};

class Instruction {

    InstructionType instruction;
    //std::map<std::string, DataType> operandTypes; // types of operands
    std::vector<ProgramValue> define; // names of operands that are defined here
    std::vector<ProgramValue> use; // names of operands that are used here
    std::vector<ProgramValue> in; // in set - UPDATED BY LIVELINESS ANALYSIS
    std::vector<ProgramValue> out; // out set - UPDATED BY LIVELINESS ANALYSIS
    std::map<std::string, StorageLocation *> storageLocations; // map from variable names to storage locations
    // UPDATED BY REGISTER ALLOCATOR
    bool leader; // whether or not this instruction is the start of a basic block

    public:
        Instruction(InstructionType instruction_, std::vector<ProgramValue> define_, std::vector<ProgramValue> use_);
        //virtual ~Instruction() = 0;
        //virtual void setOperands() = 0;
};

class BinaryInstruction : public Instruction{
    ProgramValue rhs1;
    ProgramValue rhs2;
    ProgramValue lhs;

    public:
        //~BinaryInstruction(){};
        void setOperands(ProgramValue lhs, ProgramValue rhs1, ProgramValue rhs2);
};


class AssignInstruction : public Instruction{
    ProgramValue rhs;
    ProgramValue lhs;

    public:
        
        // inherit constructor
        using Instruction::Instruction;
        void setOperands(ProgramValue lhs_, ProgramValue rhs_);
};
