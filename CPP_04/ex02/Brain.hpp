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
  
	void setIdea(size_t i, std::string idea);
    std::string getIdea(size_t i);

private :
    std::string m_ideas[100];
};

#endif