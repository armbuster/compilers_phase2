#pragma once

#include "StorageLocation.h"
#include <string>

enum RegisterClass {A, T, S, V};
// A - argument register
// T - temporary register
// S - saved register
// V - return value registers

// TODO: Register allocation will need to create map that looks something like
// map<RegisterClass , vector<unsigned int> > to track which are available to be allocated

class Register : public StorageLocation {
    
    RegisterClass R;
    unsigned int ind;
    
    public:

        // check that RegisterClass <-> registerIndex is valid
        // i.e. Register(A, 5) or Register(T, 12) would be illegal
        // because mips only has 4 argument registers ($a0-$a4)
        // and 9 temporary registers ($t0-$t9)
        Register(RegisterClass r, unsigned int registerIndex);
        std::string getStringValue();
};