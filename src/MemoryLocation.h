
#pragma once

#include <string>
#include "StorageLocation.h"



class MemoryLocation : public StorageLocation {

    unsigned int offset;
    public:
        MemoryLocation(unsigned int offset);
        
        // returns "$sp + offset"
        std::string getStringValue();

};