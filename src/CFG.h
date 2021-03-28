#include "Program.h"


class CFG{

    Program * program;

    public:
        CFG(Program * program_);

    // TODO: build CFG using program pointer
    // TODO: register allocation - a "use" is a variable in an Instruction (see Instruction.h)
    //       for each variable that is assigned a register, update
    //       std::map<std::string, StorageLocation *> storageLocations (in Instruction class);
    //       with a correspondence between the name and the register
};

