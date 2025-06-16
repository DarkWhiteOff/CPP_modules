#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>
#include <string>

class Brain
{
public :
    Brain(void);
    Brain(const Brain &copy);
    Brain &operator=(const Brain &src);
    virtual ~Brain(void);

private :
    std::string m_ideas[100];
};

#endif