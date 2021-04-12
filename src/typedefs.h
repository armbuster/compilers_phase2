#ifndef _SRC_TYPEDEFS_H
#define _SRC_TYPEDEFS_H

#include <unordered_map>
#include <vector>
#include <string>

// Forward declarations
class Instruction;
class Function; //used in typedefs
typedef std::vector<Instruction*> InstContainer;
typedef std::vector<Function*> FunctionContainer;
typedef std::unordered_map<std::string, Instruction*> InstByStringMap;
typedef std::unordered_map<Instruction*, Instruction*> InstByInstMap;


#endif /* _SRC_IR_ENUMS_H */