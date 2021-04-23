#pragma once

#include "assert.h"
#include <string>
#include <map>
#include <iostream>

enum RegisterClass {A, T, S, V, F, SP, RA, FP};
// A - argument register
// T - temporary register
// S - saved register
// V - return value registers
// F - floating point register
// SP - stack pointer
// RA - return address
// FP - frame pointer

// TODO: Register allocation will need to create map that looks something like
// map<RegisterClass , vector<unsigned int> > to track which are available to be allocated




class Register {
    
    RegisterClass R;
    int ind;
    
    public:

        // check that RegisterClass <-> registerIndex is valid
        // i.e. Register(A, 5) or Register(T, 12) would be illegal
        // because mips only has 4 argument registers ($a0-$a4)
        // and 9 temporary registers ($t0-$t9)
        friend std::ostream& operator<<(std::ostream& out, const Register& r);
        friend bool operator==(const Register& lhs, const Register& rhs);
        friend bool operator!=(const Register& lhs, const Register& rhs);
        Register(RegisterClass r = SP, int registerIndex=-1);
        Register(const Register &obj);
        // Register(Register &&obj);
        //Register(const Register& r);
        RegisterClass getRegisterClass(){ return R; };
        int getRegisterIndex() { return ind; }
};
