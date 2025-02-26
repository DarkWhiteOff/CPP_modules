#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
    (void)argc;
    std::ifstream myFile(argv[1]);
    std::ofstream myFileReplace("file.replace");

    if (myFile && myFileReplace)
    {
        std::string line;
        while (getline(myFile, line))
        {
            std::size_t found = line.find_first_of(argv[2]);
            while (found != std::string::npos)
            {
                line[found] = argv[3][0];
                found = line.find_first_of(argv[2][0]);
            }
            myFileReplace << line << std::endl;
        }
    }
    else
        std::cout << "Error handling replacement" << std::endl;
    return (0);
}