
// Generated from /Users/alexarmbruster/Desktop/compilers_2/grammar/tigerIr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "tigerIrParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by tigerIrParser.
 */
class  tigerIrListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterIrProgram(tigerIrParser::IrProgramContext *ctx) = 0;
  virtual void exitIrProgram(tigerIrParser::IrProgramContext *ctx) = 0;

  virtual void enterFunctionSeqNonempty(tigerIrParser::FunctionSeqNonemptyContext *ctx) = 0;
  virtual void exitFunctionSeqNonempty(tigerIrParser::FunctionSeqNonemptyContext *ctx) = 0;

  virtual void enterFunctionSeqEmpty(tigerIrParser::FunctionSeqEmptyContext *ctx) = 0;
  virtual void exitFunctionSeqEmpty(tigerIrParser::FunctionSeqEmptyContext *ctx) = 0;

  virtual void enterFunction(tigerIrParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(tigerIrParser::FunctionContext *ctx) = 0;

  virtual void enterParamListNonEmpty(tigerIrParser::ParamListNonEmptyContext *ctx) = 0;
  virtual void exitParamListNonEmpty(tigerIrParser::ParamListNonEmptyContext *ctx) = 0;

  virtual void enterParamListEmpty(tigerIrParser::ParamListEmptyContext *ctx) = 0;
  virtual void exitParamListEmpty(tigerIrParser::ParamListEmptyContext *ctx) = 0;

  virtual void enterParamListTailNonEmpty(tigerIrParser::ParamListTailNonEmptyContext *ctx) = 0;
  virtual void exitParamListTailNonEmpty(tigerIrParser::ParamListTailNonEmptyContext *ctx) = 0;

  virtual void enterParamListTailEmpty(tigerIrParser::ParamListTailEmptyContext *ctx) = 0;
  virtual void exitParamListTailEmpty(tigerIrParser::ParamListTailEmptyContext *ctx) = 0;

  virtual void enterParam(tigerIrParser::ParamContext *ctx) = 0;
  virtual void exitParam(tigerIrParser::ParamContext *ctx) = 0;

  virtual void enterTypeIdInt(tigerIrParser::TypeIdIntContext *ctx) = 0;
  virtual void exitTypeIdInt(tigerIrParser::TypeIdIntContext *ctx) = 0;

  virtual void enterTypeIdFloat(tigerIrParser::TypeIdFloatContext *ctx) = 0;
  virtual void exitTypeIdFloat(tigerIrParser::TypeIdFloatContext *ctx) = 0;

  virtual void enterTypeIdVoid(tigerIrParser::TypeIdVoidContext *ctx) = 0;
  virtual void exitTypeIdVoid(tigerIrParser::TypeIdVoidContext *ctx) = 0;

  virtual void enterVarListExpand(tigerIrParser::VarListExpandContext *ctx) = 0;
  virtual void exitVarListExpand(tigerIrParser::VarListExpandContext *ctx) = 0;

  virtual void enterVarListSingle(tigerIrParser::VarListSingleContext *ctx) = 0;
  virtual void exitVarListSingle(tigerIrParser::VarListSingleContext *ctx) = 0;

  virtual void enterVarListEmpty(tigerIrParser::VarListEmptyContext *ctx) = 0;
  virtual void exitVarListEmpty(tigerIrParser::VarListEmptyContext *ctx) = 0;

  virtual void enterArrayDerefNonempty(tigerIrParser::ArrayDerefNonemptyContext *ctx) = 0;
  virtual void exitArrayDerefNonempty(tigerIrParser::ArrayDerefNonemptyContext *ctx) = 0;

  virtual void enterArrayDerefEmpty(tigerIrParser::ArrayDerefEmptyContext *ctx) = 0;
  virtual void exitArrayDerefEmpty(tigerIrParser::ArrayDerefEmptyContext *ctx) = 0;

  virtual void enterMultipleNewline(tigerIrParser::MultipleNewlineContext *ctx) = 0;
  virtual void exitMultipleNewline(tigerIrParser::MultipleNewlineContext *ctx) = 0;

  virtual void enterFuncBody(tigerIrParser::FuncBodyContext *ctx) = 0;
  virtual void exitFuncBody(tigerIrParser::FuncBodyContext *ctx) = 0;

  virtual void enterStatSeqNonempty(tigerIrParser::StatSeqNonemptyContext *ctx) = 0;
  virtual void exitStatSeqNonempty(tigerIrParser::StatSeqNonemptyContext *ctx) = 0;

  virtual void enterStatSeqEmpty(tigerIrParser::StatSeqEmptyContext *ctx) = 0;
  virtual void exitStatSeqEmpty(tigerIrParser::StatSeqEmptyContext *ctx) = 0;

  virtual void enterStat(tigerIrParser::StatContext *ctx) = 0;
  virtual void exitStat(tigerIrParser::StatContext *ctx) = 0;

  virtual void enterLabel(tigerIrParser::LabelContext *ctx) = 0;
  virtual void exitLabel(tigerIrParser::LabelContext *ctx) = 0;

  virtual void enterOptionalColon(tigerIrParser::OptionalColonContext *ctx) = 0;
  virtual void exitOptionalColon(tigerIrParser::OptionalColonContext *ctx) = 0;

  virtual void enterAssign(tigerIrParser::AssignContext *ctx) = 0;
  virtual void exitAssign(tigerIrParser::AssignContext *ctx) = 0;

  virtual void enterAdd(tigerIrParser::AddContext *ctx) = 0;
  virtual void exitAdd(tigerIrParser::AddContext *ctx) = 0;

  virtual void enterSub(tigerIrParser::SubContext *ctx) = 0;
  virtual void exitSub(tigerIrParser::SubContext *ctx) = 0;

  virtual void enterMult(tigerIrParser::MultContext *ctx) = 0;
  virtual void exitMult(tigerIrParser::MultContext *ctx) = 0;

  virtual void enterDiv(tigerIrParser::DivContext *ctx) = 0;
  virtual void exitDiv(tigerIrParser::DivContext *ctx) = 0;

  virtual void enterAnd_op(tigerIrParser::And_opContext *ctx) = 0;
  virtual void exitAnd_op(tigerIrParser::And_opContext *ctx) = 0;

  virtual void enterOr_op(tigerIrParser::Or_opContext *ctx) = 0;
  virtual void exitOr_op(tigerIrParser::Or_opContext *ctx) = 0;

  virtual void enterGoto_op(tigerIrParser::Goto_opContext *ctx) = 0;
  virtual void exitGoto_op(tigerIrParser::Goto_opContext *ctx) = 0;

  virtual void enterBreq(tigerIrParser::BreqContext *ctx) = 0;
  virtual void exitBreq(tigerIrParser::BreqContext *ctx) = 0;

  virtual void enterBrneq(tigerIrParser::BrneqContext *ctx) = 0;
  virtual void exitBrneq(tigerIrParser::BrneqContext *ctx) = 0;

  virtual void enterBrlt(tigerIrParser::BrltContext *ctx) = 0;
  virtual void exitBrlt(tigerIrParser::BrltContext *ctx) = 0;

  virtual void enterBrgt(tigerIrParser::BrgtContext *ctx) = 0;
  virtual void exitBrgt(tigerIrParser::BrgtContext *ctx) = 0;

  virtual void enterBrleq(tigerIrParser::BrleqContext *ctx) = 0;
  virtual void exitBrleq(tigerIrParser::BrleqContext *ctx) = 0;

  virtual void enterBrgeq(tigerIrParser::BrgeqContext *ctx) = 0;
  virtual void exitBrgeq(tigerIrParser::BrgeqContext *ctx) = 0;

  virtual void enterReturn_void(tigerIrParser::Return_voidContext *ctx) = 0;
  virtual void exitReturn_void(tigerIrParser::Return_voidContext *ctx) = 0;

  virtual void enterReturn_nonvoid(tigerIrParser::Return_nonvoidContext *ctx) = 0;
  virtual void exitReturn_nonvoid(tigerIrParser::Return_nonvoidContext *ctx) = 0;

  virtual void enterCall(tigerIrParser::CallContext *ctx) = 0;
  virtual void exitCall(tigerIrParser::CallContext *ctx) = 0;

  virtual void enterCallr(tigerIrParser::CallrContext *ctx) = 0;
  virtual void exitCallr(tigerIrParser::CallrContext *ctx) = 0;

  virtual void enterArray_store(tigerIrParser::Array_storeContext *ctx) = 0;
  virtual void exitArray_store(tigerIrParser::Array_storeContext *ctx) = 0;

  virtual void enterArray_load(tigerIrParser::Array_loadContext *ctx) = 0;
  virtual void exitArray_load(tigerIrParser::Array_loadContext *ctx) = 0;

  virtual void enterArray_assign(tigerIrParser::Array_assignContext *ctx) = 0;
  virtual void exitArray_assign(tigerIrParser::Array_assignContext *ctx) = 0;

  virtual void enterExprListContinue(tigerIrParser::ExprListContinueContext *ctx) = 0;
  virtual void exitExprListContinue(tigerIrParser::ExprListContinueContext *ctx) = 0;

  virtual void enterExprListSingle(tigerIrParser::ExprListSingleContext *ctx) = 0;
  virtual void exitExprListSingle(tigerIrParser::ExprListSingleContext *ctx) = 0;

  virtual void enterExprListEmpty(tigerIrParser::ExprListEmptyContext *ctx) = 0;
  virtual void exitExprListEmpty(tigerIrParser::ExprListEmptyContext *ctx) = 0;

  virtual void enterOptionalComma(tigerIrParser::OptionalCommaContext *ctx) = 0;
  virtual void exitOptionalComma(tigerIrParser::OptionalCommaContext *ctx) = 0;

  virtual void enterValId(tigerIrParser::ValIdContext *ctx) = 0;
  virtual void exitValId(tigerIrParser::ValIdContext *ctx) = 0;

  virtual void enterValIntLit(tigerIrParser::ValIntLitContext *ctx) = 0;
  virtual void exitValIntLit(tigerIrParser::ValIntLitContext *ctx) = 0;

  virtual void enterValFloatLit(tigerIrParser::ValFloatLitContext *ctx) = 0;
  virtual void exitValFloatLit(tigerIrParser::ValFloatLitContext *ctx) = 0;


};

