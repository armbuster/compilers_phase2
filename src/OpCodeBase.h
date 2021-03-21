//not used... save for later
#ifndef _SRC_OP_CODE_H
#define _SRC_OP_CODE_H

#include <iostream>
#include <cstdint>

#ifndef FAIL_OP
#define FAIL_OP "DNE"
#endif

namespace ir {

class OpCodeBase {

 public:
	enum class OpCode: int
	{
	    ADD = 0,
	    SUB = 1,
	    MULTI = 2,
	    DIV = 3
	};

	static std::string getOpName(OpCode op);

	friend std::ostream& operator<<(std::ostream& os, OpCode op)
	{
	    if(getOpName(op)==FAIL_OP)
		{
	        os.setstate(std::ios_base::failbit);
	    }
	    else
	    {
	    	os << getOpName(op);
	    }
	    return os;
	}
};

} // namespace ir

#endif /* _SRC_OP_CODE_H */