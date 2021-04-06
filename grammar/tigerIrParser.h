
// Generated from /Users/alexarmbruster/Desktop/compilers_2/grammar/tigerIr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  tigerIrParser : public antlr4::Parser {
public:
  enum {
    ARRAY_STORE = 1, ARRAY_LOAD = 2, ASSIGN = 3, CALL = 4, CALLR = 5, ADD = 6, 
    SUB = 7, MULT = 8, DIV = 9, AND = 10, OR = 11, BREQ = 12, BRNEQ = 13, 
    BRLT = 14, BRGT = 15, BRLEQ = 16, BRGEQ = 17, GOTO = 18, RETURN = 19, 
    FLOAT = 20, INT = 21, VOID = 22, INT_LIST = 23, FLOAT_LIST = 24, COMMA = 25, 
    COLON = 26, SEMICOLON = 27, OPENPAREN = 28, CLOSEPAREN = 29, OPENBRACK = 30, 
    CLOSEBRACK = 31, OPENCURLY = 32, CLOSECURLY = 33, NEWLINE = 34, START_FUNCTION = 35, 
    END_FUNCTION = 36, ID = 37, INTLIT = 38, FLOATLIT = 39, WS = 40
  };

  enum {
    RuleIrProgram = 0, RuleFunctionSeq = 1, RuleFunction = 2, RuleParamList = 3, 
    RuleParamListTail = 4, RuleParam = 5, RuleTypeId = 6, RuleVarList = 7, 
    RuleArrayDeref = 8, RuleMultipleNewline = 9, RuleFuncBody = 10, RuleStatSeq = 11, 
    RuleStat = 12, RuleLabel = 13, RuleOptionalColon = 14, RuleAssign = 15, 
    RuleAdd = 16, RuleSub = 17, RuleMult = 18, RuleDiv = 19, RuleAnd_op = 20, 
    RuleOr_op = 21, RuleGoto_op = 22, RuleBreq = 23, RuleBrneq = 24, RuleBrlt = 25, 
    RuleBrgt = 26, RuleBrleq = 27, RuleBrgeq = 28, RuleReturn_void = 29, 
    RuleReturn_nonvoid = 30, RuleCall = 31, RuleCallr = 32, RuleArray_store = 33, 
    RuleArray_load = 34, RuleArray_assign = 35, RuleExprList = 36, RuleOptionalComma = 37, 
    RuleVal = 38
  };

  tigerIrParser(antlr4::TokenStream *input);
  ~tigerIrParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class IrProgramContext;
  class FunctionSeqContext;
  class FunctionContext;
  class ParamListContext;
  class ParamListTailContext;
  class ParamContext;
  class TypeIdContext;
  class VarListContext;
  class ArrayDerefContext;
  class MultipleNewlineContext;
  class FuncBodyContext;
  class StatSeqContext;
  class StatContext;
  class LabelContext;
  class OptionalColonContext;
  class AssignContext;
  class AddContext;
  class SubContext;
  class MultContext;
  class DivContext;
  class And_opContext;
  class Or_opContext;
  class Goto_opContext;
  class BreqContext;
  class BrneqContext;
  class BrltContext;
  class BrgtContext;
  class BrleqContext;
  class BrgeqContext;
  class Return_voidContext;
  class Return_nonvoidContext;
  class CallContext;
  class CallrContext;
  class Array_storeContext;
  class Array_loadContext;
  class Array_assignContext;
  class ExprListContext;
  class OptionalCommaContext;
  class ValContext; 

  class  IrProgramContext : public antlr4::ParserRuleContext {
  public:
    IrProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionContext *function();
    FunctionSeqContext *functionSeq();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IrProgramContext* irProgram();

  class  FunctionSeqContext : public antlr4::ParserRuleContext {
  public:
    FunctionSeqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FunctionSeqContext() = default;
    void copyFrom(FunctionSeqContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FunctionSeqEmptyContext : public FunctionSeqContext {
  public:
    FunctionSeqEmptyContext(FunctionSeqContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  FunctionSeqNonemptyContext : public FunctionSeqContext {
  public:
    FunctionSeqNonemptyContext(FunctionSeqContext *ctx);

    FunctionContext *function();
    FunctionSeqContext *functionSeq();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  FunctionSeqContext* functionSeq();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *START_FUNCTION();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    TypeIdContext *typeId();
    antlr4::tree::TerminalNode *OPENPAREN();
    ParamListContext *paramList();
    antlr4::tree::TerminalNode *CLOSEPAREN();
    antlr4::tree::TerminalNode *INT_LIST();
    std::vector<VarListContext *> varList();
    VarListContext* varList(size_t i);
    antlr4::tree::TerminalNode *FLOAT_LIST();
    FuncBodyContext *funcBody();
    antlr4::tree::TerminalNode *END_FUNCTION();
    MultipleNewlineContext *multipleNewline();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionContext* function();

  class  ParamListContext : public antlr4::ParserRuleContext {
  public:
    ParamListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ParamListContext() = default;
    void copyFrom(ParamListContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParamListEmptyContext : public ParamListContext {
  public:
    ParamListEmptyContext(ParamListContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ParamListNonEmptyContext : public ParamListContext {
  public:
    ParamListNonEmptyContext(ParamListContext *ctx);

    ParamContext *param();
    ParamListTailContext *paramListTail();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ParamListContext* paramList();

  class  ParamListTailContext : public antlr4::ParserRuleContext {
  public:
    ParamListTailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ParamListTailContext() = default;
    void copyFrom(ParamListTailContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParamListTailNonEmptyContext : public ParamListTailContext {
  public:
    ParamListTailNonEmptyContext(ParamListTailContext *ctx);

    antlr4::tree::TerminalNode *COMMA();
    ParamContext *param();
    ParamListTailContext *paramListTail();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ParamListTailEmptyContext : public ParamListTailContext {
  public:
    ParamListTailEmptyContext(ParamListTailContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ParamListTailContext* paramListTail();

  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeIdContext *typeId();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParamContext* param();

  class  TypeIdContext : public antlr4::ParserRuleContext {
  public:
    TypeIdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeIdContext() = default;
    void copyFrom(TypeIdContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TypeIdFloatContext : public TypeIdContext {
  public:
    TypeIdFloatContext(TypeIdContext *ctx);

    antlr4::tree::TerminalNode *FLOAT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  TypeIdIntContext : public TypeIdContext {
  public:
    TypeIdIntContext(TypeIdContext *ctx);

    antlr4::tree::TerminalNode *INT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  TypeIdVoidContext : public TypeIdContext {
  public:
    TypeIdVoidContext(TypeIdContext *ctx);

    antlr4::tree::TerminalNode *VOID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  TypeIdContext* typeId();

  class  VarListContext : public antlr4::ParserRuleContext {
  public:
    VarListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VarListContext() = default;
    void copyFrom(VarListContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VarListEmptyContext : public VarListContext {
  public:
    VarListEmptyContext(VarListContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  VarListExpandContext : public VarListContext {
  public:
    VarListExpandContext(VarListContext *ctx);

    antlr4::tree::TerminalNode *ID();
    ArrayDerefContext *arrayDeref();
    antlr4::tree::TerminalNode *COMMA();
    VarListContext *varList();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  VarListSingleContext : public VarListContext {
  public:
    VarListSingleContext(VarListContext *ctx);

    antlr4::tree::TerminalNode *ID();
    ArrayDerefContext *arrayDeref();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  VarListContext* varList();

  class  ArrayDerefContext : public antlr4::ParserRuleContext {
  public:
    ArrayDerefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ArrayDerefContext() = default;
    void copyFrom(ArrayDerefContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ArrayDerefNonemptyContext : public ArrayDerefContext {
  public:
    ArrayDerefNonemptyContext(ArrayDerefContext *ctx);

    antlr4::tree::TerminalNode *OPENBRACK();
    antlr4::tree::TerminalNode *INTLIT();
    antlr4::tree::TerminalNode *CLOSEBRACK();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ArrayDerefEmptyContext : public ArrayDerefContext {
  public:
    ArrayDerefEmptyContext(ArrayDerefContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ArrayDerefContext* arrayDeref();

  class  MultipleNewlineContext : public antlr4::ParserRuleContext {
  public:
    MultipleNewlineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEWLINE();
    MultipleNewlineContext *multipleNewline();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MultipleNewlineContext* multipleNewline();

  class  FuncBodyContext : public antlr4::ParserRuleContext {
  public:
    FuncBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *NEWLINE();
    StatSeqContext *statSeq();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncBodyContext* funcBody();

  class  StatSeqContext : public antlr4::ParserRuleContext {
  public:
    StatSeqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatSeqContext() = default;
    void copyFrom(StatSeqContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StatSeqNonemptyContext : public StatSeqContext {
  public:
    StatSeqNonemptyContext(StatSeqContext *ctx);

    StatContext *stat();
    StatSeqContext *statSeq();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StatSeqEmptyContext : public StatSeqContext {
  public:
    StatSeqEmptyContext(StatSeqContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  StatSeqContext* statSeq();

  class  StatContext : public antlr4::ParserRuleContext {
  public:
    StatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignContext *assign();
    AddContext *add();
    SubContext *sub();
    MultContext *mult();
    DivContext *div();
    And_opContext *and_op();
    Or_opContext *or_op();
    Goto_opContext *goto_op();
    BreqContext *breq();
    BrneqContext *brneq();
    BrltContext *brlt();
    BrgtContext *brgt();
    BrleqContext *brleq();
    BrgeqContext *brgeq();
    Return_voidContext *return_void();
    Return_nonvoidContext *return_nonvoid();
    CallContext *call();
    CallrContext *callr();
    Array_storeContext *array_store();
    Array_loadContext *array_load();
    Array_assignContext *array_assign();
    LabelContext *label();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatContext* stat();

  class  LabelContext : public antlr4::ParserRuleContext {
  public:
    LabelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    OptionalColonContext *optionalColon();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LabelContext* label();

  class  OptionalColonContext : public antlr4::ParserRuleContext {
  public:
    OptionalColonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OptionalColonContext* optionalColon();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignContext* assign();

  class  AddContext : public antlr4::ParserRuleContext {
  public:
    AddContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AddContext* add();

  class  SubContext : public antlr4::ParserRuleContext {
  public:
    SubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUB();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SubContext* sub();

  class  MultContext : public antlr4::ParserRuleContext {
  public:
    MultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MULT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MultContext* mult();

  class  DivContext : public antlr4::ParserRuleContext {
  public:
    DivContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DIV();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DivContext* div();

  class  And_opContext : public antlr4::ParserRuleContext {
  public:
    And_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  And_opContext* and_op();

  class  Or_opContext : public antlr4::ParserRuleContext {
  public:
    Or_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OR();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Or_opContext* or_op();

  class  Goto_opContext : public antlr4::ParserRuleContext {
  public:
    Goto_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GOTO();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Goto_opContext* goto_op();

  class  BreqContext : public antlr4::ParserRuleContext {
  public:
    BreqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREQ();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BreqContext* breq();

  class  BrneqContext : public antlr4::ParserRuleContext {
  public:
    BrneqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRNEQ();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BrneqContext* brneq();

  class  BrltContext : public antlr4::ParserRuleContext {
  public:
    BrltContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRLT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BrltContext* brlt();

  class  BrgtContext : public antlr4::ParserRuleContext {
  public:
    BrgtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRGT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BrgtContext* brgt();

  class  BrleqContext : public antlr4::ParserRuleContext {
  public:
    BrleqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRLEQ();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BrleqContext* brleq();

  class  BrgeqContext : public antlr4::ParserRuleContext {
  public:
    BrgeqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRGEQ();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BrgeqContext* brgeq();

  class  Return_voidContext : public antlr4::ParserRuleContext {
  public:
    Return_voidContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Return_voidContext* return_void();

  class  Return_nonvoidContext : public antlr4::ParserRuleContext {
  public:
    Return_nonvoidContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    ValContext *val();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Return_nonvoidContext* return_nonvoid();

  class  CallContext : public antlr4::ParserRuleContext {
  public:
    CallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CALL();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *ID();
    ExprListContext *exprList();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CallContext* call();

  class  CallrContext : public antlr4::ParserRuleContext {
  public:
    CallrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CALLR();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    ValContext *val();
    antlr4::tree::TerminalNode *ID();
    ExprListContext *exprList();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CallrContext* callr();

  class  Array_storeContext : public antlr4::ParserRuleContext {
  public:
    Array_storeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY_STORE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Array_storeContext* array_store();

  class  Array_loadContext : public antlr4::ParserRuleContext {
  public:
    Array_loadContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY_LOAD();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Array_loadContext* array_load();

  class  Array_assignContext : public antlr4::ParserRuleContext {
  public:
    Array_assignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Array_assignContext* array_assign();

  class  ExprListContext : public antlr4::ParserRuleContext {
  public:
    ExprListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprListContext() = default;
    void copyFrom(ExprListContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExprListContinueContext : public ExprListContext {
  public:
    ExprListContinueContext(ExprListContext *ctx);

    ValContext *val();
    antlr4::tree::TerminalNode *COMMA();
    ExprListContext *exprList();
    OptionalCommaContext *optionalComma();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ExprListSingleContext : public ExprListContext {
  public:
    ExprListSingleContext(ExprListContext *ctx);

    ValContext *val();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ExprListEmptyContext : public ExprListContext {
  public:
    ExprListEmptyContext(ExprListContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ExprListContext* exprList();

  class  OptionalCommaContext : public antlr4::ParserRuleContext {
  public:
    OptionalCommaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OptionalCommaContext* optionalComma();

  class  ValContext : public antlr4::ParserRuleContext {
  public:
    ValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ValContext() = default;
    void copyFrom(ValContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ValIdContext : public ValContext {
  public:
    ValIdContext(ValContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ValIntLitContext : public ValContext {
  public:
    ValIntLitContext(ValContext *ctx);

    antlr4::tree::TerminalNode *INTLIT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ValFloatLitContext : public ValContext {
  public:
    ValFloatLitContext(ValContext *ctx);

    antlr4::tree::TerminalNode *FLOATLIT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ValContext* val();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

