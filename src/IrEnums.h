#ifndef _SRC_IR_ENUMS_H
#define _SRC_IR_ENUMS_H

#include <iostream>
#include <cstdint>

#ifndef FAIL_BIN_OP
#define FAIL_BIN_OP "DNE"
#endif

//TODO: clean this code up so that it can reuse the operator 
//      overload (refer to OpCodeBase.h as a starting point)

namespace ir {
namespace OpCode {

	// ********************************************************
	enum BinOp
	{
		ADD,
		SUB,
		MULTI,
		DIV
	};

	std::string getBinOpName(BinOp op)
	{
		switch(op)
	    {
	        case ADD   	: return "ADD";    break;
	        case SUB	: return "SUB"; break;
	        case MULTI 	: return "MULTI";  break;
	        case DIV  	: return "DIV";   break;
	        default    	: return FAIL_BIN_OP;
	    }
	}

	std::ostream& operator<<(std::ostream& os, BinOp op)
	{
	    if(getBinOpName(op)==FAIL_BIN_OP)
		{
	        os.setstate(std::ios_base::failbit);
	    }
	    else
	    {
	    	os << getBinOpName(op);
	    }
	    return os;
	}

	// ********************************************************
	enum MemOp
	{
		LOAD,
		STORE
	};

	std::string getMemOpName(MemOp op)
	{
		switch(op)
	    {
	        case LOAD   	: return "LOAD";    break;
	        case STORE		: return "STORE"; break;
	        default    	: return FAIL_BIN_OP;
	    }
	}

	std::ostream& operator<<(std::ostream& os, MemOp op)
	{
	    if(getMemOpName(op)==FAIL_BIN_OP)
		{
	        os.setstate(std::ios_base::failbit);
	    }
	    else
	    {
	    	os << getMemOpName(op);
	    }
	    return os;
	}

	// ********************************************************
	enum TermOp
	{
		RET,
		BR
	};

	std::string getTermOpName(TermOp op)
	{
		switch(op)
	    {
	        case RET   	: return "RET";    break;
	        case BR		: return "BR"; break;
	        default    	: return FAIL_BIN_OP;
	    }
	}

	std::ostream& operator<<(std::ostream& os, TermOp op)
	{
	    if(getTermOpName(op)==FAIL_BIN_OP)
		{
	        os.setstate(std::ios_base::failbit);
	    }
	    else
	    {
	    	os << getTermOpName(op);
	    }
	    return os;
	}


} // namespace OpCode
} // namespace ir

#endif /* _SRC_IR_ENUMS_H */