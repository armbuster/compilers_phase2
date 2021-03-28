#include "ParseTree.h"


tiger::ParseTree::ParseTree(std::string irFileName_)
{

	irFileName = irFileName_;

	//create token stream
	std::fstream tigerFileStream(irFileName, std::ios::in);
    if(!tigerFileStream.good())
    {
        throw std::runtime_error("input file " + irFileName_ + " does not exist");
    }

    tokenStream = new antlr4::ANTLRInputStream(tigerFileStream);
    tigerFileStream.close();

    //generate member objects
    lexer = new tiger::tigerIrLexer(tokenStream);
    tokens = new antlr4::CommonTokenStream(lexer);
    parser = new tiger::tigerIrParser(tokens);
    tree = parser->irProgram();

}

bool tiger::ParseTree::visitTree()
{
    visitor = new irVisitor();
    visitor -> visit(tree);
    return true;
}

Program * tiger::ParseTree::getProgram()
{
    return visitor -> getProgram();
}