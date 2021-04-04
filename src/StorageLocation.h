#include <string>
#include "Register.h"

enum StorageType {REGISTER, MEMORY};

class StorageLocation {
    StorageType stype;
    public:
        StorageType getStorageType();
        virtual std::string getStringValue() = 0;
};

