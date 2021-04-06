
#include "Register.h"


Register::Register(RegisterClass r, int registerIndex)
{

    // check that registerIndex / registerType combo is valid
    if(registerIndex==-1)
        assert(r == SP || r == RA || r == FP);
    else
    {
        if(r == A)
            assert(registerIndex >= 0 && registerIndex < 4);
        else if(r == T)
            assert(registerIndex >= 0 && registerIndex < 10);
        else if(r == S)
            assert(registerIndex >= 0 && registerIndex < 8);
        else if(r == V)
            assert(registerIndex >= 0 && registerIndex < 2);
    }
    R = r;
    ind = registerIndex;
}

// Register::Register(const Register& r)
// {

// }



std::map<RegisterClass, std::string> m = {
    {A,"$a"},
    {T,"$t"},
    {S,"$s"},
    {V,"$v"},
    {SP,"$sp"},
    {RA,"$ra"},
    {FP,"$fp"}
};

std::ostream& operator<<(std::ostream& out, const Register& r)
{
    out << m[r.R];
    if (r.ind != -1)
        out << r.ind;
    return out;
}
