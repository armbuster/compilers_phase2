#include "irVisitor.h"


irVisitor::irVisitor()
{
    mod = new Module();
}

Module* irVisitor::getModule()
{
    return mod;
}

void irVisitor::updateDtypeMap(std::map<std::string, ProgramValue> * dtypes)
{
    dtypeMap.insert(dtypes->begin(), dtypes->end());
}

antlrcpp::Any irVisitor::visitFunction(tiger::tigerIrParser::FunctionContext *ctx){

    // get info about the function
    std::deque<std::string> params = visit(ctx->paramList());
    DataType dtype = visit(ctx->typeId());
    std::string funcname = ctx->ID(0)->getText();
    std::deque<ProgramValue> intList = visit(ctx->varList(0));
    std::deque<ProgramValue> floatList = visit(ctx->varList(1));
    
    // create function object
    currentFunction = new Function(funcname, dtype, floatList, intList, params);
    updateDtypeMap(currentFunction->getDtypeMap());
    visit(ctx->funcBody());
    mod->addFunction(currentFunction);
    return 0;

}

antlrcpp::Any irVisitor::visitParamListNonEmpty(tiger::tigerIrParser::ParamListNonEmptyContext *ctx){
    std::deque<std::string> paramList = visit(ctx->paramListTail());
    std::string param = visit(ctx->param());
    paramList.push_front(param);
    return paramList;
}

antlrcpp::Any irVisitor::visitParamListEmpty(tiger::tigerIrParser::ParamListEmptyContext *ctx){
    std::deque<std::string> paramList;
    return paramList;
}

antlrcpp::Any irVisitor::visitParamListTailNonEmpty(tiger::tigerIrParser::ParamListTailNonEmptyContext *ctx){
    std::deque<std::string> paramList = visit(ctx ->paramListTail());
    std::string param = visit(ctx->param());
    paramList.push_front(param);
    return paramList;
}

antlrcpp::Any irVisitor::visitParamListTailEmpty(tiger::tigerIrParser::ParamListTailEmptyContext *ctx){
    std::deque<std::string> paramList;
    return paramList;
}

antlrcpp::Any irVisitor::visitParam(tiger::tigerIrParser::ParamContext *ctx){
    std::string id = ctx->ID()->getText();
    return id;
}

// antlrcpp::Any irVisitor::visitTypeId(tiger::tigerIrParser::TypeIdContext *ctx){}

antlrcpp::Any irVisitor::visitVarListExpand(tiger::tigerIrParser::VarListExpandContext *ctx){
    std::deque<ProgramValue> varList = visit(ctx->varList());
    int size = visit(ctx->arrayDeref());
    ValType vtype;
    if(size == 0)
        vtype=VAR;
    else if(size > 0)
        vtype=ARRAY;
    else
        assert(false);

    ProgramValue pval = {vtype, UNKNOWN, ctx->ID()->getText(), size};
    varList.push_front(pval);
    return varList;
}

antlrcpp::Any irVisitor::visitVarListSingle(tiger::tigerIrParser::VarListSingleContext *ctx){
    std::deque<ProgramValue> varList;
    int size = visit(ctx->arrayDeref());
    ValType vtype;
    if(size == 0)
        vtype=VAR;
    else if(size > 0)
        vtype=ARRAY;

    ProgramValue pval = {vtype, UNKNOWN, ctx->ID()->getText(), size};
    varList.push_front(pval);
    return varList;
}

antlrcpp::Any irVisitor::visitVarListEmpty(tiger::tigerIrParser::VarListEmptyContext *ctx){
    std::deque<ProgramValue> dq;
    return dq;
}

antlrcpp::Any irVisitor::visitTypeIdInt(tiger::tigerIrParser::TypeIdIntContext *ctx){
    return INT;
    
}

antlrcpp::Any irVisitor::visitTypeIdFloat(tiger::tigerIrParser::TypeIdFloatContext *ctx){
    return FLOAT;
}

antlrcpp::Any irVisitor::visitTypeIdVoid(tiger::tigerIrParser::TypeIdVoidContext *ctx){
    return VOID;
}

antlrcpp::Any irVisitor::visitValId(tiger::tigerIrParser::ValIdContext *ctx){
    DataType dtype = dtypeMap.at(ctx->ID()->getText()).dtype;
    ProgramValue val = {VAR, dtype, ctx->ID()->getText(), 0};
    return val;
}

antlrcpp::Any irVisitor::visitValIntLit(tiger::tigerIrParser::ValIntLitContext *ctx){
    ProgramValue val = {LITERAL, INT, ctx->INTLIT()->getText(), 0};
    return val;
}

