
// Generated from /Users/alexarmbruster/Desktop/compilers_2/grammar/tigerIr.g4 by ANTLR 4.8


#include "tigerIrListener.h"

#include "tigerIrParser.h"


using namespace antlrcpp;
using namespace antlr4;

tigerIrParser::tigerIrParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

tigerIrParser::~tigerIrParser() {
  delete _interpreter;
}

std::string tigerIrParser::getGrammarFileName() const {
  return "tigerIr.g4";
}

const std::vector<std::string>& tigerIrParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& tigerIrParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- IrProgramContext ------------------------------------------------------------------

tigerIrParser::IrProgramContext::IrProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tigerIrParser::FunctionContext* tigerIrParser::IrProgramContext::function() {
  return getRuleContext<tigerIrParser::FunctionContext>(0);
}

tigerIrParser::FunctionSeqContext* tigerIrParser::IrProgramContext::functionSeq() {
  return getRuleContext<tigerIrParser::FunctionSeqContext>(0);
}


size_t tigerIrParser::IrProgramContext::getRuleIndex() const {
  return tigerIrParser::RuleIrProgram;
}

void tigerIrParser::IrProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIrProgram(this);
}

void tigerIrParser::IrProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIrProgram(this);
}

tigerIrParser::IrProgramContext* tigerIrParser::irProgram() {
  IrProgramContext *_localctx = _tracker.createInstance<IrProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, tigerIrParser::RuleIrProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    function();
    setState(79);
    functionSeq();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionSeqContext ------------------------------------------------------------------

tigerIrParser::FunctionSeqContext::FunctionSeqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t tigerIrParser::FunctionSeqContext::getRuleIndex() const {
  return tigerIrParser::RuleFunctionSeq;
}

void tigerIrParser::FunctionSeqContext::copyFrom(FunctionSeqContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FunctionSeqEmptyContext ------------------------------------------------------------------

tigerIrParser::FunctionSeqEmptyContext::FunctionSeqEmptyContext(FunctionSeqContext *ctx) { copyFrom(ctx); }

void tigerIrParser::FunctionSeqEmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionSeqEmpty(this);
}
void tigerIrParser::FunctionSeqEmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionSeqEmpty(this);
}
//----------------- FunctionSeqNonemptyContext ------------------------------------------------------------------

tigerIrParser::FunctionContext* tigerIrParser::FunctionSeqNonemptyContext::function() {
  return getRuleContext<tigerIrParser::FunctionContext>(0);
}

tigerIrParser::FunctionSeqContext* tigerIrParser::FunctionSeqNonemptyContext::functionSeq() {
  return getRuleContext<tigerIrParser::FunctionSeqContext>(0);
}

tigerIrParser::FunctionSeqNonemptyContext::FunctionSeqNonemptyContext(FunctionSeqContext *ctx) { copyFrom(ctx); }

void tigerIrParser::FunctionSeqNonemptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionSeqNonempty(this);
}
void tigerIrParser::FunctionSeqNonemptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionSeqNonempty(this);
}
tigerIrParser::FunctionSeqContext* tigerIrParser::functionSeq() {
  FunctionSeqContext *_localctx = _tracker.createInstance<FunctionSeqContext>(_ctx, getState());
  enterRule(_localctx, 2, tigerIrParser::RuleFunctionSeq);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(85);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case tigerIrParser::START_FUNCTION: {
        _localctx = dynamic_cast<FunctionSeqContext *>(_tracker.createInstance<tigerIrParser::FunctionSeqNonemptyContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(81);
        function();
        setState(82);
        functionSeq();
        break;
      }

      case tigerIrParser::EOF: {
        _localctx = dynamic_cast<FunctionSeqContext *>(_tracker.createInstance<tigerIrParser::FunctionSeqEmptyContext>(_localctx));
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

tigerIrParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::FunctionContext::START_FUNCTION() {
  return getToken(tigerIrParser::START_FUNCTION, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::FunctionContext::ID() {
  return getTokens(tigerIrParser::ID);
}

tree::TerminalNode* tigerIrParser::FunctionContext::ID(size_t i) {
  return getToken(tigerIrParser::ID, i);
}

std::vector<tree::TerminalNode *> tigerIrParser::FunctionContext::NEWLINE() {
  return getTokens(tigerIrParser::NEWLINE);
}

tree::TerminalNode* tigerIrParser::FunctionContext::NEWLINE(size_t i) {
  return getToken(tigerIrParser::NEWLINE, i);
}

tigerIrParser::TypeIdContext* tigerIrParser::FunctionContext::typeId() {
  return getRuleContext<tigerIrParser::TypeIdContext>(0);
}

tree::TerminalNode* tigerIrParser::FunctionContext::OPENPAREN() {
  return getToken(tigerIrParser::OPENPAREN, 0);
}

tigerIrParser::ParamListContext* tigerIrParser::FunctionContext::paramList() {
  return getRuleContext<tigerIrParser::ParamListContext>(0);
}

tree::TerminalNode* tigerIrParser::FunctionContext::CLOSEPAREN() {
  return getToken(tigerIrParser::CLOSEPAREN, 0);
}

tree::TerminalNode* tigerIrParser::FunctionContext::INT_LIST() {
  return getToken(tigerIrParser::INT_LIST, 0);
}

std::vector<tigerIrParser::VarListContext *> tigerIrParser::FunctionContext::varList() {
  return getRuleContexts<tigerIrParser::VarListContext>();
}

tigerIrParser::VarListContext* tigerIrParser::FunctionContext::varList(size_t i) {
  return getRuleContext<tigerIrParser::VarListContext>(i);
}

tree::TerminalNode* tigerIrParser::FunctionContext::FLOAT_LIST() {
  return getToken(tigerIrParser::FLOAT_LIST, 0);
}

tigerIrParser::FuncBodyContext* tigerIrParser::FunctionContext::funcBody() {
  return getRuleContext<tigerIrParser::FuncBodyContext>(0);
}

tree::TerminalNode* tigerIrParser::FunctionContext::END_FUNCTION() {
  return getToken(tigerIrParser::END_FUNCTION, 0);
}

tigerIrParser::MultipleNewlineContext* tigerIrParser::FunctionContext::multipleNewline() {
  return getRuleContext<tigerIrParser::MultipleNewlineContext>(0);
}


size_t tigerIrParser::FunctionContext::getRuleIndex() const {
  return tigerIrParser::RuleFunction;
}

void tigerIrParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void tigerIrParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

tigerIrParser::FunctionContext* tigerIrParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 4, tigerIrParser::RuleFunction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(tigerIrParser::START_FUNCTION);
    setState(88);
    match(tigerIrParser::ID);
    setState(89);
    match(tigerIrParser::NEWLINE);
    setState(90);
    typeId();
    setState(91);
    match(tigerIrParser::ID);
    setState(92);
    match(tigerIrParser::OPENPAREN);
    setState(93);
    paramList();
    setState(94);
    match(tigerIrParser::CLOSEPAREN);
    setState(95);
    match(tigerIrParser::NEWLINE);
    setState(96);
    match(tigerIrParser::INT_LIST);
    setState(97);
    varList();
    setState(98);
    match(tigerIrParser::NEWLINE);
    setState(99);
    match(tigerIrParser::FLOAT_LIST);
    setState(100);
    varList();
    setState(101);
    match(tigerIrParser::NEWLINE);
    setState(102);
    funcBody();
    setState(103);
    match(tigerIrParser::END_FUNCTION);
    setState(104);
    match(tigerIrParser::ID);
    setState(105);
    multipleNewline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

tigerIrParser::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t tigerIrParser::ParamListContext::getRuleIndex() const {
  return tigerIrParser::RuleParamList;
}

void tigerIrParser::ParamListContext::copyFrom(ParamListContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParamListEmptyContext ------------------------------------------------------------------

tigerIrParser::ParamListEmptyContext::ParamListEmptyContext(ParamListContext *ctx) { copyFrom(ctx); }

void tigerIrParser::ParamListEmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamListEmpty(this);
}
void tigerIrParser::ParamListEmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamListEmpty(this);
}
//----------------- ParamListNonEmptyContext ------------------------------------------------------------------

tigerIrParser::ParamContext* tigerIrParser::ParamListNonEmptyContext::param() {
  return getRuleContext<tigerIrParser::ParamContext>(0);
}

tigerIrParser::ParamListTailContext* tigerIrParser::ParamListNonEmptyContext::paramListTail() {
  return getRuleContext<tigerIrParser::ParamListTailContext>(0);
}

tigerIrParser::ParamListNonEmptyContext::ParamListNonEmptyContext(ParamListContext *ctx) { copyFrom(ctx); }

void tigerIrParser::ParamListNonEmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamListNonEmpty(this);
}
void tigerIrParser::ParamListNonEmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamListNonEmpty(this);
}
tigerIrParser::ParamListContext* tigerIrParser::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 6, tigerIrParser::RuleParamList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(111);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case tigerIrParser::FLOAT:
      case tigerIrParser::INT:
      case tigerIrParser::VOID: {
        _localctx = dynamic_cast<ParamListContext *>(_tracker.createInstance<tigerIrParser::ParamListNonEmptyContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(107);
        param();
        setState(108);
        paramListTail();
        break;
      }

      case tigerIrParser::CLOSEPAREN: {
        _localctx = dynamic_cast<ParamListContext *>(_tracker.createInstance<tigerIrParser::ParamListEmptyContext>(_localctx));
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamListTailContext ------------------------------------------------------------------

tigerIrParser::ParamListTailContext::ParamListTailContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t tigerIrParser::ParamListTailContext::getRuleIndex() const {
  return tigerIrParser::RuleParamListTail;
}

void tigerIrParser::ParamListTailContext::copyFrom(ParamListTailContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParamListTailNonEmptyContext ------------------------------------------------------------------

tree::TerminalNode* tigerIrParser::ParamListTailNonEmptyContext::COMMA() {
  return getToken(tigerIrParser::COMMA, 0);
}

tigerIrParser::ParamContext* tigerIrParser::ParamListTailNonEmptyContext::param() {
  return getRuleContext<tigerIrParser::ParamContext>(0);
}

tigerIrParser::ParamListTailContext* tigerIrParser::ParamListTailNonEmptyContext::paramListTail() {
  return getRuleContext<tigerIrParser::ParamListTailContext>(0);
}

tigerIrParser::ParamListTailNonEmptyContext::ParamListTailNonEmptyContext(ParamListTailContext *ctx) { copyFrom(ctx); }

void tigerIrParser::ParamListTailNonEmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamListTailNonEmpty(this);
}
void tigerIrParser::ParamListTailNonEmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamListTailNonEmpty(this);
}
//----------------- ParamListTailEmptyContext ------------------------------------------------------------------

tigerIrParser::ParamListTailEmptyContext::ParamListTailEmptyContext(ParamListTailContext *ctx) { copyFrom(ctx); }

void tigerIrParser::ParamListTailEmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamListTailEmpty(this);
}
void tigerIrParser::ParamListTailEmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamListTailEmpty(this);
}
tigerIrParser::ParamListTailContext* tigerIrParser::paramListTail() {
  ParamListTailContext *_localctx = _tracker.createInstance<ParamListTailContext>(_ctx, getState());
  enterRule(_localctx, 8, tigerIrParser::RuleParamListTail);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(118);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case tigerIrParser::COMMA: {
        _localctx = dynamic_cast<ParamListTailContext *>(_tracker.createInstance<tigerIrParser::ParamListTailNonEmptyContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(113);
        match(tigerIrParser::COMMA);
        setState(114);
        param();
        setState(115);
        paramListTail();
        break;
      }

      case tigerIrParser::CLOSEPAREN: {
        _localctx = dynamic_cast<ParamListTailContext *>(_tracker.createInstance<tigerIrParser::ParamListTailEmptyContext>(_localctx));
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

tigerIrParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tigerIrParser::TypeIdContext* tigerIrParser::ParamContext::typeId() {
  return getRuleContext<tigerIrParser::TypeIdContext>(0);
}

tree::TerminalNode* tigerIrParser::ParamContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}


size_t tigerIrParser::ParamContext::getRuleIndex() const {
  return tigerIrParser::RuleParam;
}

void tigerIrParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void tigerIrParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}

tigerIrParser::ParamContext* tigerIrParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 10, tigerIrParser::RuleParam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    typeId();
    setState(121);
    match(tigerIrParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeIdContext ------------------------------------------------------------------

tigerIrParser::TypeIdContext::TypeIdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t tigerIrParser::TypeIdContext::getRuleIndex() const {
  return tigerIrParser::RuleTypeId;
}

void tigerIrParser::TypeIdContext::copyFrom(TypeIdContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TypeIdFloatContext ------------------------------------------------------------------

tree::TerminalNode* tigerIrParser::TypeIdFloatContext::FLOAT() {
  return getToken(tigerIrParser::FLOAT, 0);
}

tigerIrParser::TypeIdFloatContext::TypeIdFloatContext(TypeIdContext *ctx) { copyFrom(ctx); }

void tigerIrParser::TypeIdFloatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeIdFloat(this);
}
void tigerIrParser::TypeIdFloatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeIdFloat(this);
}
//----------------- TypeIdIntContext ------------------------------------------------------------------

tree::TerminalNode* tigerIrParser::TypeIdIntContext::INT() {
  return getToken(tigerIrParser::INT, 0);
}

tigerIrParser::TypeIdIntContext::TypeIdIntContext(TypeIdContext *ctx) { copyFrom(ctx); }

void tigerIrParser::TypeIdIntContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeIdInt(this);
}
void tigerIrParser::TypeIdIntContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeIdInt(this);
}
//----------------- TypeIdVoidContext ------------------------------------------------------------------

