#pragma once

#include <string>
#include <vector>
#include <map>
#include <deque>
#include <iostream>
#include "Register.h"

enum ValType {VAR, ARRAY, LITERAL, EMPTY};
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
    ARRAY_ASSIGN,
    LABEL
};


class Instruction {

    InstructionType instruction;
    //std::map<std::string, DataType> operandTypes; // types of operands
    std::vector<ProgramValue> define; // names of operands that are defined here
    std::vector<ProgramValue> use; // names of operands that are used here
    std::vector<ProgramValue> in; // in set - UPDATED BY LIVELINESS ANALYSIS
    std::vector<ProgramValue> out; // out set - UPDATED BY LIVELINESS ANALYSIS
    std::map<std::string, Register*>* registerAssignments; // map from variable names to storage locations


    // This should be set in the treeVisitor. 
    // The register allocator will then use it when building the CFG.
    bool isLeader; // whether or not this instruction is the start of a basic block

    public:
        Instruction(InstructionType instruction_, std::vector<ProgramValue> define_, std::vector<ProgramValue> use_);
        friend std::ostream& operator<<(std::ostream& os, const Instruction& instr);
        
        InstructionType getInstructionType();
        std::vector<ProgramValue> getDefined();
        std::vector<ProgramValue> getUse();
        bool isUsed(std::string name);
        bool isDefined(std::string name);
        
        ////// keep these
        std::map<std::string, Register*>* getRegisterAssignments();
        void setRegisterAssignment(std::string, Register*);




};

class BinaryInstruction : public Instruction{
    public:
    ////// keep these
    ProgramValue rhs1;
    ProgramValue rhs2;
    ProgramValue lhs;
    std::string instrType;

        using Instruction::Instruction;
        void setOperands(ProgramValue lhs_, ProgramValue rhs1_, ProgramValue rhs2_, InstructionType instrType);
};


class AssignInstruction : public Instruction{
    public:
    ////// keep these
    ProgramValue rhs;
    ProgramValue lhs;
        
        // inherit constructor
        using Instruction::Instruction;
        void setOperands(ProgramValue lhs_, ProgramValue rhs_);
};


class BranchInstruction : public Instruction{
    public:
    ////// keep these
    ProgramValue lval;
    ProgramValue rval;
    std::string label;
        
        // inherit constructor
        using Instruction::Instruction;
        void setOperands(std::string label, ProgramValue lval_ = {EMPTY, UNKNOWN, "", 0}, ProgramValue rval_ = {EMPTY, UNKNOWN, "", 0});
};



class GotoInstruction : public Instruction{
    public:
    ////// keep these
    std::string label;
        
        // inherit constructor
        using Instruction::Instruction;
        void setOperands(std::string label);
};


class ReturnInstruction : public Instruction{
    public:////// keep these
    ProgramValue returnVal;
        
        // inherit constructor
        using Instruction::Instruction;
        void setOperands(ProgramValue returnVal_ = {EMPTY, UNKNOWN, "", 0});
};


class CallInstruction : public Instruction{
    public:////// keep these
    std::deque<ProgramValue> args;
    std::string funcname;
    ProgramValue returnVal;
        
        // inherit constructor
        using Instruction::Instruction;
        void setOperands(std::string funcname_, std::deque<ProgramValue> args_, ProgramValue rval = {EMPTY, UNKNOWN, "", 0});
};



class ArrayInstruction : public Instruction{
    
    public:////// keep these
    ProgramValue arrayName;
    ProgramValue index;
    ProgramValue value;
        
        // inherit constructor
        using Instruction::Instruction;
        void setOperands(ProgramValue arrayName_, ProgramValue value_, ProgramValue index_ = {EMPTY, UNKNOWN, "", 0});
};


class LabelInstruction : public Instruction{
    
    public:////// keep these
    std::string label;
        
        // inherit constructor
        using Instruction::Instruction;
        void setOperands(std::string label_);
};