#include "Instruction.h"
#include "IrEnums.h"


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
    
    // //TODO: add option menu class
    // int tokens_code;
    // std::string tigerInputFile;
    // std::string tigerInputFileName;
    // std::string irOutputFile;

    // if (optionExists(argv, argv+argc, "-l"))
    //     tokens_code=2;
    // else if(optionExists(argv, argv+argc, "-p"))
    //     tokens_code=1;
    // else
    //     tokens_code=0;

    // // read input file
    // if (optionExists(argv, argv+argc, "-i"))
    // {
    //     tigerInputFile = getOption(argv, argv+argc, "-i");
    //     std::string ext = ".tiger";
    //     if (tigerInputFile.size() > ext.size() &&
    //         tigerInputFile.substr(tigerInputFile.size() - ext.size()) == ".tiger")
    //     {
    //         tigerInputFileName = tigerInputFile.substr(0, tigerInputFile.size() - ext.size());
    //         irOutputFile = tigerInputFileName+".ir";
    //     }
    //     else
    //     {
    //         std::cout << "input file must have extension .tiger";
    //         return -1;
    //     }

    // }
    // else
    // {
    //     std::cout << "missing input file name" << std::endl;
    //     return -1;
    // }
    


    return 0;

}