antlrcpp::Any irVisitor::visitValFloatLit(tiger::tigerIrParser::ValFloatLitContext *ctx){
    ProgramValue val = {LITERAL, FLOAT, ctx->FLOATLIT()->getText(), 0};
    return val;
}

antlrcpp::Any irVisitor::visitArrayDerefNonempty(tiger::tigerIrParser::ArrayDerefNonemptyContext *ctx){
    return std::stoi(ctx->INTLIT()->getText());
}

antlrcpp::Any irVisitor::visitArrayDerefEmpty(tiger::tigerIrParser::ArrayDerefEmptyContext *ctx){
    return 0;
}

antlrcpp::Any irVisitor::visitExprListContinue(tiger::tigerIrParser::ExprListContinueContext *ctx){
    std::deque<ProgramValue> dq = visit(ctx->exprList());
    dq.push_front(visit(ctx->val()));
    return dq;
}

antlrcpp::Any irVisitor::visitExprListSingle(tiger::tigerIrParser::ExprListSingleContext *ctx){
    std::deque<ProgramValue> dq;
    dq.push_back(visit(ctx->val()));
    return dq;
}

antlrcpp::Any irVisitor::visitExprListEmpty(tiger::tigerIrParser::ExprListEmptyContext *ctx){
    std::deque<ProgramValue> dq;
    return dq;
}

antlrcpp::Any irVisitor::visitAssign(tiger::tigerIrParser::AssignContext *ctx){
    std::vector<ProgramValue> lhs; 
    lhs.push_back(visit(ctx->val(0)));
    std::vector<ProgramValue> rhs;
    rhs.push_back(visit(ctx->val(1)));
    AssignInstruction* inst = new AssignInstruction(ASSIGN, lhs, rhs);
    inst->setOperands(lhs[0], rhs[0]);
    currentFunction->addInstruction(inst);

    updateInstId(inst);
    isInstBrTarget(inst);
    updatePrevInst(inst);
    checkIfFollowingLabel(inst);

    return 0;
}

antlrcpp::Any irVisitor::visitAdd(tiger::tigerIrParser::AddContext *ctx)
{
    return visitBinInst<tiger::tigerIrParser::AddContext>(ctx, ADD);
}

antlrcpp::Any irVisitor::visitSub(tiger::tigerIrParser::SubContext *ctx)
{
    return visitBinInst<tiger::tigerIrParser::SubContext>(ctx, SUB);
}

antlrcpp::Any irVisitor::visitMult(tiger::tigerIrParser::MultContext *ctx)
{
    return visitBinInst<tiger::tigerIrParser::MultContext>(ctx, MULT);
}

antlrcpp::Any irVisitor::visitDiv(tiger::tigerIrParser::DivContext *ctx)
{
    return visitBinInst<tiger::tigerIrParser::DivContext>(ctx, DIV);
}

antlrcpp::Any irVisitor::visitAnd_op(tiger::tigerIrParser::And_opContext *ctx)
{
    return visitBinInst<tiger::tigerIrParser::And_opContext>(ctx, AND);
}

antlrcpp::Any irVisitor::visitOr_op(tiger::tigerIrParser::Or_opContext *ctx)
{
    return visitBinInst<tiger::tigerIrParser::Or_opContext>(ctx, OR);
}

antlrcpp::Any irVisitor::visitGoto_op(tiger::tigerIrParser::Goto_opContext *ctx)
{
    std::vector<ProgramValue> use;
    std::vector<ProgramValue> define; 
    GotoInstruction* instr = new GotoInstruction(GOTO, define, use);
    instr->setOperands(ctx->ID()->getText());
    currentFunction->addInstruction(instr);
    return 0;
}

antlrcpp::Any irVisitor::visitBreq(tiger::tigerIrParser::BreqContext *ctx)
{
    return visitBrInst<tiger::tigerIrParser::BreqContext>(ctx, BREQ);
}

antlrcpp::Any irVisitor::visitBrneq(tiger::tigerIrParser::BrneqContext *ctx)
{
    return visitBrInst<tiger::tigerIrParser::BrneqContext>(ctx, BRNEQ);
}

antlrcpp::Any irVisitor::visitBrlt(tiger::tigerIrParser::BrltContext *ctx)
{
    return visitBrInst<tiger::tigerIrParser::BrltContext>(ctx, BRLT);
}

antlrcpp::Any irVisitor::visitBrgt(tiger::tigerIrParser::BrgtContext *ctx)
{
    return visitBrInst<tiger::tigerIrParser::BrgtContext>(ctx, BRGT);
}

