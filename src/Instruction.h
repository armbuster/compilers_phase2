#pragma once

#include <string>
#include <vector>
#include <map>
#include <deque>
#include <iostream>
#include <typeinfo>
#include <stdio.h>

#include "StorageLocation.h"

enum ValType {VAR, ARRAY, LITERAL, EMPTY};
enum DataType {FLOAT, INT, VOID, UNKNOWN};

struct ProgramValue {
    ValType vtype;
    DataType dtype;
    std::string value;
    int size;
};

enum InstOpType 
{
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

namespace IR {
enum InstType
{
    BINARY,
    ASSIGN,
    BRANCH,
    RETURN,
    CALL,
    ARRAY
};
}; //end namespace IR


class Instruction {

    protected:
        InstOpType instOpType;  //denotes the instruction operation type
        //std::map<std::string, DataType> operandTypes; // types of operands
        std::vector<ProgramValue> define; // names of operands that are defined here
        std::vector<ProgramValue> use; // names of operands that are used here
        std::vector<ProgramValue> in; // in set - UPDATED BY LIVELINESS ANALYSIS
        std::vector<ProgramValue> out; // out set - UPDATED BY LIVELINESS ANALYSIS
        std::map<std::string, StorageLocation *> storageLocations; // map from variable names to storage locations
        // This should be set in the treeVisitor. 
        // The register allocator will then use it when building the CFG.
        bool leader; // whether or not this instruction is the start of a basic block

    public:
        Instruction(InstOpType instOpType_, std::vector<ProgramValue> define_, std::vector<ProgramValue> use_);
        friend std::ostream& operator<<(std::ostream& os, const Instruction& instr);
        void markAsLeader() { leader = true; };
        bool isLeader() { return leader; };

        //pure virtual
        virtual bool is(IR::InstType instType) = 0;
        virtual void print() = 0;

        //virtual ~Instruction() = 0;
        //virtual void setOperands() = 0;
};


class BinaryInstruction : public Instruction {
    ProgramValue rhs1;
    ProgramValue rhs2;
    ProgramValue lhs;

    public:
        using Instruction::Instruction; // inherit constructor
        bool is(IR::InstType instType);
        void print();
        void setOperands(ProgramValue lhs_, ProgramValue rhs1_, ProgramValue rhs2_);
};


class AssignInstruction : public Instruction {
    ProgramValue rhs;
    ProgramValue lhs;

    public:
        using Instruction::Instruction;
        bool is(IR::InstType instType);
        void print();
        void setOperands(ProgramValue lhs_, ProgramValue rhs_);
};


class BranchInstruction : public Instruction {
    ProgramValue lval;
    ProgramValue rval;
    std::string label;

    public:
        using Instruction::Instruction;
        bool is(IR::InstType instType);
        void print();
        void setOperands(std::string label, ProgramValue lval_ = {EMPTY, UNKNOWN, "", 0}, ProgramValue rval_ = {EMPTY, UNKNOWN, "", 0});
};


class ReturnInstruction : public Instruction {
    ProgramValue returnVal;

    public:
        using Instruction::Instruction;
        bool is(IR::InstType instType);
        void print();
        void setOperands(ProgramValue returnVal_ = {EMPTY, UNKNOWN, "", 0});
};


class CallInstruction : public Instruction {
    std::deque<ProgramValue> args;
    std::string funcname;
    ProgramValue returnVal;

    public:
        using Instruction::Instruction;
        bool is(IR::InstType instType);
        void print();
        void setOperands(std::string funcname_, std::deque<ProgramValue> args_, ProgramValue rval = {EMPTY, UNKNOWN, "", 0});
};



class ArrayInstruction : public Instruction {
    ProgramValue arrayName;
    ProgramValue index;
    ProgramValue value;

    public:
        using Instruction::Instruction;
        bool is(IR::InstType instType);
        void print();
        void setOperands(ProgramValue arrayName_, ProgramValue value_, ProgramValue index_ = {EMPTY, UNKNOWN, "", 0});
};


