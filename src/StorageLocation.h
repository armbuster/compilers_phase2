#pragma once

#include <string>



enum StorageType {REGISTER, MEMORY};

class StorageLocation {
    StorageType stype;
    public:
        StorageType getStorageType();
        virtual std::string getStringValue() = 0;
};

