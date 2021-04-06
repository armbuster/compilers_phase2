
// Generated from /Users/alexarmbruster/Desktop/compilers_2/grammar/tigerIr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "tigerIrListener.h"


/**
 * This class provides an empty implementation of tigerIrListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  tigerIrBaseListener : public tigerIrListener {
public:

  virtual void enterIrProgram(tigerIrParser::IrProgramContext * /*ctx*/) override { }
  virtual void exitIrProgram(tigerIrParser::IrProgramContext * /*ctx*/) override { }

  virtual void enterFunctionSeqNonempty(tigerIrParser::FunctionSeqNonemptyContext * /*ctx*/) override { }
  virtual void exitFunctionSeqNonempty(tigerIrParser::FunctionSeqNonemptyContext * /*ctx*/) override { }

  virtual void enterFunctionSeqEmpty(tigerIrParser::FunctionSeqEmptyContext * /*ctx*/) override { }
  virtual void exitFunctionSeqEmpty(tigerIrParser::FunctionSeqEmptyContext * /*ctx*/) override { }

  virtual void enterFunction(tigerIrParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(tigerIrParser::FunctionContext * /*ctx*/) override { }

  virtual void enterParamListNonEmpty(tigerIrParser::ParamListNonEmptyContext * /*ctx*/) override { }
  virtual void exitParamListNonEmpty(tigerIrParser::ParamListNonEmptyContext * /*ctx*/) override { }

  virtual void enterParamListEmpty(tigerIrParser::ParamListEmptyContext * /*ctx*/) override { }
  virtual void exitParamListEmpty(tigerIrParser::ParamListEmptyContext * /*ctx*/) override { }

  virtual void enterParamListTailNonEmpty(tigerIrParser::ParamListTailNonEmptyContext * /*ctx*/) override { }
  virtual void exitParamListTailNonEmpty(tigerIrParser::ParamListTailNonEmptyContext * /*ctx*/) override { }

  virtual void enterParamListTailEmpty(tigerIrParser::ParamListTailEmptyContext * /*ctx*/) override { }
  virtual void exitParamListTailEmpty(tigerIrParser::ParamListTailEmptyContext * /*ctx*/) override { }

  virtual void enterParam(tigerIrParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(tigerIrParser::ParamContext * /*ctx*/) override { }

  virtual void enterTypeIdInt(tigerIrParser::TypeIdIntContext * /*ctx*/) override { }
  virtual void exitTypeIdInt(tigerIrParser::TypeIdIntContext * /*ctx*/) override { }

  virtual void enterTypeIdFloat(tigerIrParser::TypeIdFloatContext * /*ctx*/) override { }
  virtual void exitTypeIdFloat(tigerIrParser::TypeIdFloatContext * /*ctx*/) override { }

  virtual void enterTypeIdVoid(tigerIrParser::TypeIdVoidContext * /*ctx*/) override { }
  virtual void exitTypeIdVoid(tigerIrParser::TypeIdVoidContext * /*ctx*/) override { }

  virtual void enterVarListExpand(tigerIrParser::VarListExpandContext * /*ctx*/) override { }
  virtual void exitVarListExpand(tigerIrParser::VarListExpandContext * /*ctx*/) override { }

  virtual void enterVarListSingle(tigerIrParser::VarListSingleContext * /*ctx*/) override { }
  virtual void exitVarListSingle(tigerIrParser::VarListSingleContext * /*ctx*/) override { }

  virtual void enterVarListEmpty(tigerIrParser::VarListEmptyContext * /*ctx*/) override { }
  virtual void exitVarListEmpty(tigerIrParser::VarListEmptyContext * /*ctx*/) override { }

  virtual void enterArrayDerefNonempty(tigerIrParser::ArrayDerefNonemptyContext * /*ctx*/) override { }
  virtual void exitArrayDerefNonempty(tigerIrParser::ArrayDerefNonemptyContext * /*ctx*/) override { }

  virtual void enterArrayDerefEmpty(tigerIrParser::ArrayDerefEmptyContext * /*ctx*/) override { }
  virtual void exitArrayDerefEmpty(tigerIrParser::ArrayDerefEmptyContext * /*ctx*/) override { }

  virtual void enterMultipleNewline(tigerIrParser::MultipleNewlineContext * /*ctx*/) override { }
  virtual void exitMultipleNewline(tigerIrParser::MultipleNewlineContext * /*ctx*/) override { }

  virtual void enterFuncBody(tigerIrParser::FuncBodyContext * /*ctx*/) override { }
  virtual void exitFuncBody(tigerIrParser::FuncBodyContext * /*ctx*/) override { }

  virtual void enterStatSeqNonempty(tigerIrParser::StatSeqNonemptyContext * /*ctx*/) override { }
  virtual void exitStatSeqNonempty(tigerIrParser::StatSeqNonemptyContext * /*ctx*/) override { }

  virtual void enterStatSeqEmpty(tigerIrParser::StatSeqEmptyContext * /*ctx*/) override { }
  virtual void exitStatSeqEmpty(tigerIrParser::StatSeqEmptyContext * /*ctx*/) override { }

  virtual void enterStat(tigerIrParser::StatContext * /*ctx*/) override { }
  virtual void exitStat(tigerIrParser::StatContext * /*ctx*/) override { }

  virtual void enterLabel(tigerIrParser::LabelContext * /*ctx*/) override { }
  virtual void exitLabel(tigerIrParser::LabelContext * /*ctx*/) override { }

  virtual void enterOptionalColon(tigerIrParser::OptionalColonContext * /*ctx*/) override { }
  virtual void exitOptionalColon(tigerIrParser::OptionalColonContext * /*ctx*/) override { }

  virtual void enterAssign(tigerIrParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(tigerIrParser::AssignContext * /*ctx*/) override { }

  virtual void enterAdd(tigerIrParser::AddContext * /*ctx*/) override { }
  virtual void exitAdd(tigerIrParser::AddContext * /*ctx*/) override { }

  virtual void enterSub(tigerIrParser::SubContext * /*ctx*/) override { }
  virtual void exitSub(tigerIrParser::SubContext * /*ctx*/) override { }

  virtual void enterMult(tigerIrParser::MultContext * /*ctx*/) override { }
  virtual void exitMult(tigerIrParser::MultContext * /*ctx*/) override { }

  virtual void enterDiv(tigerIrParser::DivContext * /*ctx*/) override { }
  virtual void exitDiv(tigerIrParser::DivContext * /*ctx*/) override { }

  virtual void enterAnd_op(tigerIrParser::And_opContext * /*ctx*/) override { }
  virtual void exitAnd_op(tigerIrParser::And_opContext * /*ctx*/) override { }

  virtual void enterOr_op(tigerIrParser::Or_opContext * /*ctx*/) override { }
  virtual void exitOr_op(tigerIrParser::Or_opContext * /*ctx*/) override { }

  virtual void enterGoto_op(tigerIrParser::Goto_opContext * /*ctx*/) override { }
  virtual void exitGoto_op(tigerIrParser::Goto_opContext * /*ctx*/) override { }

  virtual void enterBreq(tigerIrParser::BreqContext * /*ctx*/) override { }
  virtual void exitBreq(tigerIrParser::BreqContext * /*ctx*/) override { }

  virtual void enterBrneq(tigerIrParser::BrneqContext * /*ctx*/) override { }
  virtual void exitBrneq(tigerIrParser::BrneqContext * /*ctx*/) override { }

  virtual void enterBrlt(tigerIrParser::BrltContext * /*ctx*/) override { }
  virtual void exitBrlt(tigerIrParser::BrltContext * /*ctx*/) override { }

  virtual void enterBrgt(tigerIrParser::BrgtContext * /*ctx*/) override { }
  virtual void exitBrgt(tigerIrParser::BrgtContext * /*ctx*/) override { }

  virtual void enterBrleq(tigerIrParser::BrleqContext * /*ctx*/) override { }
  virtual void exitBrleq(tigerIrParser::BrleqContext * /*ctx*/) override { }

  virtual void enterBrgeq(tigerIrParser::BrgeqContext * /*ctx*/) override { }
  virtual void exitBrgeq(tigerIrParser::BrgeqContext * /*ctx*/) override { }

  virtual void enterReturn_void(tigerIrParser::Return_voidContext * /*ctx*/) override { }
  virtual void exitReturn_void(tigerIrParser::Return_voidContext * /*ctx*/) override { }

  virtual void enterReturn_nonvoid(tigerIrParser::Return_nonvoidContext * /*ctx*/) override { }
  virtual void exitReturn_nonvoid(tigerIrParser::Return_nonvoidContext * /*ctx*/) override { }

  virtual void enterCall(tigerIrParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(tigerIrParser::CallContext * /*ctx*/) override { }

  virtual void enterCallr(tigerIrParser::CallrContext * /*ctx*/) override { }
  virtual void exitCallr(tigerIrParser::CallrContext * /*ctx*/) override { }

  virtual void enterArray_store(tigerIrParser::Array_storeContext * /*ctx*/) override { }
  virtual void exitArray_store(tigerIrParser::Array_storeContext * /*ctx*/) override { }

  virtual void enterArray_load(tigerIrParser::Array_loadContext * /*ctx*/) override { }
  virtual void exitArray_load(tigerIrParser::Array_loadContext * /*ctx*/) override { }

  virtual void enterArray_assign(tigerIrParser::Array_assignContext * /*ctx*/) override { }
  virtual void exitArray_assign(tigerIrParser::Array_assignContext * /*ctx*/) override { }

  virtual void enterExprListContinue(tigerIrParser::ExprListContinueContext * /*ctx*/) override { }
  virtual void exitExprListContinue(tigerIrParser::ExprListContinueContext * /*ctx*/) override { }

  virtual void enterExprListSingle(tigerIrParser::ExprListSingleContext * /*ctx*/) override { }
  virtual void exitExprListSingle(tigerIrParser::ExprListSingleContext * /*ctx*/) override { }

  virtual void enterExprListEmpty(tigerIrParser::ExprListEmptyContext * /*ctx*/) override { }
  virtual void exitExprListEmpty(tigerIrParser::ExprListEmptyContext * /*ctx*/) override { }

  virtual void enterOptionalComma(tigerIrParser::OptionalCommaContext * /*ctx*/) override { }
  virtual void exitOptionalComma(tigerIrParser::OptionalCommaContext * /*ctx*/) override { }

  virtual void enterValId(tigerIrParser::ValIdContext * /*ctx*/) override { }
  virtual void exitValId(tigerIrParser::ValIdContext * /*ctx*/) override { }

  virtual void enterValIntLit(tigerIrParser::ValIntLitContext * /*ctx*/) override { }
  virtual void exitValIntLit(tigerIrParser::ValIntLitContext * /*ctx*/) override { }

  virtual void enterValFloatLit(tigerIrParser::ValFloatLitContext * /*ctx*/) override { }
  virtual void exitValFloatLit(tigerIrParser::ValFloatLitContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

