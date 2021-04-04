#include "Module.h"
#include <stack>


class CodeGenerator{
    Module * mod;
    public:
        CodeGenerator(Module * m);

        // handle main module first
        // calculate how much $sp needs to move down
        // copy $sp -> $fp (main only)
        // assign each variable an offset from $sp
        // handle statements 1 by 1
        // before function call spill all values to their data slot (main only)
        


        // abstractions:
        //  void setupStack()
        //  
        //
        //


};