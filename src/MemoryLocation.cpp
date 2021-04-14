
#include "MemoryLocation.h"


MemoryLocation::MemoryLocation(int offset_, Register r_) : r(r_)
{
    offset = offset_;
}



std::ostream& operator<<(std::ostream& out, const MemoryLocation& r)
{
    out << r.offset << "(" << r.r << ")";
    return out;
}
