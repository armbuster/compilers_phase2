#ifndef _SRC_PARSE_TREE_H
#define _SRC_PARSE_TREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include "tigerIrLexer.h"
#include "tigerIrParser.h"
#include "irVisitor.h"


namespace tiger {

class ParseTree
{
 private:
	irVisitor* visitor;
 	tiger::tigerIrLexer* lexer;
 	tiger::tigerIrParser* parser;
 	antlr4::ANTLRInputStream* tokenStream;
 	antlr4::CommonTokenStream* tokens;
 	antlr4::tree::ParseTree* tree;
 	std::string tigerFileName;
 	std::string irFileName;

 public:
 	ParseTree(std::string irFileName_);
 	~ParseTree(){};

 	tiger::tigerIrLexer* getLexer() { return lexer; };
 	tiger::tigerIrParser* getParser() { return parser; };
 	antlr4::CommonTokenStream* getTokens() { return tokens; };
 	std::string getTigerFileName(){ return tigerFileName; };
 	std::string getIrFileName(){ return irFileName; };
	Module* getModule();

 	bool visitTree();
};

}  // namespace tiger


#endif /* _SRC_PARSE_TREE_H */