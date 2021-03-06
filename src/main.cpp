#include <fstream>
#include <iostream>

#include "ParseTree.h"
#include "CFG.h"
#include "CodeGenerator.h"
#include "IntraBlockAllocation.h"
#include "GraphColoring.h"


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


    // read input file
    if (optionExists(argv, argv+argc, "-r"))
    {
        inputFile = getOption(argv, argv+argc, "-r");
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

    RegisterAllocation rallocation = BRIGGS;
    tiger::ParseTree * parseTree = new tiger::ParseTree(inputFile);
    
    parseTree->visitTree();
    Module* mod = parseTree->getModule();
    

    // for testing, make it easy to switch between stdout and file output
    std::ostream* out;
    std::ofstream* outputFile;
    if(true)
    {
        outputFile = new std::ofstream();
        outputFile->open(mipsOutputFile, std::ios::out);
        if(!outputFile)
            return -1;
        out = outputFile;
    }
    else
    {
        out = &std::cout;
    }


    std::vector<IR::CFG*>* cfgList = new std::vector<IR::CFG*>;
    for (Function* func : *mod->getFunctions())
    {
        IR::CFG* cfg = new IR::CFG(func);
        cfgList->push_back(cfg);
        cfg->build();
    }

    if(rallocation==INTRA_BLOCK)
        intraBlockAllocation(cfgList);
    if(rallocation==BRIGGS)
        briggsGraphColoring(cfgList);

    //for(IR::CFG* cfg : *cfgList)
    //    cfg->print();




    CodeGenerator codeGenerator(mod, out, rallocation); // ALEX
    return 0;

}