antlrcpp::Any irVisitor::visitBrleq(tiger::tigerIrParser::BrleqContext *ctx)
{
    return visitBrInst<tiger::tigerIrParser::BrleqContext>(ctx, BRLEQ);
}

antlrcpp::Any irVisitor::visitBrgeq(tiger::tigerIrParser::BrgeqContext *ctx)
{
    return visitBrInst<tiger::tigerIrParser::BrgeqContext>(ctx, BRGEQ);
}

antlrcpp::Any irVisitor::visitReturn_void(tiger::tigerIrParser::Return_voidContext *ctx){
    std::vector<ProgramValue> use;
    std::vector<ProgramValue> define; 
    ReturnInstruction* inst = new ReturnInstruction(RETURN_VOID, define, use);
    inst->setOperands();
    currentFunction->addInstruction(inst);

    updateInstId(inst);
    isInstBrTarget(inst);
    updatePrevInst(inst);
    checkIfFollowingLabel(inst);

    return 0;
}

antlrcpp::Any irVisitor::visitReturn_nonvoid(tiger::tigerIrParser::Return_nonvoidContext *ctx){
    std::vector<ProgramValue> use;
    std::vector<ProgramValue> define;
    use.push_back(visit(ctx->val()));
    ReturnInstruction * inst = new ReturnInstruction(RETURN_NONVOID, define, use);
    inst->setOperands(use[0]);
    currentFunction->addInstruction(inst);

    updateInstId(inst);
    isInstBrTarget(inst);
    updatePrevInst(inst);
    checkIfFollowingLabel(inst);

    return 0;
}

antlrcpp::Any irVisitor::visitCall(tiger::tigerIrParser::CallContext *ctx){
    std::deque<ProgramValue> queue = visit(ctx->exprList());
    std::string funcname = ctx->ID()->getText();
    std::vector<ProgramValue> define;
    std::vector<ProgramValue> use;
    
    for(ProgramValue p : queue)
    {
        use.push_back(p);
    }
    CallInstruction* inst = new CallInstruction(CALL, define, use);
    inst->setOperands(funcname, queue);
    currentFunction->addInstruction(inst);

    updateInstId(inst);
    isInstBrTarget(inst);
    updatePrevInst(inst);
    checkIfFollowingLabel(inst);

    return 0;
}

antlrcpp::Any irVisitor::visitCallr(tiger::tigerIrParser::CallrContext *ctx){
    std::deque<ProgramValue> queue = visit(ctx->exprList());
    ProgramValue rval = visit(ctx->val());
    std::string funcname = ctx->ID()->getText();
    std::vector<ProgramValue> define;
    std::vector<ProgramValue> use;
    for(ProgramValue p : queue)
    {
        use.push_back(p);
    }
    define.push_back(rval);
    CallInstruction* inst = new CallInstruction(CALLR, define, use);
    inst->setOperands(funcname, queue, rval);
    currentFunction->addInstruction(inst);

    updateInstId(inst);
    isInstBrTarget(inst);
    updatePrevInst(inst);
    checkIfFollowingLabel(inst);

    return 0;
}


antlrcpp::Any irVisitor::visitArray_store(tiger::tigerIrParser::Array_storeContext *ctx){
    ProgramValue array = visit(ctx->val(0));
    ProgramValue index = visit(ctx->val(1));
    ProgramValue storeval = visit(ctx->val(2));
    
    std::vector<ProgramValue> define;
    std::vector<ProgramValue> use;
    use.push_back(index);
    use.push_back(storeval);
    use.push_back(array);

    ArrayInstruction* inst = new ArrayInstruction(ARRAY_STORE, define, use);
    inst->setOperands(array, storeval, index);
    currentFunction->addInstruction(inst);

    updateInstId(inst);
    isInstBrTarget(inst);
    updatePrevInst(inst);
    checkIfFollowingLabel(inst);

    return 0;
}

antlrcpp::Any irVisitor::visitArray_load(tiger::tigerIrParser::Array_loadContext *ctx){
    ProgramValue array = visit(ctx->val(1));
    ProgramValue index = visit(ctx->val(2));
    ProgramValue loadval = visit(ctx->val(0));
    
    std::vector<ProgramValue> define;
    std::vector<ProgramValue> use;
    use.push_back(index);
    use.push_back(array);
    define.push_back(loadval);

    ArrayInstruction* inst = new ArrayInstruction(ARRAY_LOAD, define, use);
    inst->setOperands(array, loadval, index);
    currentFunction->addInstruction(inst);

    updateInstId(inst);
    isInstBrTarget(inst);
    updatePrevInst(inst);
    checkIfFollowingLabel(inst);

    return 0;
}

