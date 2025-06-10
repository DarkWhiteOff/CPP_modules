#include "Replace.hpp"

Replace::Replace(std::ifstream& myFile, std::ofstream& myFileReplace) : m_myFile(myFile), m_myFileReplace(myFileReplace)
{
    return ;
}

Replace::~Replace(void)
{
    return ;
}

void    Replace::rpl(std::string toReplace, std::string c)
{
    std::string line;
    while (getline(m_myFile, line))
    {
        std::size_t found = line.find_first_of(toReplace);
        while (found != std::string::npos)
        {
            line[found] = c[0];
            found = line.find_first_of(toReplace[0]);
        }
        m_myFileReplace << line << std::endl;
    }
}