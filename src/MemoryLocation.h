
#pragma once

#include "Register.h"
#include <string>



struct MemoryLocation {

    int offset;
    Register r;
    friend std::ostream& operator<<(std::ostream& out, const MemoryLocation& r);
    MemoryLocation(int offset_, Register r_);
};