#pragma once

#include <string>
#include <vector>
#include <map>
#include <deque>
#include <iostream>
#include <typeinfo>
#include <stdio.h>

#include "IrEnums.h"
#include "typedefs.h"
#include "BasicBlock.h"
#include "StorageLocation.h"
#include "Register.h"


class Instruction {

    protected:
        InstOpType instOpType;  //denotes the instruction operation type
        //std::map<std::string, DataType> operandTypes; // types of operands
        std::vector<ProgramValue> define; // names of operands that are defined here
        std::vector<ProgramValue> use; // names of operands that are used here
        std::vector<ProgramValue> in; // in set - UPDATED BY LIVELINESS ANALYSIS
        std::vector<ProgramValue> out; // out set - UPDATED BY LIVELINESS ANALYSIS
        std::map<std::string, StorageLocation *> storageLocations; // map from variable names to storage locations
        bool leader; // whether or not this instruction is the start of a basic block
        bool branchTarget;
        IR::BasicBlock* parent_;
        InstContainer* successors_ = new InstContainer();
        InstContainer* predecessors_ = new InstContainer();
        unsigned int id_;
        std::map<std::string, Register*>* registerAssignments; // map from variable names to storage locations

    public:
        Instruction(InstOpType instOpType_, std::vector<ProgramValue> define_, std::vector<ProgramValue> use_);
        friend std::ostream& operator<<(std::ostream& os, const Instruction& instr);
        void addSuccessor(Instruction* successor);
        void addPredecessor(Instruction* predecessor);
        void printSuccessors();
        void printPredecessors();
        void printParent();
        BasicBlockContainer* getSuccessorsParents();
        std::map<std::string, Register*>* getRegisterAssignments();
        void setRegisterAssignment(std::string, Register*);

        void setId(unsigned int id) { id_ = id; }
        unsigned int getId() { return id_; }
        void markAsLeader() { leader = true; };
        bool isLeader() { return leader; };
        void isBranchTarget(bool brTarget) { branchTarget = brTarget; }
        bool isBranchTarget() { return branchTarget; }
        void setParent(IR::BasicBlock* parent) { parent_ = parent; }
        IR::BasicBlock* getParent() { return parent_; }

        //pure virtual
        virtual bool is(IR::InstType instType) = 0;
        virtual void print() = 0;
};


class BinaryInstruction : public Instruction {
    ProgramValue rhs1;
    ProgramValue rhs2;
    ProgramValue lhs;
    std::string instrType;

    public:
        using Instruction::Instruction; // inherit constructor
        bool is(IR::InstType instType);
        void print();
        void setOperands(ProgramValue lhs_, ProgramValue rhs1_, ProgramValue rhs2_, InstructionType instrType);
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
        
        // inherit constructor
        using Instruction::Instruction;
        void setOperands(std::string label, ProgramValue lval_ = {EMPTY, UNKNOWN, "", 0}, ProgramValue rval_ = {EMPTY, UNKNOWN, "", 0});
};


class GotoInstruction : public Instruction{
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


class LabelInstruction : public Instruction{
    
    public:////// keep these
    std::string label;

        using Instruction::Instruction;
        void setOperands(std::string label_);
};