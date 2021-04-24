#ifndef _SRC_TYPEDEFS_H
#define _SRC_TYPEDEFS_H

#include <unordered_map>
#include <vector>
#include <string>

// Forward declarations
class Instruction;
class Function;
namespace IR
{
	class BasicBlock;
}

// typedefs
typedef std::vector<Instruction*> InstContainer;
typedef std::vector<Function*> FunctionContainer;
typedef std::unordered_map<std::string, Instruction*> InstByStringMap;
typedef std::unordered_map<Instruction*, Instruction*> InstByInstMap;
typedef std::vector<IR::BasicBlock*> BasicBlockContainer;
typedef std::vector<BasicBlockContainer*> ExtendedBasicBlocks;





#endif /* _SRC_TYPEDEFS_H */