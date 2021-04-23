#include "IrEnums.h"


bool operator<(const ProgramValue& a, const ProgramValue& b)
{
    return a.value < b.value;
}