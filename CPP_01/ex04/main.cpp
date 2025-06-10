#include <iostream>
#include <string>
#include <fstream>
#include "Replace.hpp"

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        std::ifstream myFile(argv[1]);
        std::ofstream myFileReplace("file.replace");
        if (myFile && myFileReplace)
        {
            Replace replace(myFile, myFileReplace);
            replace.rpl(argv[2], argv[3]);
        }
        else
            std::cout << "Error handling replacement" << std::endl;
    }
    else
        std::cout << "Wrong arguments." << std::endl;
    return (0);
}