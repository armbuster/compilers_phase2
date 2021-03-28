

#include "irVisitor.h"


irVisitor::irVisitor()
{
    mod = new Module();
}

Module * irVisitor::getModule()
{
    return mod;
}


antlrcpp::Any irVisitor::visitFunction(tiger::tigerIrParser::FunctionContext *ctx){

    // get info about the function
    std::deque<std::string> params = visit(ctx -> paramList());
    DataType dtype = visit(ctx -> typeId());
    std::string funcname = ctx -> ID(0) -> getText();
    std::deque<ProgramValue> intList = visit(ctx -> varList(0));
    std::deque<ProgramValue> floatList = visit(ctx -> varList(1));
    
    // create function object
    Function * currentFunction = new Function(funcname, dtype, floatList, intList);
    visit(ctx -> funcBody());
    mod -> addFunction(currentFunction);
    return 0;

}

antlrcpp::Any irVisitor::visitParamListNonEmpty(tiger::tigerIrParser::ParamListNonEmptyContext *ctx){
    std::deque<std::string> paramList = visit(ctx ->paramListTail());
    std::string param = visit(ctx -> param());
    paramList.push_front(param);
    return paramList;
}

antlrcpp::Any irVisitor::visitParamListEmpty(tiger::tigerIrParser::ParamListEmptyContext *ctx){
    std::deque<std::string> paramList;
    return paramList;
}

antlrcpp::Any irVisitor::visitParamListTailNonEmpty(tiger::tigerIrParser::ParamListTailNonEmptyContext *ctx){
    std::deque<std::string> paramList = visit(ctx ->paramListTail());
    std::string param = visit(ctx -> param());
    paramList.push_front(param);
    return paramList;
}

antlrcpp::Any irVisitor::visitParamListTailEmpty(tiger::tigerIrParser::ParamListTailEmptyContext *ctx){
    std::deque<std::string> paramList;
    return paramList;
}

antlrcpp::Any irVisitor::visitParam(tiger::tigerIrParser::ParamContext *ctx){
    std::string id = ctx -> ID() -> getText();
    return id;
}

// antlrcpp::Any irVisitor::visitTypeId(tiger::tigerIrParser::TypeIdContext *ctx){}

antlrcpp::Any irVisitor::visitVarListExpand(tiger::tigerIrParser::VarListExpandContext *ctx){
    std::deque<ProgramValue> varList = visit(ctx -> varList());
    int size = visit(ctx -> arrayDeref());
    ValType vtype;
    if(size == 0)
        vtype=VAR;
    else if(size > 0)
        vtype=ARRAY;

    ProgramValue pval = {vtype, UNKNOWN, ctx -> ID() -> getText(), size};
    varList.push_front(pval);
    return varList;
}

antlrcpp::Any irVisitor::visitVarListSingle(tiger::tigerIrParser::VarListSingleContext *ctx){
    std::deque<ProgramValue> varList;
    int size = visit(ctx -> arrayDeref());
    ValType vtype;
    if(size == 0)
        vtype=VAR;
    else if(size > 0)
        vtype=ARRAY;

    ProgramValue pval = {vtype, UNKNOWN, ctx -> ID() -> getText(), size};
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
    ProgramValue val = {VAR, UNKNOWN, ctx -> ID() -> getText(), 0};
    return val;
}

antlrcpp::Any irVisitor::visitValIntLit(tiger::tigerIrParser::ValIntLitContext *ctx){
    ProgramValue val = {LITERAL, INT, ctx -> INTLIT() -> getText(), 0};
    return val;
}

antlrcpp::Any irVisitor::visitValFloatLit(tiger::tigerIrParser::ValFloatLitContext *ctx){
    ProgramValue val = {LITERAL, FLOAT, ctx -> FLOATLIT() -> getText(), 0};
    return val;
}


antlrcpp::Any irVisitor::visitArrayDerefNonempty(tiger::tigerIrParser::ArrayDerefNonemptyContext *ctx){
    return std::stoi(ctx -> INTLIT() -> getText());
}

antlrcpp::Any irVisitor::visitArrayDerefEmpty(tiger::tigerIrParser::ArrayDerefEmptyContext *ctx){
    return 0;
}



antlrcpp::Any irVisitor::visitAssign(tiger::tigerIrParser::AssignContext *ctx){
    
    // TODO: implement ProgramValue struct
    
    std::vector<ProgramValue> lhs; 
    lhs.push_back(visit(ctx -> val(0)));
    std::vector<ProgramValue> rhs;
    rhs.push_back(visit(ctx -> val(0)));
    Instruction * instr = new AssignInstruction(ASSIGN, lhs, rhs);
    return 0;
}

// antlrcpp::Any irVisitor::visitAdd(tiger::tigerIrParser::AddContext *ctx){}

// antlrcpp::Any irVisitor::visitSub(tiger::tigerIrParser::SubContext *ctx){}

// antlrcpp::Any irVisitor::visitMult(tiger::tigerIrParser::MultContext *ctx){}

// antlrcpp::Any irVisitor::visitDiv(tiger::tigerIrParser::DivContext *ctx){}

// antlrcpp::Any irVisitor::visitAnd_op(tiger::tigerIrParser::And_opContext *ctx){}

// antlrcpp::Any irVisitor::visitOr_op(tiger::tigerIrParser::Or_opContext *ctx){}

// antlrcpp::Any irVisitor::visitGoto_op(tiger::tigerIrParser::Goto_opContext *ctx){}

// antlrcpp::Any irVisitor::visitBreq(tiger::tigerIrParser::BreqContext *ctx){}

// antlrcpp::Any irVisitor::visitBrneq(tiger::tigerIrParser::BrneqContext *ctx){}

// antlrcpp::Any irVisitor::visitBrlt(tiger::tigerIrParser::BrltContext *ctx){}

// antlrcpp::Any irVisitor::visitBrgt(tiger::tigerIrParser::BrgtContext *ctx){}

// antlrcpp::Any irVisitor::visitBrleq(tiger::tigerIrParser::BrleqContext *ctx){}

// antlrcpp::Any irVisitor::visitBrgeq(tiger::tigerIrParser::BrgeqContext *ctx){}

// antlrcpp::Any irVisitor::visitReturn_void(tiger::tigerIrParser::Return_voidContext *ctx){}

// antlrcpp::Any irVisitor::visitReturn_nonvoid(tiger::tigerIrParser::Return_nonvoidContext *ctx){}

// antlrcpp::Any irVisitor::visitCall(tiger::tigerIrParser::CallContext *ctx){}

// antlrcpp::Any irVisitor::visitCallr(tiger::tigerIrParser::CallrContext *ctx){}

// antlrcpp::Any irVisitor::visitArray_store(tiger::tigerIrParser::Array_storeContext *ctx){}

// antlrcpp::Any irVisitor::visitArray_load(tiger::tigerIrParser::Array_loadContext *ctx){}

// antlrcpp::Any irVisitor::visitArray_assign(tiger::tigerIrParser::Array_assignContext *ctx){}

