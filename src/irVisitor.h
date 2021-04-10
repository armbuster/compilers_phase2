
#pragma once


#include "tigerIrBaseVisitor.h"
#include "Module.h"
#include "Instruction.h"
#include "Function.h"
#include <string>
#include <map>
#include <deque>
#include <vector>


 class irVisitor : public tiger::tigerIrBaseVisitor {
     Module* mod;
     Function* currentFunction;
     std::map<std::string, ProgramValue> dtypeMap;

     public:
        irVisitor();

        Module* getModule();

        void updateDtypeMap(std::map<std::string, ProgramValue> * dtypes);

        antlrcpp::Any visitFunction(tiger::tigerIrParser::FunctionContext *ctx);

        antlrcpp::Any visitParamListNonEmpty(tiger::tigerIrParser::ParamListNonEmptyContext *ctx);

        antlrcpp::Any visitParamListEmpty(tiger::tigerIrParser::ParamListEmptyContext *ctx);

        antlrcpp::Any visitParamListTailNonEmpty(tiger::tigerIrParser::ParamListTailNonEmptyContext *ctx);

        antlrcpp::Any visitParamListTailEmpty(tiger::tigerIrParser::ParamListTailEmptyContext *ctx);

        antlrcpp::Any visitParam(tiger::tigerIrParser::ParamContext *ctx);

        antlrcpp::Any visitVarListExpand(tiger::tigerIrParser::VarListExpandContext *ctx);

        antlrcpp::Any visitVarListSingle(tiger::tigerIrParser::VarListSingleContext *ctx);

        antlrcpp::Any visitVarListEmpty(tiger::tigerIrParser::VarListEmptyContext *ctx);

        antlrcpp::Any visitTypeIdInt(tiger::tigerIrParser::TypeIdIntContext *ctx);

        antlrcpp::Any visitTypeIdFloat(tiger::tigerIrParser::TypeIdFloatContext *ctx);

        antlrcpp::Any visitTypeIdVoid(tiger::tigerIrParser::TypeIdVoidContext *ctx);

        antlrcpp::Any visitArrayDerefNonempty(tiger::tigerIrParser::ArrayDerefNonemptyContext *ctx);

        antlrcpp::Any visitArrayDerefEmpty(tiger::tigerIrParser::ArrayDerefEmptyContext *ctx);

        antlrcpp::Any visitExprListContinue(tiger::tigerIrParser::ExprListContinueContext *ctx);

        antlrcpp::Any visitExprListSingle(tiger::tigerIrParser::ExprListSingleContext *ctx);

        antlrcpp::Any visitExprListEmpty(tiger::tigerIrParser::ExprListEmptyContext *ctx);

        antlrcpp::Any visitAssign(tiger::tigerIrParser::AssignContext *ctx);

        antlrcpp::Any visitAdd(tiger::tigerIrParser::AddContext *ctx);

        antlrcpp::Any visitSub(tiger::tigerIrParser::SubContext *ctx);

        antlrcpp::Any visitMult(tiger::tigerIrParser::MultContext *ctx);

        antlrcpp::Any visitDiv(tiger::tigerIrParser::DivContext *ctx);

        antlrcpp::Any visitAnd_op(tiger::tigerIrParser::And_opContext *ctx);

        antlrcpp::Any visitOr_op(tiger::tigerIrParser::Or_opContext *ctx);

        antlrcpp::Any visitGoto_op(tiger::tigerIrParser::Goto_opContext *ctx);

        antlrcpp::Any visitBreq(tiger::tigerIrParser::BreqContext *ctx);

        antlrcpp::Any visitBrneq(tiger::tigerIrParser::BrneqContext *ctx);

        antlrcpp::Any visitBrlt(tiger::tigerIrParser::BrltContext *ctx);

        antlrcpp::Any visitBrgt(tiger::tigerIrParser::BrgtContext *ctx);

        antlrcpp::Any visitBrleq(tiger::tigerIrParser::BrleqContext *ctx);

        antlrcpp::Any visitBrgeq(tiger::tigerIrParser::BrgeqContext *ctx);

        antlrcpp::Any visitReturn_void(tiger::tigerIrParser::Return_voidContext *ctx);

        antlrcpp::Any visitReturn_nonvoid(tiger::tigerIrParser::Return_nonvoidContext *ctx);

        antlrcpp::Any visitCall(tiger::tigerIrParser::CallContext *ctx);

        antlrcpp::Any visitCallr(tiger::tigerIrParser::CallrContext *ctx);

        antlrcpp::Any visitArray_store(tiger::tigerIrParser::Array_storeContext *ctx);

        antlrcpp::Any visitArray_load(tiger::tigerIrParser::Array_loadContext *ctx);

        antlrcpp::Any visitArray_assign(tiger::tigerIrParser::Array_assignContext *ctx);

        antlrcpp::Any visitValId(tiger::tigerIrParser::ValIdContext *ctx);

        antlrcpp::Any visitValIntLit(tiger::tigerIrParser::ValIntLitContext *ctx);

        antlrcpp::Any visitValFloatLit(tiger::tigerIrParser::ValFloatLitContext *ctx);

        antlrcpp::Any visitLabel(tiger::tigerIrParser::LabelContext *ctx);

     private:
        template <class ctxType>
        antlrcpp::Any visitBinInst(ctxType *ctx, InstructionType instType);

        template <class ctxType>
        antlrcpp::Any visitBrInst(ctxType *ctx, InstructionType instType);

};