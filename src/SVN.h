#ifndef _SRC_SVN_H
#define _SRC_SVN_H

#include "IrEnums.h"
#include "typedefs.h"
#include "CFG.h"


namespace IR {


class SVN
{
 public:
 	SVN(CFG* cfg);
 	~SVN(){};

 private:
 	CFG* cfg_;
 	ExtendedBasicBlocks* extendedBasicBlocks_ = new ExtendedBasicBlocks();

 	void getEbbsFromCfg();
 	BasicBlockContainer* getNextEbb(BasicBlock* parent);
 	void visitSuccessors(BasicBlock* parent, BasicBlockContainer* ebb);


};

}  // namespace ir


#endif /* _SRC_SVN_H */