tree::TerminalNode* tigerIrParser::TypeIdVoidContext::VOID() {
  return getToken(tigerIrParser::VOID, 0);
}

tigerIrParser::TypeIdVoidContext::TypeIdVoidContext(TypeIdContext *ctx) { copyFrom(ctx); }

void tigerIrParser::TypeIdVoidContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeIdVoid(this);
}
void tigerIrParser::TypeIdVoidContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeIdVoid(this);
}
tigerIrParser::TypeIdContext* tigerIrParser::typeId() {
  TypeIdContext *_localctx = _tracker.createInstance<TypeIdContext>(_ctx, getState());
  enterRule(_localctx, 12, tigerIrParser::RuleTypeId);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(126);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case tigerIrParser::INT: {
        _localctx = dynamic_cast<TypeIdContext *>(_tracker.createInstance<tigerIrParser::TypeIdIntContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(123);
        match(tigerIrParser::INT);
        break;
      }

      case tigerIrParser::FLOAT: {
        _localctx = dynamic_cast<TypeIdContext *>(_tracker.createInstance<tigerIrParser::TypeIdFloatContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(124);
        match(tigerIrParser::FLOAT);
        break;
      }

      case tigerIrParser::VOID: {
        _localctx = dynamic_cast<TypeIdContext *>(_tracker.createInstance<tigerIrParser::TypeIdVoidContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(125);
        match(tigerIrParser::VOID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarListContext ------------------------------------------------------------------

tigerIrParser::VarListContext::VarListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t tigerIrParser::VarListContext::getRuleIndex() const {
  return tigerIrParser::RuleVarList;
}

void tigerIrParser::VarListContext::copyFrom(VarListContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VarListEmptyContext ------------------------------------------------------------------

tigerIrParser::VarListEmptyContext::VarListEmptyContext(VarListContext *ctx) { copyFrom(ctx); }

void tigerIrParser::VarListEmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarListEmpty(this);
}
void tigerIrParser::VarListEmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarListEmpty(this);
}
//----------------- VarListExpandContext ------------------------------------------------------------------

tree::TerminalNode* tigerIrParser::VarListExpandContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}

tigerIrParser::ArrayDerefContext* tigerIrParser::VarListExpandContext::arrayDeref() {
  return getRuleContext<tigerIrParser::ArrayDerefContext>(0);
}

tree::TerminalNode* tigerIrParser::VarListExpandContext::COMMA() {
  return getToken(tigerIrParser::COMMA, 0);
}

tigerIrParser::VarListContext* tigerIrParser::VarListExpandContext::varList() {
  return getRuleContext<tigerIrParser::VarListContext>(0);
}

tigerIrParser::VarListExpandContext::VarListExpandContext(VarListContext *ctx) { copyFrom(ctx); }

void tigerIrParser::VarListExpandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarListExpand(this);
}
void tigerIrParser::VarListExpandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarListExpand(this);
}
//----------------- VarListSingleContext ------------------------------------------------------------------

tree::TerminalNode* tigerIrParser::VarListSingleContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}

tigerIrParser::ArrayDerefContext* tigerIrParser::VarListSingleContext::arrayDeref() {
  return getRuleContext<tigerIrParser::ArrayDerefContext>(0);
}

tigerIrParser::VarListSingleContext::VarListSingleContext(VarListContext *ctx) { copyFrom(ctx); }

void tigerIrParser::VarListSingleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarListSingle(this);
}
void tigerIrParser::VarListSingleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarListSingle(this);
}
tigerIrParser::VarListContext* tigerIrParser::varList() {
  VarListContext *_localctx = _tracker.createInstance<VarListContext>(_ctx, getState());
  enterRule(_localctx, 14, tigerIrParser::RuleVarList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(136);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarListContext *>(_tracker.createInstance<tigerIrParser::VarListExpandContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(128);
      match(tigerIrParser::ID);
      setState(129);
      arrayDeref();
      setState(130);
      match(tigerIrParser::COMMA);
      setState(131);
      varList();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarListContext *>(_tracker.createInstance<tigerIrParser::VarListSingleContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(133);
      match(tigerIrParser::ID);
      setState(134);
      arrayDeref();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<VarListContext *>(_tracker.createInstance<tigerIrParser::VarListEmptyContext>(_localctx));
      enterOuterAlt(_localctx, 3);

      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayDerefContext ------------------------------------------------------------------

tigerIrParser::ArrayDerefContext::ArrayDerefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t tigerIrParser::ArrayDerefContext::getRuleIndex() const {
  return tigerIrParser::RuleArrayDeref;
}

void tigerIrParser::ArrayDerefContext::copyFrom(ArrayDerefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayDerefNonemptyContext ------------------------------------------------------------------

tree::TerminalNode* tigerIrParser::ArrayDerefNonemptyContext::OPENBRACK() {
  return getToken(tigerIrParser::OPENBRACK, 0);
}

tree::TerminalNode* tigerIrParser::ArrayDerefNonemptyContext::INTLIT() {
  return getToken(tigerIrParser::INTLIT, 0);
}

tree::TerminalNode* tigerIrParser::ArrayDerefNonemptyContext::CLOSEBRACK() {
  return getToken(tigerIrParser::CLOSEBRACK, 0);
}

tigerIrParser::ArrayDerefNonemptyContext::ArrayDerefNonemptyContext(ArrayDerefContext *ctx) { copyFrom(ctx); }

void tigerIrParser::ArrayDerefNonemptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayDerefNonempty(this);
}
void tigerIrParser::ArrayDerefNonemptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayDerefNonempty(this);
}
//----------------- ArrayDerefEmptyContext ------------------------------------------------------------------

tigerIrParser::ArrayDerefEmptyContext::ArrayDerefEmptyContext(ArrayDerefContext *ctx) { copyFrom(ctx); }

void tigerIrParser::ArrayDerefEmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayDerefEmpty(this);
}
void tigerIrParser::ArrayDerefEmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayDerefEmpty(this);
}
tigerIrParser::ArrayDerefContext* tigerIrParser::arrayDeref() {
  ArrayDerefContext *_localctx = _tracker.createInstance<ArrayDerefContext>(_ctx, getState());
  enterRule(_localctx, 16, tigerIrParser::RuleArrayDeref);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(142);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case tigerIrParser::OPENBRACK: {
        _localctx = dynamic_cast<ArrayDerefContext *>(_tracker.createInstance<tigerIrParser::ArrayDerefNonemptyContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(138);
        match(tigerIrParser::OPENBRACK);
        setState(139);
        match(tigerIrParser::INTLIT);
        setState(140);
        match(tigerIrParser::CLOSEBRACK);
        break;
      }

      case tigerIrParser::COMMA:
      case tigerIrParser::NEWLINE: {
        _localctx = dynamic_cast<ArrayDerefContext *>(_tracker.createInstance<tigerIrParser::ArrayDerefEmptyContext>(_localctx));
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultipleNewlineContext ------------------------------------------------------------------

tigerIrParser::MultipleNewlineContext::MultipleNewlineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::MultipleNewlineContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}

tigerIrParser::MultipleNewlineContext* tigerIrParser::MultipleNewlineContext::multipleNewline() {
  return getRuleContext<tigerIrParser::MultipleNewlineContext>(0);
}


size_t tigerIrParser::MultipleNewlineContext::getRuleIndex() const {
  return tigerIrParser::RuleMultipleNewline;
}

void tigerIrParser::MultipleNewlineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultipleNewline(this);
}

void tigerIrParser::MultipleNewlineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultipleNewline(this);
}

tigerIrParser::MultipleNewlineContext* tigerIrParser::multipleNewline() {
  MultipleNewlineContext *_localctx = _tracker.createInstance<MultipleNewlineContext>(_ctx, getState());
  enterRule(_localctx, 18, tigerIrParser::RuleMultipleNewline);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(147);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case tigerIrParser::NEWLINE: {
        enterOuterAlt(_localctx, 1);
        setState(144);
        match(tigerIrParser::NEWLINE);
        setState(145);
        multipleNewline();
        break;
      }

      case tigerIrParser::EOF:
      case tigerIrParser::START_FUNCTION: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncBodyContext ------------------------------------------------------------------

tigerIrParser::FuncBodyContext::FuncBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::FuncBodyContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}

tree::TerminalNode* tigerIrParser::FuncBodyContext::COLON() {
  return getToken(tigerIrParser::COLON, 0);
}

tree::TerminalNode* tigerIrParser::FuncBodyContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}

