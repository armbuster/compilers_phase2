#ifndef _SRC_IR_ENUMS_H
#define _SRC_IR_ENUMS_H


#include <string>

enum ValType {VAR, ARRAY, LITERAL, EMPTY};
enum DataType {FLOAT, INT, VOID, UNKNOWN};
enum RegisterAllocation {NAIVE, INTRA_BLOCK, BRIGGS};


struct ProgramValue {
    ValType vtype;
    DataType dtype;
    std::string value;
    int size;
};

bool operator<(const ProgramValue& a, const ProgramValue& b);

enum InstOpType 
{
    ASSIGN,
    ADD,
    SUB,
    MULT,
    DIV,
    AND,
    OR,
    GOTO,
    BREQ,
    BRNEQ,
    BRLT,
    BRGT,
    BRLEQ,
    BRGEQ,
    RETURN_VOID,
    RETURN_NONVOID,
    CALL,
    CALLR,
    ARRAY_STORE,
    ARRAY_LOAD,
    ARRAY_ASSIGN,
    LABEL
};

namespace IR {
    // Forward declaration
    // class BasicBlock;

    enum InstType
    {
        BINARY,
        ASSIGN,
        BRANCH,
        RETURN,
        CALL,
        ARRAY,
        LABEL
    };
}; //end namespace IR


#endif /* _SRC_IR_ENUMS_H */