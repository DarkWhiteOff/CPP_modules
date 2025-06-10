#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

class Replace
{
public :
    Replace(void);
    Replace(std::ifstream& myFile, std::ofstream& myFileReplace);
    ~Replace(void);
    void rpl(std::string toReplace, std::string c);
private :
    std::ifstream& m_myFile;
    std::ofstream& m_myFileReplace;
};

#endif