tigerIrParser::StatSeqContext* tigerIrParser::FuncBodyContext::statSeq() {
  return getRuleContext<tigerIrParser::StatSeqContext>(0);
}


size_t tigerIrParser::FuncBodyContext::getRuleIndex() const {
  return tigerIrParser::RuleFuncBody;
}

void tigerIrParser::FuncBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncBody(this);
}

void tigerIrParser::FuncBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncBody(this);
}

tigerIrParser::FuncBodyContext* tigerIrParser::funcBody() {
  FuncBodyContext *_localctx = _tracker.createInstance<FuncBodyContext>(_ctx, getState());
  enterRule(_localctx, 20, tigerIrParser::RuleFuncBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    match(tigerIrParser::ID);
    setState(150);
    match(tigerIrParser::COLON);
    setState(151);
    match(tigerIrParser::NEWLINE);
    setState(152);
    statSeq();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatSeqContext ------------------------------------------------------------------

tigerIrParser::StatSeqContext::StatSeqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t tigerIrParser::StatSeqContext::getRuleIndex() const {
  return tigerIrParser::RuleStatSeq;
}

void tigerIrParser::StatSeqContext::copyFrom(StatSeqContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StatSeqNonemptyContext ------------------------------------------------------------------

tigerIrParser::StatContext* tigerIrParser::StatSeqNonemptyContext::stat() {
  return getRuleContext<tigerIrParser::StatContext>(0);
}

tigerIrParser::StatSeqContext* tigerIrParser::StatSeqNonemptyContext::statSeq() {
  return getRuleContext<tigerIrParser::StatSeqContext>(0);
}

tigerIrParser::StatSeqNonemptyContext::StatSeqNonemptyContext(StatSeqContext *ctx) { copyFrom(ctx); }

void tigerIrParser::StatSeqNonemptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatSeqNonempty(this);
}
void tigerIrParser::StatSeqNonemptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatSeqNonempty(this);
}
//----------------- StatSeqEmptyContext ------------------------------------------------------------------

tigerIrParser::StatSeqEmptyContext::StatSeqEmptyContext(StatSeqContext *ctx) { copyFrom(ctx); }

void tigerIrParser::StatSeqEmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatSeqEmpty(this);
}
void tigerIrParser::StatSeqEmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatSeqEmpty(this);
}
tigerIrParser::StatSeqContext* tigerIrParser::statSeq() {
  StatSeqContext *_localctx = _tracker.createInstance<StatSeqContext>(_ctx, getState());
  enterRule(_localctx, 22, tigerIrParser::RuleStatSeq);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case tigerIrParser::ARRAY_STORE:
      case tigerIrParser::ARRAY_LOAD:
      case tigerIrParser::ASSIGN:
      case tigerIrParser::CALL:
      case tigerIrParser::CALLR:
      case tigerIrParser::ADD:
      case tigerIrParser::SUB:
      case tigerIrParser::MULT:
      case tigerIrParser::DIV:
      case tigerIrParser::AND:
      case tigerIrParser::OR:
      case tigerIrParser::BREQ:
      case tigerIrParser::BRNEQ:
      case tigerIrParser::BRLT:
      case tigerIrParser::BRGT:
      case tigerIrParser::BRLEQ:
      case tigerIrParser::BRGEQ:
      case tigerIrParser::GOTO:
      case tigerIrParser::RETURN:
      case tigerIrParser::ID: {
        _localctx = dynamic_cast<StatSeqContext *>(_tracker.createInstance<tigerIrParser::StatSeqNonemptyContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(154);
        stat();
        setState(155);
        statSeq();
        break;
      }

      case tigerIrParser::END_FUNCTION: {
        _localctx = dynamic_cast<StatSeqContext *>(_tracker.createInstance<tigerIrParser::StatSeqEmptyContext>(_localctx));
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

tigerIrParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tigerIrParser::AssignContext* tigerIrParser::StatContext::assign() {
  return getRuleContext<tigerIrParser::AssignContext>(0);
}

tigerIrParser::AddContext* tigerIrParser::StatContext::add() {
  return getRuleContext<tigerIrParser::AddContext>(0);
}

tigerIrParser::SubContext* tigerIrParser::StatContext::sub() {
  return getRuleContext<tigerIrParser::SubContext>(0);
}

tigerIrParser::MultContext* tigerIrParser::StatContext::mult() {
  return getRuleContext<tigerIrParser::MultContext>(0);
}

tigerIrParser::DivContext* tigerIrParser::StatContext::div() {
  return getRuleContext<tigerIrParser::DivContext>(0);
}

tigerIrParser::And_opContext* tigerIrParser::StatContext::and_op() {
  return getRuleContext<tigerIrParser::And_opContext>(0);
}

tigerIrParser::Or_opContext* tigerIrParser::StatContext::or_op() {
  return getRuleContext<tigerIrParser::Or_opContext>(0);
}

tigerIrParser::Goto_opContext* tigerIrParser::StatContext::goto_op() {
  return getRuleContext<tigerIrParser::Goto_opContext>(0);
}

tigerIrParser::BreqContext* tigerIrParser::StatContext::breq() {
  return getRuleContext<tigerIrParser::BreqContext>(0);
}

tigerIrParser::BrneqContext* tigerIrParser::StatContext::brneq() {
  return getRuleContext<tigerIrParser::BrneqContext>(0);
}

tigerIrParser::BrltContext* tigerIrParser::StatContext::brlt() {
  return getRuleContext<tigerIrParser::BrltContext>(0);
}

tigerIrParser::BrgtContext* tigerIrParser::StatContext::brgt() {
  return getRuleContext<tigerIrParser::BrgtContext>(0);
}

tigerIrParser::BrleqContext* tigerIrParser::StatContext::brleq() {
  return getRuleContext<tigerIrParser::BrleqContext>(0);
}

tigerIrParser::BrgeqContext* tigerIrParser::StatContext::brgeq() {
  return getRuleContext<tigerIrParser::BrgeqContext>(0);
}

tigerIrParser::Return_voidContext* tigerIrParser::StatContext::return_void() {
  return getRuleContext<tigerIrParser::Return_voidContext>(0);
}

tigerIrParser::Return_nonvoidContext* tigerIrParser::StatContext::return_nonvoid() {
  return getRuleContext<tigerIrParser::Return_nonvoidContext>(0);
}

tigerIrParser::CallContext* tigerIrParser::StatContext::call() {
  return getRuleContext<tigerIrParser::CallContext>(0);
}

tigerIrParser::CallrContext* tigerIrParser::StatContext::callr() {
  return getRuleContext<tigerIrParser::CallrContext>(0);
}

tigerIrParser::Array_storeContext* tigerIrParser::StatContext::array_store() {
  return getRuleContext<tigerIrParser::Array_storeContext>(0);
}

tigerIrParser::Array_loadContext* tigerIrParser::StatContext::array_load() {
  return getRuleContext<tigerIrParser::Array_loadContext>(0);
}

tigerIrParser::Array_assignContext* tigerIrParser::StatContext::array_assign() {
  return getRuleContext<tigerIrParser::Array_assignContext>(0);
}

tigerIrParser::LabelContext* tigerIrParser::StatContext::label() {
  return getRuleContext<tigerIrParser::LabelContext>(0);
}


size_t tigerIrParser::StatContext::getRuleIndex() const {
  return tigerIrParser::RuleStat;
}

void tigerIrParser::StatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat(this);
}

void tigerIrParser::StatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat(this);
}

tigerIrParser::StatContext* tigerIrParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 24, tigerIrParser::RuleStat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(182);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(160);
      assign();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(161);
      add();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(162);
      sub();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(163);
      mult();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(164);
      div();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(165);
      and_op();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(166);
      or_op();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(167);
      goto_op();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(168);
      breq();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(169);
      brneq();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(170);
      brlt();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(171);
      brgt();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(172);
      brleq();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(173);
      brgeq();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(174);
      return_void();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(175);
      return_nonvoid();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(176);
      call();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(177);
      callr();
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(178);
      array_store();
      break;
    }

    case 20: {
      enterOuterAlt(_localctx, 20);
      setState(179);
      array_load();
      break;
    }

    case 21: {
      enterOuterAlt(_localctx, 21);
      setState(180);
      array_assign();
      break;
    }

    case 22: {
      enterOuterAlt(_localctx, 22);
      setState(181);
      label();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelContext ------------------------------------------------------------------

tigerIrParser::LabelContext::LabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::LabelContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}

tigerIrParser::OptionalColonContext* tigerIrParser::LabelContext::optionalColon() {
  return getRuleContext<tigerIrParser::OptionalColonContext>(0);
}

tree::TerminalNode* tigerIrParser::LabelContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::LabelContext::getRuleIndex() const {
  return tigerIrParser::RuleLabel;
}

void tigerIrParser::LabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel(this);
}

void tigerIrParser::LabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel(this);
}

tigerIrParser::LabelContext* tigerIrParser::label() {
  LabelContext *_localctx = _tracker.createInstance<LabelContext>(_ctx, getState());
  enterRule(_localctx, 26, tigerIrParser::RuleLabel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    match(tigerIrParser::ID);
    setState(185);
    optionalColon();
    setState(186);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OptionalColonContext ------------------------------------------------------------------

tigerIrParser::OptionalColonContext::OptionalColonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::OptionalColonContext::COLON() {
  return getToken(tigerIrParser::COLON, 0);
}


size_t tigerIrParser::OptionalColonContext::getRuleIndex() const {
  return tigerIrParser::RuleOptionalColon;
}

void tigerIrParser::OptionalColonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOptionalColon(this);
}

void tigerIrParser::OptionalColonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOptionalColon(this);
}

