#pragma once


#include "MemoryLocation.h"
#include "Function.h"
#include "assert.h"
#include <map>
#include <string>



class CodeGenerator;

class FunctionWriter {

    CodeGenerator* codeGen;
    std::map<std::string, MemoryLocation*> memoryMap; // mapping from program names to memory locations
    std::vector<std::string> mipsInstructions; // MIPS instructions in sequential order
    Function * func;

    // move stack pointer
    // setup data section
    // assign memory addresses to variables
    void stackSetup();
    
    // iterates over instructions in func
    // and translates to MIPS, adds to end of mipsInstructions
    void translateIr();

    public:
        FunctionWriter(CodeGenerator * codeGen_, Function * func_);
        
        
        // allow other functions to look up memory locations relative to
        // $sp of main (which is set as $fp), this operation is only valid for main
        MemoryLocation * memLookup(std::string);
        
        void writeLabel(std::string label);
        void writeInstruction(std::string instruction);
        
        
        
        
        
        // handle main module first
        // calculate how much $sp needs to move down
        // copy $sp -> $fp (main only)
        // assign each variable an offset from $sp
        // handle statements 1 by 1
        // before function call spill all values to their data slot (main only)
        //
        //
        //
        //
        // abstractions:
        //  void setupStack()
        //    
        //
        //

};