antlrcpp::Any irVisitor::visitArray_assign(tiger::tigerIrParser::Array_assignContext *ctx){
    
    ProgramValue array = visit(ctx->val(0));
    ProgramValue storeval = visit(ctx->val(2));
    
    std::vector<ProgramValue> define;
    std::vector<ProgramValue> use;
    use.push_back(storeval);
    define.push_back(array);

    ArrayInstruction* inst = new ArrayInstruction(ARRAY_ASSIGN, define, use);
    inst->setOperands(array, storeval);
    currentFunction->addInstruction(inst);

    updateInstId(inst);
    isInstBrTarget(inst);
    updatePrevInst(inst);
    checkIfFollowingLabel(inst);

    return 0;
}

antlrcpp::Any irVisitor::visitLabel(tiger::tigerIrParser::LabelContext *ctx)
{
    lastLabelText = ctx->ID()->getText();
    //printf("irVisitor::visitLabel - labelText=%s\n", lastLabelText.c_str());
    currentFunction->addBranchTarget(lastLabelText);

    isBranchTarget = true;
    lastVisitedLabel = true;

    // Not actual inst. Used in codeGen
    std::vector<ProgramValue> use;
    std::vector<ProgramValue> define; 
    LabelInstruction* instr = new LabelInstruction(LABEL, define, use);
    instr->setOperands(lastLabelText);

    //TODO: figure out what to do with this... if we add it here I'll
    //   need to add some checks.
    currentFunction->addInstruction(instr);

    return 0;
}

template <class ctxType>
antlrcpp::Any irVisitor::visitBinInst(ctxType *ctx, InstOpType instOpType)
{
    std::vector<ProgramValue> lhs; 
    lhs.push_back(visit(ctx->val(2)));
    std::vector<ProgramValue> rhs;
    rhs.push_back(visit(ctx->val(0)));
    rhs.push_back(visit(ctx->val(1)));

    BinaryInstruction* inst = new BinaryInstruction(instOpType, lhs, rhs);
    inst->setOperands(lhs[0], rhs[0], rhs[1]);
    currentFunction->addInstruction(inst);

    updateInstId(inst);
    isInstBrTarget(inst);
    updatePrevInst(inst);
    checkIfFollowingLabel(inst);

    return 0;
}


template <class ctxType>
antlrcpp::Any irVisitor::visitBrInst(ctxType *ctx, InstOpType instOpType)
{
    std::vector<ProgramValue> use;
    std::vector<ProgramValue> define;
    use.push_back(visit(ctx->val(0)));
    use.push_back(visit(ctx->val(1))); 
    BranchInstruction* inst = new BranchInstruction(instOpType, define, use);

    std::string targetLabel = ctx->ID()->getText();
    inst->setOperands(targetLabel, visit(ctx->val(0)), visit(ctx->val(1)));
    currentFunction->addInstruction(inst);

    // printf("irVisitor::visitBrInst - isBranchInst: targetLabel=%s\n", targetLabel.c_str());
    currentFunction->addBranchSrc(targetLabel, inst);
    updateInstId(inst);
    isInstBrTarget(inst);
    updatePrevInst(inst);
    checkIfFollowingLabel(inst);

    // If this is a branch inst the next will be the target
    isBranchTarget = true;
    return 0;
}

void irVisitor::isInstBrTarget(Instruction* inst)
{
    if (isBranchTarget)
    {
        // printf("irVisitor::isInstBrTarget - isBranchTarget\n");
        
        //mark as leader
        inst->markAsLeader();
        inst->isBranchTarget(true);
        currentFunction->addBranchTarget(lastLabelText, inst);
        
        //mark false when done
        isBranchTarget = false;
    }
    
}

void irVisitor::updatePrevInst(Instruction* nextInst)
{
    if (prevInst != nullptr)
    {
        prevInst->addSuccessor(nextInst);
        nextInst->addPredecessor(prevInst);
    }
    //update for next call
    prevInst = nextInst;
}

void irVisitor::updateInstId(Instruction* inst)
{
    inst->setId(instId);
    ++instId;
}

void irVisitor::checkIfFollowingLabel(Instruction* inst)
{
    Instruction* brSrcInst = nullptr;

    if (lastVisitedLabel)
    {
        brSrcInst = currentFunction->getBrSrcInst(lastLabelText);
        if (brSrcInst != nullptr) //getBrSrcInst() can return nullptr
        {
            brSrcInst->addSuccessor(inst);
            inst->addPredecessor(inst);
        }
        lastVisitedLabel = false; //make sure this only happens once
    }
}