tigerIrParser::OptionalColonContext* tigerIrParser::optionalColon() {
  OptionalColonContext *_localctx = _tracker.createInstance<OptionalColonContext>(_ctx, getState());
  enterRule(_localctx, 28, tigerIrParser::RuleOptionalColon);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(190);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case tigerIrParser::COLON: {
        enterOuterAlt(_localctx, 1);
        setState(188);
        match(tigerIrParser::COLON);
        break;
      }

      case tigerIrParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

tigerIrParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::AssignContext::ASSIGN() {
  return getToken(tigerIrParser::ASSIGN, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::AssignContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::AssignContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::AssignContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::AssignContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::AssignContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::AssignContext::getRuleIndex() const {
  return tigerIrParser::RuleAssign;
}

void tigerIrParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void tigerIrParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}

tigerIrParser::AssignContext* tigerIrParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 30, tigerIrParser::RuleAssign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    match(tigerIrParser::ASSIGN);
    setState(193);
    match(tigerIrParser::COMMA);
    setState(194);
    val();
    setState(195);
    match(tigerIrParser::COMMA);
    setState(196);
    val();
    setState(197);
    match(tigerIrParser::COMMA);
    setState(198);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddContext ------------------------------------------------------------------

tigerIrParser::AddContext::AddContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::AddContext::ADD() {
  return getToken(tigerIrParser::ADD, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::AddContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::AddContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::AddContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::AddContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::AddContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::AddContext::getRuleIndex() const {
  return tigerIrParser::RuleAdd;
}

void tigerIrParser::AddContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdd(this);
}

void tigerIrParser::AddContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdd(this);
}

tigerIrParser::AddContext* tigerIrParser::add() {
  AddContext *_localctx = _tracker.createInstance<AddContext>(_ctx, getState());
  enterRule(_localctx, 32, tigerIrParser::RuleAdd);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    match(tigerIrParser::ADD);
    setState(201);
    match(tigerIrParser::COMMA);
    setState(202);
    val();
    setState(203);
    match(tigerIrParser::COMMA);
    setState(204);
    val();
    setState(205);
    match(tigerIrParser::COMMA);
    setState(206);
    val();
    setState(207);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubContext ------------------------------------------------------------------

tigerIrParser::SubContext::SubContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::SubContext::SUB() {
  return getToken(tigerIrParser::SUB, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::SubContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::SubContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::SubContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::SubContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::SubContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::SubContext::getRuleIndex() const {
  return tigerIrParser::RuleSub;
}

void tigerIrParser::SubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSub(this);
}

void tigerIrParser::SubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSub(this);
}

tigerIrParser::SubContext* tigerIrParser::sub() {
  SubContext *_localctx = _tracker.createInstance<SubContext>(_ctx, getState());
  enterRule(_localctx, 34, tigerIrParser::RuleSub);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(tigerIrParser::SUB);
    setState(210);
    match(tigerIrParser::COMMA);
    setState(211);
    val();
    setState(212);
    match(tigerIrParser::COMMA);
    setState(213);
    val();
    setState(214);
    match(tigerIrParser::COMMA);
    setState(215);
    val();
    setState(216);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultContext ------------------------------------------------------------------

tigerIrParser::MultContext::MultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::MultContext::MULT() {
  return getToken(tigerIrParser::MULT, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::MultContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::MultContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::MultContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::MultContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::MultContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::MultContext::getRuleIndex() const {
  return tigerIrParser::RuleMult;
}

void tigerIrParser::MultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMult(this);
}

void tigerIrParser::MultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMult(this);
}

tigerIrParser::MultContext* tigerIrParser::mult() {
  MultContext *_localctx = _tracker.createInstance<MultContext>(_ctx, getState());
  enterRule(_localctx, 36, tigerIrParser::RuleMult);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(tigerIrParser::MULT);
    setState(219);
    match(tigerIrParser::COMMA);
    setState(220);
    val();
    setState(221);
    match(tigerIrParser::COMMA);
    setState(222);
    val();
    setState(223);
    match(tigerIrParser::COMMA);
    setState(224);
    val();
    setState(225);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DivContext ------------------------------------------------------------------

tigerIrParser::DivContext::DivContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::DivContext::DIV() {
  return getToken(tigerIrParser::DIV, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::DivContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::DivContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::DivContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::DivContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::DivContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::DivContext::getRuleIndex() const {
  return tigerIrParser::RuleDiv;
}

void tigerIrParser::DivContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiv(this);
}

void tigerIrParser::DivContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiv(this);
}

tigerIrParser::DivContext* tigerIrParser::div() {
  DivContext *_localctx = _tracker.createInstance<DivContext>(_ctx, getState());
  enterRule(_localctx, 38, tigerIrParser::RuleDiv);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    match(tigerIrParser::DIV);
    setState(228);
    match(tigerIrParser::COMMA);
    setState(229);
    val();
    setState(230);
    match(tigerIrParser::COMMA);
    setState(231);
    val();
    setState(232);
    match(tigerIrParser::COMMA);
    setState(233);
    val();
    setState(234);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- And_opContext ------------------------------------------------------------------

tigerIrParser::And_opContext::And_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::And_opContext::AND() {
  return getToken(tigerIrParser::AND, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::And_opContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::And_opContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::And_opContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::And_opContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::And_opContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::And_opContext::getRuleIndex() const {
  return tigerIrParser::RuleAnd_op;
}

void tigerIrParser::And_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnd_op(this);
}

void tigerIrParser::And_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnd_op(this);
}

tigerIrParser::And_opContext* tigerIrParser::and_op() {
  And_opContext *_localctx = _tracker.createInstance<And_opContext>(_ctx, getState());
  enterRule(_localctx, 40, tigerIrParser::RuleAnd_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
    match(tigerIrParser::AND);
    setState(237);
    match(tigerIrParser::COMMA);
    setState(238);
    val();
    setState(239);
    match(tigerIrParser::COMMA);
    setState(240);
    val();
    setState(241);
    match(tigerIrParser::COMMA);
    setState(242);
    val();
    setState(243);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Or_opContext ------------------------------------------------------------------

tigerIrParser::Or_opContext::Or_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::Or_opContext::OR() {
  return getToken(tigerIrParser::OR, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::Or_opContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::Or_opContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::Or_opContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::Or_opContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::Or_opContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::Or_opContext::getRuleIndex() const {
  return tigerIrParser::RuleOr_op;
}

void tigerIrParser::Or_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOr_op(this);
}

void tigerIrParser::Or_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOr_op(this);
}

tigerIrParser::Or_opContext* tigerIrParser::or_op() {
  Or_opContext *_localctx = _tracker.createInstance<Or_opContext>(_ctx, getState());
  enterRule(_localctx, 42, tigerIrParser::RuleOr_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    match(tigerIrParser::OR);
    setState(246);
    match(tigerIrParser::COMMA);
    setState(247);
    val();
    setState(248);
    match(tigerIrParser::COMMA);
    setState(249);
    val();
    setState(250);
    match(tigerIrParser::COMMA);
    setState(251);
    val();
    setState(252);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Goto_opContext ------------------------------------------------------------------

tigerIrParser::Goto_opContext::Goto_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::Goto_opContext::GOTO() {
  return getToken(tigerIrParser::GOTO, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::Goto_opContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::Goto_opContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

tree::TerminalNode* tigerIrParser::Goto_opContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}

tree::TerminalNode* tigerIrParser::Goto_opContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::Goto_opContext::getRuleIndex() const {
  return tigerIrParser::RuleGoto_op;
}

void tigerIrParser::Goto_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGoto_op(this);
}

void tigerIrParser::Goto_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGoto_op(this);
}

tigerIrParser::Goto_opContext* tigerIrParser::goto_op() {
  Goto_opContext *_localctx = _tracker.createInstance<Goto_opContext>(_ctx, getState());
  enterRule(_localctx, 44, tigerIrParser::RuleGoto_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(254);
    match(tigerIrParser::GOTO);
    setState(255);
    match(tigerIrParser::COMMA);
    setState(256);
    match(tigerIrParser::ID);
    setState(257);
    match(tigerIrParser::COMMA);
    setState(258);
    match(tigerIrParser::COMMA);
    setState(259);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreqContext ------------------------------------------------------------------

tigerIrParser::BreqContext::BreqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::BreqContext::BREQ() {
  return getToken(tigerIrParser::BREQ, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::BreqContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::BreqContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::BreqContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::BreqContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::BreqContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}

tree::TerminalNode* tigerIrParser::BreqContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::BreqContext::getRuleIndex() const {
  return tigerIrParser::RuleBreq;
}

void tigerIrParser::BreqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreq(this);
}

void tigerIrParser::BreqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreq(this);
}

tigerIrParser::BreqContext* tigerIrParser::breq() {
  BreqContext *_localctx = _tracker.createInstance<BreqContext>(_ctx, getState());
  enterRule(_localctx, 46, tigerIrParser::RuleBreq);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    match(tigerIrParser::BREQ);
    setState(262);
    match(tigerIrParser::COMMA);
    setState(263);
    val();
    setState(264);
    match(tigerIrParser::COMMA);
    setState(265);
    val();
    setState(266);
    match(tigerIrParser::COMMA);
    setState(267);
    match(tigerIrParser::ID);
    setState(268);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BrneqContext ------------------------------------------------------------------

tigerIrParser::BrneqContext::BrneqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::BrneqContext::BRNEQ() {
  return getToken(tigerIrParser::BRNEQ, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::BrneqContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::BrneqContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::BrneqContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::BrneqContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::BrneqContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}

tree::TerminalNode* tigerIrParser::BrneqContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::BrneqContext::getRuleIndex() const {
  return tigerIrParser::RuleBrneq;
}

void tigerIrParser::BrneqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBrneq(this);
}

void tigerIrParser::BrneqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBrneq(this);
}

tigerIrParser::BrneqContext* tigerIrParser::brneq() {
  BrneqContext *_localctx = _tracker.createInstance<BrneqContext>(_ctx, getState());
  enterRule(_localctx, 48, tigerIrParser::RuleBrneq);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(270);
    match(tigerIrParser::BRNEQ);
    setState(271);
    match(tigerIrParser::COMMA);
    setState(272);
    val();
    setState(273);
    match(tigerIrParser::COMMA);
    setState(274);
    val();
    setState(275);
    match(tigerIrParser::COMMA);
    setState(276);
    match(tigerIrParser::ID);
    setState(277);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BrltContext ------------------------------------------------------------------

tigerIrParser::BrltContext::BrltContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::BrltContext::BRLT() {
  return getToken(tigerIrParser::BRLT, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::BrltContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::BrltContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::BrltContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::BrltContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::BrltContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}

tree::TerminalNode* tigerIrParser::BrltContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::BrltContext::getRuleIndex() const {
  return tigerIrParser::RuleBrlt;
}

void tigerIrParser::BrltContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBrlt(this);
}

void tigerIrParser::BrltContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBrlt(this);
}

tigerIrParser::BrltContext* tigerIrParser::brlt() {
  BrltContext *_localctx = _tracker.createInstance<BrltContext>(_ctx, getState());
  enterRule(_localctx, 50, tigerIrParser::RuleBrlt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    match(tigerIrParser::BRLT);
    setState(280);
    match(tigerIrParser::COMMA);
    setState(281);
    val();
    setState(282);
    match(tigerIrParser::COMMA);
    setState(283);
    val();
    setState(284);
    match(tigerIrParser::COMMA);
    setState(285);
    match(tigerIrParser::ID);
    setState(286);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BrgtContext ------------------------------------------------------------------

tigerIrParser::BrgtContext::BrgtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::BrgtContext::BRGT() {
  return getToken(tigerIrParser::BRGT, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::BrgtContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::BrgtContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::BrgtContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::BrgtContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::BrgtContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}

tree::TerminalNode* tigerIrParser::BrgtContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::BrgtContext::getRuleIndex() const {
  return tigerIrParser::RuleBrgt;
}

void tigerIrParser::BrgtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBrgt(this);
}

void tigerIrParser::BrgtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBrgt(this);
}

tigerIrParser::BrgtContext* tigerIrParser::brgt() {
  BrgtContext *_localctx = _tracker.createInstance<BrgtContext>(_ctx, getState());
  enterRule(_localctx, 52, tigerIrParser::RuleBrgt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    match(tigerIrParser::BRGT);
    setState(289);
    match(tigerIrParser::COMMA);
    setState(290);
    val();
    setState(291);
    match(tigerIrParser::COMMA);
    setState(292);
    val();
    setState(293);
    match(tigerIrParser::COMMA);
    setState(294);
    match(tigerIrParser::ID);
    setState(295);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BrleqContext ------------------------------------------------------------------

tigerIrParser::BrleqContext::BrleqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::BrleqContext::BRLEQ() {
  return getToken(tigerIrParser::BRLEQ, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::BrleqContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::BrleqContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::BrleqContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::BrleqContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::BrleqContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}

tree::TerminalNode* tigerIrParser::BrleqContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::BrleqContext::getRuleIndex() const {
  return tigerIrParser::RuleBrleq;
}

void tigerIrParser::BrleqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBrleq(this);
}

void tigerIrParser::BrleqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBrleq(this);
}

tigerIrParser::BrleqContext* tigerIrParser::brleq() {
  BrleqContext *_localctx = _tracker.createInstance<BrleqContext>(_ctx, getState());
  enterRule(_localctx, 54, tigerIrParser::RuleBrleq);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(tigerIrParser::BRLEQ);
    setState(298);
    match(tigerIrParser::COMMA);
    setState(299);
    val();
    setState(300);
    match(tigerIrParser::COMMA);
    setState(301);
    val();
    setState(302);
    match(tigerIrParser::COMMA);
    setState(303);
    match(tigerIrParser::ID);
    setState(304);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BrgeqContext ------------------------------------------------------------------

tigerIrParser::BrgeqContext::BrgeqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::BrgeqContext::BRGEQ() {
  return getToken(tigerIrParser::BRGEQ, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::BrgeqContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::BrgeqContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::BrgeqContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::BrgeqContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::BrgeqContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}

tree::TerminalNode* tigerIrParser::BrgeqContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::BrgeqContext::getRuleIndex() const {
  return tigerIrParser::RuleBrgeq;
}

void tigerIrParser::BrgeqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBrgeq(this);
}

void tigerIrParser::BrgeqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBrgeq(this);
}

tigerIrParser::BrgeqContext* tigerIrParser::brgeq() {
  BrgeqContext *_localctx = _tracker.createInstance<BrgeqContext>(_ctx, getState());
  enterRule(_localctx, 56, tigerIrParser::RuleBrgeq);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    match(tigerIrParser::BRGEQ);
    setState(307);
    match(tigerIrParser::COMMA);
    setState(308);
    val();
    setState(309);
    match(tigerIrParser::COMMA);
    setState(310);
    val();
    setState(311);
    match(tigerIrParser::COMMA);
    setState(312);
    match(tigerIrParser::ID);
    setState(313);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_voidContext ------------------------------------------------------------------

tigerIrParser::Return_voidContext::Return_voidContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::Return_voidContext::RETURN() {
  return getToken(tigerIrParser::RETURN, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::Return_voidContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::Return_voidContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

tree::TerminalNode* tigerIrParser::Return_voidContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::Return_voidContext::getRuleIndex() const {
  return tigerIrParser::RuleReturn_void;
}

void tigerIrParser::Return_voidContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_void(this);
}

void tigerIrParser::Return_voidContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_void(this);
}

tigerIrParser::Return_voidContext* tigerIrParser::return_void() {
  Return_voidContext *_localctx = _tracker.createInstance<Return_voidContext>(_ctx, getState());
  enterRule(_localctx, 58, tigerIrParser::RuleReturn_void);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(315);
    match(tigerIrParser::RETURN);
    setState(316);
    match(tigerIrParser::COMMA);
    setState(317);
    match(tigerIrParser::COMMA);
    setState(318);
    match(tigerIrParser::COMMA);
    setState(319);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_nonvoidContext ------------------------------------------------------------------

tigerIrParser::Return_nonvoidContext::Return_nonvoidContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::Return_nonvoidContext::RETURN() {
  return getToken(tigerIrParser::RETURN, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::Return_nonvoidContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::Return_nonvoidContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

tigerIrParser::ValContext* tigerIrParser::Return_nonvoidContext::val() {
  return getRuleContext<tigerIrParser::ValContext>(0);
}

tree::TerminalNode* tigerIrParser::Return_nonvoidContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::Return_nonvoidContext::getRuleIndex() const {
  return tigerIrParser::RuleReturn_nonvoid;
}

void tigerIrParser::Return_nonvoidContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_nonvoid(this);
}

void tigerIrParser::Return_nonvoidContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_nonvoid(this);
}

tigerIrParser::Return_nonvoidContext* tigerIrParser::return_nonvoid() {
  Return_nonvoidContext *_localctx = _tracker.createInstance<Return_nonvoidContext>(_ctx, getState());
  enterRule(_localctx, 60, tigerIrParser::RuleReturn_nonvoid);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    match(tigerIrParser::RETURN);
    setState(322);
    match(tigerIrParser::COMMA);
    setState(323);
    val();
    setState(324);
    match(tigerIrParser::COMMA);
    setState(325);
    match(tigerIrParser::COMMA);
    setState(326);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallContext ------------------------------------------------------------------

tigerIrParser::CallContext::CallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::CallContext::CALL() {
  return getToken(tigerIrParser::CALL, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::CallContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::CallContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

tree::TerminalNode* tigerIrParser::CallContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}

tigerIrParser::ExprListContext* tigerIrParser::CallContext::exprList() {
  return getRuleContext<tigerIrParser::ExprListContext>(0);
}

tree::TerminalNode* tigerIrParser::CallContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::CallContext::getRuleIndex() const {
  return tigerIrParser::RuleCall;
}

void tigerIrParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}

void tigerIrParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}

tigerIrParser::CallContext* tigerIrParser::call() {
  CallContext *_localctx = _tracker.createInstance<CallContext>(_ctx, getState());
  enterRule(_localctx, 62, tigerIrParser::RuleCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    match(tigerIrParser::CALL);
    setState(329);
    match(tigerIrParser::COMMA);
    setState(330);
    match(tigerIrParser::ID);
    setState(331);
    match(tigerIrParser::COMMA);
    setState(332);
    exprList();
    setState(333);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallrContext ------------------------------------------------------------------

tigerIrParser::CallrContext::CallrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::CallrContext::CALLR() {
  return getToken(tigerIrParser::CALLR, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::CallrContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::CallrContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

tigerIrParser::ValContext* tigerIrParser::CallrContext::val() {
  return getRuleContext<tigerIrParser::ValContext>(0);
}

tree::TerminalNode* tigerIrParser::CallrContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}

tigerIrParser::ExprListContext* tigerIrParser::CallrContext::exprList() {
  return getRuleContext<tigerIrParser::ExprListContext>(0);
}

tree::TerminalNode* tigerIrParser::CallrContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::CallrContext::getRuleIndex() const {
  return tigerIrParser::RuleCallr;
}

void tigerIrParser::CallrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallr(this);
}

void tigerIrParser::CallrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallr(this);
}

tigerIrParser::CallrContext* tigerIrParser::callr() {
  CallrContext *_localctx = _tracker.createInstance<CallrContext>(_ctx, getState());
  enterRule(_localctx, 64, tigerIrParser::RuleCallr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    match(tigerIrParser::CALLR);
    setState(336);
    match(tigerIrParser::COMMA);
    setState(337);
    val();
    setState(338);
    match(tigerIrParser::COMMA);
    setState(339);
    match(tigerIrParser::ID);
    setState(340);
    match(tigerIrParser::COMMA);
    setState(341);
    exprList();
    setState(342);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_storeContext ------------------------------------------------------------------

tigerIrParser::Array_storeContext::Array_storeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::Array_storeContext::ARRAY_STORE() {
  return getToken(tigerIrParser::ARRAY_STORE, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::Array_storeContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::Array_storeContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::Array_storeContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::Array_storeContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::Array_storeContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::Array_storeContext::getRuleIndex() const {
  return tigerIrParser::RuleArray_store;
}

void tigerIrParser::Array_storeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_store(this);
}

void tigerIrParser::Array_storeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_store(this);
}

tigerIrParser::Array_storeContext* tigerIrParser::array_store() {
  Array_storeContext *_localctx = _tracker.createInstance<Array_storeContext>(_ctx, getState());
  enterRule(_localctx, 66, tigerIrParser::RuleArray_store);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(344);
    match(tigerIrParser::ARRAY_STORE);
    setState(345);
    match(tigerIrParser::COMMA);
    setState(346);
    val();
    setState(347);
    match(tigerIrParser::COMMA);
    setState(348);
    val();
    setState(349);
    match(tigerIrParser::COMMA);
    setState(350);
    val();
    setState(351);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_loadContext ------------------------------------------------------------------

tigerIrParser::Array_loadContext::Array_loadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::Array_loadContext::ARRAY_LOAD() {
  return getToken(tigerIrParser::ARRAY_LOAD, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::Array_loadContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::Array_loadContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::Array_loadContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::Array_loadContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::Array_loadContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::Array_loadContext::getRuleIndex() const {
  return tigerIrParser::RuleArray_load;
}

void tigerIrParser::Array_loadContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_load(this);
}

void tigerIrParser::Array_loadContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_load(this);
}

tigerIrParser::Array_loadContext* tigerIrParser::array_load() {
  Array_loadContext *_localctx = _tracker.createInstance<Array_loadContext>(_ctx, getState());
  enterRule(_localctx, 68, tigerIrParser::RuleArray_load);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
    match(tigerIrParser::ARRAY_LOAD);
    setState(354);
    match(tigerIrParser::COMMA);
    setState(355);
    val();
    setState(356);
    match(tigerIrParser::COMMA);
    setState(357);
    val();
    setState(358);
    match(tigerIrParser::COMMA);
    setState(359);
    val();
    setState(360);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_assignContext ------------------------------------------------------------------

tigerIrParser::Array_assignContext::Array_assignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::Array_assignContext::ASSIGN() {
  return getToken(tigerIrParser::ASSIGN, 0);
}

std::vector<tree::TerminalNode *> tigerIrParser::Array_assignContext::COMMA() {
  return getTokens(tigerIrParser::COMMA);
}

tree::TerminalNode* tigerIrParser::Array_assignContext::COMMA(size_t i) {
  return getToken(tigerIrParser::COMMA, i);
}

std::vector<tigerIrParser::ValContext *> tigerIrParser::Array_assignContext::val() {
  return getRuleContexts<tigerIrParser::ValContext>();
}

tigerIrParser::ValContext* tigerIrParser::Array_assignContext::val(size_t i) {
  return getRuleContext<tigerIrParser::ValContext>(i);
}

tree::TerminalNode* tigerIrParser::Array_assignContext::NEWLINE() {
  return getToken(tigerIrParser::NEWLINE, 0);
}


size_t tigerIrParser::Array_assignContext::getRuleIndex() const {
  return tigerIrParser::RuleArray_assign;
}

void tigerIrParser::Array_assignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_assign(this);
}

void tigerIrParser::Array_assignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_assign(this);
}

tigerIrParser::Array_assignContext* tigerIrParser::array_assign() {
  Array_assignContext *_localctx = _tracker.createInstance<Array_assignContext>(_ctx, getState());
  enterRule(_localctx, 70, tigerIrParser::RuleArray_assign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    match(tigerIrParser::ASSIGN);
    setState(363);
    match(tigerIrParser::COMMA);
    setState(364);
    val();
    setState(365);
    match(tigerIrParser::COMMA);
    setState(366);
    val();
    setState(367);
    match(tigerIrParser::COMMA);
    setState(368);
    val();
    setState(369);
    match(tigerIrParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprListContext ------------------------------------------------------------------

tigerIrParser::ExprListContext::ExprListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t tigerIrParser::ExprListContext::getRuleIndex() const {
  return tigerIrParser::RuleExprList;
}

void tigerIrParser::ExprListContext::copyFrom(ExprListContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprListContinueContext ------------------------------------------------------------------

tigerIrParser::ValContext* tigerIrParser::ExprListContinueContext::val() {
  return getRuleContext<tigerIrParser::ValContext>(0);
}

tree::TerminalNode* tigerIrParser::ExprListContinueContext::COMMA() {
  return getToken(tigerIrParser::COMMA, 0);
}

tigerIrParser::ExprListContext* tigerIrParser::ExprListContinueContext::exprList() {
  return getRuleContext<tigerIrParser::ExprListContext>(0);
}

tigerIrParser::OptionalCommaContext* tigerIrParser::ExprListContinueContext::optionalComma() {
  return getRuleContext<tigerIrParser::OptionalCommaContext>(0);
}

tigerIrParser::ExprListContinueContext::ExprListContinueContext(ExprListContext *ctx) { copyFrom(ctx); }

void tigerIrParser::ExprListContinueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprListContinue(this);
}
void tigerIrParser::ExprListContinueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprListContinue(this);
}
//----------------- ExprListSingleContext ------------------------------------------------------------------

tigerIrParser::ValContext* tigerIrParser::ExprListSingleContext::val() {
  return getRuleContext<tigerIrParser::ValContext>(0);
}

tigerIrParser::ExprListSingleContext::ExprListSingleContext(ExprListContext *ctx) { copyFrom(ctx); }

void tigerIrParser::ExprListSingleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprListSingle(this);
}
void tigerIrParser::ExprListSingleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprListSingle(this);
}
//----------------- ExprListEmptyContext ------------------------------------------------------------------

tigerIrParser::ExprListEmptyContext::ExprListEmptyContext(ExprListContext *ctx) { copyFrom(ctx); }

void tigerIrParser::ExprListEmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprListEmpty(this);
}
void tigerIrParser::ExprListEmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprListEmpty(this);
}
tigerIrParser::ExprListContext* tigerIrParser::exprList() {
  ExprListContext *_localctx = _tracker.createInstance<ExprListContext>(_ctx, getState());
  enterRule(_localctx, 72, tigerIrParser::RuleExprList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(378);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ExprListContext *>(_tracker.createInstance<tigerIrParser::ExprListContinueContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(371);
      val();
      setState(372);
      match(tigerIrParser::COMMA);
      setState(373);
      exprList();
      setState(374);
      optionalComma();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ExprListContext *>(_tracker.createInstance<tigerIrParser::ExprListSingleContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(376);
      val();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<ExprListContext *>(_tracker.createInstance<tigerIrParser::ExprListEmptyContext>(_localctx));
      enterOuterAlt(_localctx, 3);

      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OptionalCommaContext ------------------------------------------------------------------

tigerIrParser::OptionalCommaContext::OptionalCommaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* tigerIrParser::OptionalCommaContext::COMMA() {
  return getToken(tigerIrParser::COMMA, 0);
}


size_t tigerIrParser::OptionalCommaContext::getRuleIndex() const {
  return tigerIrParser::RuleOptionalComma;
}

void tigerIrParser::OptionalCommaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOptionalComma(this);
}

void tigerIrParser::OptionalCommaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOptionalComma(this);
}

tigerIrParser::OptionalCommaContext* tigerIrParser::optionalComma() {
  OptionalCommaContext *_localctx = _tracker.createInstance<OptionalCommaContext>(_ctx, getState());
  enterRule(_localctx, 74, tigerIrParser::RuleOptionalComma);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(382);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(380);
      match(tigerIrParser::COMMA);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValContext ------------------------------------------------------------------

tigerIrParser::ValContext::ValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t tigerIrParser::ValContext::getRuleIndex() const {
  return tigerIrParser::RuleVal;
}

void tigerIrParser::ValContext::copyFrom(ValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ValIdContext ------------------------------------------------------------------

tree::TerminalNode* tigerIrParser::ValIdContext::ID() {
  return getToken(tigerIrParser::ID, 0);
}

tigerIrParser::ValIdContext::ValIdContext(ValContext *ctx) { copyFrom(ctx); }

void tigerIrParser::ValIdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValId(this);
}
void tigerIrParser::ValIdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValId(this);
}
//----------------- ValIntLitContext ------------------------------------------------------------------

tree::TerminalNode* tigerIrParser::ValIntLitContext::INTLIT() {
  return getToken(tigerIrParser::INTLIT, 0);
}

tigerIrParser::ValIntLitContext::ValIntLitContext(ValContext *ctx) { copyFrom(ctx); }

void tigerIrParser::ValIntLitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValIntLit(this);
}
void tigerIrParser::ValIntLitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValIntLit(this);
}
//----------------- ValFloatLitContext ------------------------------------------------------------------

tree::TerminalNode* tigerIrParser::ValFloatLitContext::FLOATLIT() {
  return getToken(tigerIrParser::FLOATLIT, 0);
}

tigerIrParser::ValFloatLitContext::ValFloatLitContext(ValContext *ctx) { copyFrom(ctx); }

void tigerIrParser::ValFloatLitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValFloatLit(this);
}
void tigerIrParser::ValFloatLitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<tigerIrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValFloatLit(this);
}
tigerIrParser::ValContext* tigerIrParser::val() {
  ValContext *_localctx = _tracker.createInstance<ValContext>(_ctx, getState());
  enterRule(_localctx, 76, tigerIrParser::RuleVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(387);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case tigerIrParser::ID: {
        _localctx = dynamic_cast<ValContext *>(_tracker.createInstance<tigerIrParser::ValIdContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(384);
        match(tigerIrParser::ID);
        break;
      }

      case tigerIrParser::INTLIT: {
        _localctx = dynamic_cast<ValContext *>(_tracker.createInstance<tigerIrParser::ValIntLitContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(385);
        match(tigerIrParser::INTLIT);
        break;
      }

      case tigerIrParser::FLOATLIT: {
        _localctx = dynamic_cast<ValContext *>(_tracker.createInstance<tigerIrParser::ValFloatLitContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(386);
        match(tigerIrParser::FLOATLIT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> tigerIrParser::_decisionToDFA;
atn::PredictionContextCache tigerIrParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN tigerIrParser::_atn;
std::vector<uint16_t> tigerIrParser::_serializedATN;

std::vector<std::string> tigerIrParser::_ruleNames = {
  "irProgram", "functionSeq", "function", "paramList", "paramListTail", 
  "param", "typeId", "varList", "arrayDeref", "multipleNewline", "funcBody", 
  "statSeq", "stat", "label", "optionalColon", "assign", "add", "sub", "mult", 
  "div", "and_op", "or_op", "goto_op", "breq", "brneq", "brlt", "brgt", 
  "brleq", "brgeq", "return_void", "return_nonvoid", "call", "callr", "array_store", 
  "array_load", "array_assign", "exprList", "optionalComma", "val"
};

std::vector<std::string> tigerIrParser::_literalNames = {
  "", "'array_store'", "'array_load'", "'assign'", "'call'", "'callr'", 
  "'add'", "'sub'", "'mult'", "'div'", "'and'", "'or'", "'breq'", "'brneq'", 
  "'brlt'", "'brgt'", "'brleq'", "'brgeq'", "'goto'", "'return'", "'float'", 
  "'int'", "'void'", "'int-list:'", "'float-list:'", "','", "':'", "';'", 
  "'('", "')'", "'['", "']'", "'{'", "'}'", "'\n'", "'#start_function'", 
  "'#end_function'"
};

std::vector<std::string> tigerIrParser::_symbolicNames = {
  "", "ARRAY_STORE", "ARRAY_LOAD", "ASSIGN", "CALL", "CALLR", "ADD", "SUB", 
  "MULT", "DIV", "AND", "OR", "BREQ", "BRNEQ", "BRLT", "BRGT", "BRLEQ", 
  "BRGEQ", "GOTO", "RETURN", "FLOAT", "INT", "VOID", "INT_LIST", "FLOAT_LIST", 
  "COMMA", "COLON", "SEMICOLON", "OPENPAREN", "CLOSEPAREN", "OPENBRACK", 
  "CLOSEBRACK", "OPENCURLY", "CLOSECURLY", "NEWLINE", "START_FUNCTION", 
  "END_FUNCTION", "ID", "INTLIT", "FLOATLIT", "WS"
};

dfa::Vocabulary tigerIrParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> tigerIrParser::_tokenNames;

tigerIrParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2a, 0x188, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x58, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x72, 
    0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 
    0x79, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x5, 0x8, 0x81, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x8b, 0xa, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x91, 0xa, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x96, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0xa1, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xb9, 0xa, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xc1, 0xa, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 
    0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x17d, 
    0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x181, 0xa, 0x27, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x186, 0xa, 0x28, 0x3, 0x28, 0x2, 0x2, 
    0x29, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
    0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 
    0x4a, 0x4c, 0x4e, 0x2, 0x2, 0x2, 0x185, 0x2, 0x50, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x57, 0x3, 0x2, 0x2, 0x2, 0x6, 0x59, 0x3, 0x2, 0x2, 0x2, 0x8, 0x71, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x78, 0x3, 0x2, 0x2, 0x2, 0xc, 0x7a, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x80, 0x3, 0x2, 0x2, 0x2, 0x10, 0x8a, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x90, 0x3, 0x2, 0x2, 0x2, 0x14, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x97, 0x3, 0x2, 0x2, 0x2, 0x18, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xb8, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xba, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xc2, 0x3, 0x2, 0x2, 0x2, 0x22, 0xca, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x26, 0xdc, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xee, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x100, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x107, 0x3, 0x2, 0x2, 0x2, 0x32, 0x110, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x119, 0x3, 0x2, 0x2, 0x2, 0x36, 0x122, 0x3, 0x2, 0x2, 0x2, 0x38, 0x12b, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x134, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x13d, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x143, 0x3, 0x2, 0x2, 0x2, 0x40, 0x14a, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x151, 0x3, 0x2, 0x2, 0x2, 0x44, 0x15a, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x163, 0x3, 0x2, 0x2, 0x2, 0x48, 0x16c, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x180, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x185, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x5, 0x6, 0x4, 0x2, 0x51, 0x52, 
    0x5, 0x4, 0x3, 0x2, 0x52, 0x3, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x5, 
    0x6, 0x4, 0x2, 0x54, 0x55, 0x5, 0x4, 0x3, 0x2, 0x55, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x58, 0x3, 0x2, 0x2, 0x2, 0x57, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x59, 0x5a, 0x7, 0x25, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x27, 0x2, 0x2, 0x5b, 
    0x5c, 0x7, 0x24, 0x2, 0x2, 0x5c, 0x5d, 0x5, 0xe, 0x8, 0x2, 0x5d, 0x5e, 
    0x7, 0x27, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x1e, 0x2, 0x2, 0x5f, 0x60, 0x5, 
    0x8, 0x5, 0x2, 0x60, 0x61, 0x7, 0x1f, 0x2, 0x2, 0x61, 0x62, 0x7, 0x24, 
    0x2, 0x2, 0x62, 0x63, 0x7, 0x19, 0x2, 0x2, 0x63, 0x64, 0x5, 0x10, 0x9, 
    0x2, 0x64, 0x65, 0x7, 0x24, 0x2, 0x2, 0x65, 0x66, 0x7, 0x1a, 0x2, 0x2, 
    0x66, 0x67, 0x5, 0x10, 0x9, 0x2, 0x67, 0x68, 0x7, 0x24, 0x2, 0x2, 0x68, 
    0x69, 0x5, 0x16, 0xc, 0x2, 0x69, 0x6a, 0x7, 0x26, 0x2, 0x2, 0x6a, 0x6b, 
    0x7, 0x27, 0x2, 0x2, 0x6b, 0x6c, 0x5, 0x14, 0xb, 0x2, 0x6c, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x6d, 0x6e, 0x5, 0xc, 0x7, 0x2, 0x6e, 0x6f, 0x5, 0xa, 
    0x6, 0x2, 0x6f, 0x72, 0x3, 0x2, 0x2, 0x2, 0x70, 0x72, 0x3, 0x2, 0x2, 
    0x2, 0x71, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x71, 0x70, 0x3, 0x2, 0x2, 0x2, 
    0x72, 0x9, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x7, 0x1b, 0x2, 0x2, 0x74, 
    0x75, 0x5, 0xc, 0x7, 0x2, 0x75, 0x76, 0x5, 0xa, 0x6, 0x2, 0x76, 0x79, 
    0x3, 0x2, 0x2, 0x2, 0x77, 0x79, 0x3, 0x2, 0x2, 0x2, 0x78, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x7b, 0x5, 0xe, 0x8, 0x2, 0x7b, 0x7c, 0x7, 0x27, 0x2, 
    0x2, 0x7c, 0xd, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x81, 0x7, 0x17, 0x2, 0x2, 
    0x7e, 0x81, 0x7, 0x16, 0x2, 0x2, 0x7f, 0x81, 0x7, 0x18, 0x2, 0x2, 0x80, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7f, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0xf, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x7, 
    0x27, 0x2, 0x2, 0x83, 0x84, 0x5, 0x12, 0xa, 0x2, 0x84, 0x85, 0x7, 0x1b, 
    0x2, 0x2, 0x85, 0x86, 0x5, 0x10, 0x9, 0x2, 0x86, 0x8b, 0x3, 0x2, 0x2, 
    0x2, 0x87, 0x88, 0x7, 0x27, 0x2, 0x2, 0x88, 0x8b, 0x5, 0x12, 0xa, 0x2, 
    0x89, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x82, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x87, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x20, 0x2, 0x2, 0x8d, 0x8e, 0x7, 
    0x28, 0x2, 0x2, 0x8e, 0x91, 0x7, 0x21, 0x2, 0x2, 0x8f, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x90, 0x8f, 0x3, 0x2, 0x2, 
    0x2, 0x91, 0x13, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x24, 0x2, 0x2, 
    0x93, 0x96, 0x5, 0x14, 0xb, 0x2, 0x94, 0x96, 0x3, 0x2, 0x2, 0x2, 0x95, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0x95, 0x94, 0x3, 0x2, 0x2, 0x2, 0x96, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x7, 0x27, 0x2, 0x2, 0x98, 0x99, 0x7, 
    0x1c, 0x2, 0x2, 0x99, 0x9a, 0x7, 0x24, 0x2, 0x2, 0x9a, 0x9b, 0x5, 0x18, 
    0xd, 0x2, 0x9b, 0x17, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x5, 0x1a, 0xe, 
    0x2, 0x9d, 0x9e, 0x5, 0x18, 0xd, 0x2, 0x9e, 0xa1, 0x3, 0x2, 0x2, 0x2, 
    0x9f, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa0, 
    0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x19, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xb9, 
    0x5, 0x20, 0x11, 0x2, 0xa3, 0xb9, 0x5, 0x22, 0x12, 0x2, 0xa4, 0xb9, 
    0x5, 0x24, 0x13, 0x2, 0xa5, 0xb9, 0x5, 0x26, 0x14, 0x2, 0xa6, 0xb9, 
    0x5, 0x28, 0x15, 0x2, 0xa7, 0xb9, 0x5, 0x2a, 0x16, 0x2, 0xa8, 0xb9, 
    0x5, 0x2c, 0x17, 0x2, 0xa9, 0xb9, 0x5, 0x2e, 0x18, 0x2, 0xaa, 0xb9, 
    0x5, 0x30, 0x19, 0x2, 0xab, 0xb9, 0x5, 0x32, 0x1a, 0x2, 0xac, 0xb9, 
    0x5, 0x34, 0x1b, 0x2, 0xad, 0xb9, 0x5, 0x36, 0x1c, 0x2, 0xae, 0xb9, 
    0x5, 0x38, 0x1d, 0x2, 0xaf, 0xb9, 0x5, 0x3a, 0x1e, 0x2, 0xb0, 0xb9, 
    0x5, 0x3c, 0x1f, 0x2, 0xb1, 0xb9, 0x5, 0x3e, 0x20, 0x2, 0xb2, 0xb9, 
    0x5, 0x40, 0x21, 0x2, 0xb3, 0xb9, 0x5, 0x42, 0x22, 0x2, 0xb4, 0xb9, 
    0x5, 0x44, 0x23, 0x2, 0xb5, 0xb9, 0x5, 0x46, 0x24, 0x2, 0xb6, 0xb9, 
    0x5, 0x48, 0x25, 0x2, 0xb7, 0xb9, 0x5, 0x1c, 0xf, 0x2, 0xb8, 0xa2, 0x3, 
    0x2, 0x2, 0x2, 0xb8, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xa4, 0x3, 0x2, 
    0x2, 0x2, 0xb8, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xa6, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xa8, 0x3, 0x2, 0x2, 0x2, 
    0xb8, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xb8, 
    0xab, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xac, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xad, 
    0x3, 0x2, 0x2, 0x2, 0xb8, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xaf, 0x3, 
    0x2, 0x2, 0x2, 0xb8, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb1, 0x3, 0x2, 
    0x2, 0x2, 0xb8, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb3, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb5, 0x3, 0x2, 0x2, 0x2, 
    0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x27, 0x2, 0x2, 0xbb, 0xbc, 
    0x5, 0x1e, 0x10, 0x2, 0xbc, 0xbd, 0x7, 0x24, 0x2, 0x2, 0xbd, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0xbe, 0xc1, 0x7, 0x1c, 0x2, 0x2, 0xbf, 0xc1, 0x3, 0x2, 
    0x2, 0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbf, 0x3, 0x2, 0x2, 
    0x2, 0xc1, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x7, 0x5, 0x2, 0x2, 
    0xc3, 0xc4, 0x7, 0x1b, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x4e, 0x28, 0x2, 0xc5, 
    0xc6, 0x7, 0x1b, 0x2, 0x2, 0xc6, 0xc7, 0x5, 0x4e, 0x28, 0x2, 0xc7, 0xc8, 
    0x7, 0x1b, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x24, 0x2, 0x2, 0xc9, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x8, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x1b, 
    0x2, 0x2, 0xcc, 0xcd, 0x5, 0x4e, 0x28, 0x2, 0xcd, 0xce, 0x7, 0x1b, 0x2, 
    0x2, 0xce, 0xcf, 0x5, 0x4e, 0x28, 0x2, 0xcf, 0xd0, 0x7, 0x1b, 0x2, 0x2, 
    0xd0, 0xd1, 0x5, 0x4e, 0x28, 0x2, 0xd1, 0xd2, 0x7, 0x24, 0x2, 0x2, 0xd2, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x9, 0x2, 0x2, 0xd4, 0xd5, 
    0x7, 0x1b, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x4e, 0x28, 0x2, 0xd6, 0xd7, 0x7, 
    0x1b, 0x2, 0x2, 0xd7, 0xd8, 0x5, 0x4e, 0x28, 0x2, 0xd8, 0xd9, 0x7, 0x1b, 
    0x2, 0x2, 0xd9, 0xda, 0x5, 0x4e, 0x28, 0x2, 0xda, 0xdb, 0x7, 0x24, 0x2, 
    0x2, 0xdb, 0x25, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0xa, 0x2, 0x2, 
    0xdd, 0xde, 0x7, 0x1b, 0x2, 0x2, 0xde, 0xdf, 0x5, 0x4e, 0x28, 0x2, 0xdf, 
    0xe0, 0x7, 0x1b, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0x4e, 0x28, 0x2, 0xe1, 0xe2, 
    0x7, 0x1b, 0x2, 0x2, 0xe2, 0xe3, 0x5, 0x4e, 0x28, 0x2, 0xe3, 0xe4, 0x7, 
    0x24, 0x2, 0x2, 0xe4, 0x27, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0xb, 
    0x2, 0x2, 0xe6, 0xe7, 0x7, 0x1b, 0x2, 0x2, 0xe7, 0xe8, 0x5, 0x4e, 0x28, 
    0x2, 0xe8, 0xe9, 0x7, 0x1b, 0x2, 0x2, 0xe9, 0xea, 0x5, 0x4e, 0x28, 0x2, 
    0xea, 0xeb, 0x7, 0x1b, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x4e, 0x28, 0x2, 0xec, 
    0xed, 0x7, 0x24, 0x2, 0x2, 0xed, 0x29, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 
    0x7, 0xc, 0x2, 0x2, 0xef, 0xf0, 0x7, 0x1b, 0x2, 0x2, 0xf0, 0xf1, 0x5, 
    0x4e, 0x28, 0x2, 0xf1, 0xf2, 0x7, 0x1b, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x4e, 
    0x28, 0x2, 0xf3, 0xf4, 0x7, 0x1b, 0x2, 0x2, 0xf4, 0xf5, 0x5, 0x4e, 0x28, 
    0x2, 0xf5, 0xf6, 0x7, 0x24, 0x2, 0x2, 0xf6, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0xf7, 0xf8, 0x7, 0xd, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x1b, 0x2, 0x2, 0xf9, 
    0xfa, 0x5, 0x4e, 0x28, 0x2, 0xfa, 0xfb, 0x7, 0x1b, 0x2, 0x2, 0xfb, 0xfc, 
    0x5, 0x4e, 0x28, 0x2, 0xfc, 0xfd, 0x7, 0x1b, 0x2, 0x2, 0xfd, 0xfe, 0x5, 
    0x4e, 0x28, 0x2, 0xfe, 0xff, 0x7, 0x24, 0x2, 0x2, 0xff, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x100, 0x101, 0x7, 0x14, 0x2, 0x2, 0x101, 0x102, 0x7, 0x1b, 
    0x2, 0x2, 0x102, 0x103, 0x7, 0x27, 0x2, 0x2, 0x103, 0x104, 0x7, 0x1b, 
    0x2, 0x2, 0x104, 0x105, 0x7, 0x1b, 0x2, 0x2, 0x105, 0x106, 0x7, 0x24, 
    0x2, 0x2, 0x106, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x7, 0xe, 0x2, 
    0x2, 0x108, 0x109, 0x7, 0x1b, 0x2, 0x2, 0x109, 0x10a, 0x5, 0x4e, 0x28, 
    0x2, 0x10a, 0x10b, 0x7, 0x1b, 0x2, 0x2, 0x10b, 0x10c, 0x5, 0x4e, 0x28, 
    0x2, 0x10c, 0x10d, 0x7, 0x1b, 0x2, 0x2, 0x10d, 0x10e, 0x7, 0x27, 0x2, 
    0x2, 0x10e, 0x10f, 0x7, 0x24, 0x2, 0x2, 0x10f, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x110, 0x111, 0x7, 0xf, 0x2, 0x2, 0x111, 0x112, 0x7, 0x1b, 0x2, 
    0x2, 0x112, 0x113, 0x5, 0x4e, 0x28, 0x2, 0x113, 0x114, 0x7, 0x1b, 0x2, 
    0x2, 0x114, 0x115, 0x5, 0x4e, 0x28, 0x2, 0x115, 0x116, 0x7, 0x1b, 0x2, 
    0x2, 0x116, 0x117, 0x7, 0x27, 0x2, 0x2, 0x117, 0x118, 0x7, 0x24, 0x2, 
    0x2, 0x118, 0x33, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x7, 0x10, 0x2, 
    0x2, 0x11a, 0x11b, 0x7, 0x1b, 0x2, 0x2, 0x11b, 0x11c, 0x5, 0x4e, 0x28, 
    0x2, 0x11c, 0x11d, 0x7, 0x1b, 0x2, 0x2, 0x11d, 0x11e, 0x5, 0x4e, 0x28, 
    0x2, 0x11e, 0x11f, 0x7, 0x1b, 0x2, 0x2, 0x11f, 0x120, 0x7, 0x27, 0x2, 
    0x2, 0x120, 0x121, 0x7, 0x24, 0x2, 0x2, 0x121, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x122, 0x123, 0x7, 0x11, 0x2, 0x2, 0x123, 0x124, 0x7, 0x1b, 0x2, 
    0x2, 0x124, 0x125, 0x5, 0x4e, 0x28, 0x2, 0x125, 0x126, 0x7, 0x1b, 0x2, 
    0x2, 0x126, 0x127, 0x5, 0x4e, 0x28, 0x2, 0x127, 0x128, 0x7, 0x1b, 0x2, 
    0x2, 0x128, 0x129, 0x7, 0x27, 0x2, 0x2, 0x129, 0x12a, 0x7, 0x24, 0x2, 
    0x2, 0x12a, 0x37, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x7, 0x12, 0x2, 
    0x2, 0x12c, 0x12d, 0x7, 0x1b, 0x2, 0x2, 0x12d, 0x12e, 0x5, 0x4e, 0x28, 
    0x2, 0x12e, 0x12f, 0x7, 0x1b, 0x2, 0x2, 0x12f, 0x130, 0x5, 0x4e, 0x28, 
    0x2, 0x130, 0x131, 0x7, 0x1b, 0x2, 0x2, 0x131, 0x132, 0x7, 0x27, 0x2, 
    0x2, 0x132, 0x133, 0x7, 0x24, 0x2, 0x2, 0x133, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x134, 0x135, 0x7, 0x13, 0x2, 0x2, 0x135, 0x136, 0x7, 0x1b, 0x2, 
    0x2, 0x136, 0x137, 0x5, 0x4e, 0x28, 0x2, 0x137, 0x138, 0x7, 0x1b, 0x2, 
    0x2, 0x138, 0x139, 0x5, 0x4e, 0x28, 0x2, 0x139, 0x13a, 0x7, 0x1b, 0x2, 
    0x2, 0x13a, 0x13b, 0x7, 0x27, 0x2, 0x2, 0x13b, 0x13c, 0x7, 0x24, 0x2, 
    0x2, 0x13c, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x7, 0x15, 0x2, 
    0x2, 0x13e, 0x13f, 0x7, 0x1b, 0x2, 0x2, 0x13f, 0x140, 0x7, 0x1b, 0x2, 
    0x2, 0x140, 0x141, 0x7, 0x1b, 0x2, 0x2, 0x141, 0x142, 0x7, 0x24, 0x2, 
    0x2, 0x142, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x7, 0x15, 0x2, 
    0x2, 0x144, 0x145, 0x7, 0x1b, 0x2, 0x2, 0x145, 0x146, 0x5, 0x4e, 0x28, 
    0x2, 0x146, 0x147, 0x7, 0x1b, 0x2, 0x2, 0x147, 0x148, 0x7, 0x1b, 0x2, 
    0x2, 0x148, 0x149, 0x7, 0x24, 0x2, 0x2, 0x149, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x14a, 0x14b, 0x7, 0x6, 0x2, 0x2, 0x14b, 0x14c, 0x7, 0x1b, 0x2, 
    0x2, 0x14c, 0x14d, 0x7, 0x27, 0x2, 0x2, 0x14d, 0x14e, 0x7, 0x1b, 0x2, 
    0x2, 0x14e, 0x14f, 0x5, 0x4a, 0x26, 0x2, 0x14f, 0x150, 0x7, 0x24, 0x2, 
    0x2, 0x150, 0x41, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x7, 0x7, 0x2, 0x2, 
    0x152, 0x153, 0x7, 0x1b, 0x2, 0x2, 0x153, 0x154, 0x5, 0x4e, 0x28, 0x2, 
    0x154, 0x155, 0x7, 0x1b, 0x2, 0x2, 0x155, 0x156, 0x7, 0x27, 0x2, 0x2, 
    0x156, 0x157, 0x7, 0x1b, 0x2, 0x2, 0x157, 0x158, 0x5, 0x4a, 0x26, 0x2, 
    0x158, 0x159, 0x7, 0x24, 0x2, 0x2, 0x159, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x15a, 0x15b, 0x7, 0x3, 0x2, 0x2, 0x15b, 0x15c, 0x7, 0x1b, 0x2, 0x2, 
    0x15c, 0x15d, 0x5, 0x4e, 0x28, 0x2, 0x15d, 0x15e, 0x7, 0x1b, 0x2, 0x2, 
    0x15e, 0x15f, 0x5, 0x4e, 0x28, 0x2, 0x15f, 0x160, 0x7, 0x1b, 0x2, 0x2, 
    0x160, 0x161, 0x5, 0x4e, 0x28, 0x2, 0x161, 0x162, 0x7, 0x24, 0x2, 0x2, 
    0x162, 0x45, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x7, 0x4, 0x2, 0x2, 0x164, 
    0x165, 0x7, 0x1b, 0x2, 0x2, 0x165, 0x166, 0x5, 0x4e, 0x28, 0x2, 0x166, 
    0x167, 0x7, 0x1b, 0x2, 0x2, 0x167, 0x168, 0x5, 0x4e, 0x28, 0x2, 0x168, 
    0x169, 0x7, 0x1b, 0x2, 0x2, 0x169, 0x16a, 0x5, 0x4e, 0x28, 0x2, 0x16a, 
    0x16b, 0x7, 0x24, 0x2, 0x2, 0x16b, 0x47, 0x3, 0x2, 0x2, 0x2, 0x16c, 
    0x16d, 0x7, 0x5, 0x2, 0x2, 0x16d, 0x16e, 0x7, 0x1b, 0x2, 0x2, 0x16e, 
    0x16f, 0x5, 0x4e, 0x28, 0x2, 0x16f, 0x170, 0x7, 0x1b, 0x2, 0x2, 0x170, 
    0x171, 0x5, 0x4e, 0x28, 0x2, 0x171, 0x172, 0x7, 0x1b, 0x2, 0x2, 0x172, 
    0x173, 0x5, 0x4e, 0x28, 0x2, 0x173, 0x174, 0x7, 0x24, 0x2, 0x2, 0x174, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x5, 0x4e, 0x28, 0x2, 0x176, 
    0x177, 0x7, 0x1b, 0x2, 0x2, 0x177, 0x178, 0x5, 0x4a, 0x26, 0x2, 0x178, 
    0x179, 0x5, 0x4c, 0x27, 0x2, 0x179, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17a, 
    0x17d, 0x5, 0x4e, 0x28, 0x2, 0x17b, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17c, 
    0x175, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17c, 
    0x17b, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x181, 
    0x7, 0x1b, 0x2, 0x2, 0x17f, 0x181, 0x3, 0x2, 0x2, 0x2, 0x180, 0x17e, 
    0x3, 0x2, 0x2, 0x2, 0x180, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x181, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x182, 0x186, 0x7, 0x27, 0x2, 0x2, 0x183, 0x186, 0x7, 
    0x28, 0x2, 0x2, 0x184, 0x186, 0x7, 0x29, 0x2, 0x2, 0x185, 0x182, 0x3, 
    0x2, 0x2, 0x2, 0x185, 0x183, 0x3, 0x2, 0x2, 0x2, 0x185, 0x184, 0x3, 
    0x2, 0x2, 0x2, 0x186, 0x4f, 0x3, 0x2, 0x2, 0x2, 0xf, 0x57, 0x71, 0x78, 
    0x80, 0x8a, 0x90, 0x95, 0xa0, 0xb8, 0xc0, 0x17c, 0x180, 0x185, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

tigerIrParser::Initializer tigerIrParser::_init;
