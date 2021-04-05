
// Generated from /Users/alexarmbruster/Desktop/compilers_2/grammar/tigerIr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  tigerIrLexer : public antlr4::Lexer {
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

  tigerIrLexer(antlr4::CharStream *input);
  ~tigerIrLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

