#include "ParseTree.h"
#include "CFG.h"
#include "CodeGenerator.h"

// CITATION:
// got these two functions for parsing command line arguments from here
// https://stackoverflow.com/questions/865668/parsing-command-line-arguments-in-c
char * getOption(char ** start, char ** end, const std::string & option)
{
    char ** itr = std::find(start, end, option);
    if (itr != end && ++itr != end)
        return *itr;
    return 0;
}
bool optionExists(char ** start, char ** end, const std::string & option)
{
    return std::find(start, end, option) != end;
}



int main(int argc, char* argv[]) {
    
    //TODO: add option menu class
    //int tokens_code;
    std::string inputFile;
    std::string inputFileName;
    std::string mipsOutputFile;

    // if (optionExists(argv, argv+argc, "-l"))
    //     tokens_code=2;
    // else if(optionExists(argv, argv+argc, "-p"))
    //     tokens_code=1;
    // else
    //     tokens_code=0;

    // read input file
    if (optionExists(argv, argv+argc, "-i"))
    {
        inputFile = getOption(argv, argv+argc, "-i");
        std::string ext = ".ir";
        if (inputFile.size() > ext.size() &&
            inputFile.substr(inputFile.size() - ext.size()) == ".ir")
        {
            inputFileName = inputFile.substr(0, inputFile.size() - ext.size());
            mipsOutputFile = inputFileName+".s";
        }
        else
        {
            std::cout << "input file must have extension .ir";
            return -1;
        }

    }
    else
    {
        std::cout << "missing input file name" << std::endl;
        return -1;
    }

    tiger::ParseTree * parseTree = new tiger::ParseTree(inputFile);
    
    parseTree->visitTree();
    Module* mod = parseTree->getModule();

    for (Function* func : mod->getFunctions())
    {
        IR::CFG* cfg = new IR::CFG(func);
        cfg->build();
        cfg->print();
    }

    
    // if register allocation strategy is not naive
    /// GARRETS SECTION    
    // CFG cfg(program); // GARRET

    // END GARRETS SECION
    CodeGenerator codeGenerator(mod); // ALEX
    return 0;

}