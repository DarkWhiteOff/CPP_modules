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
    // Getter
		const std::string getIdea(size_t i)const;
		const std::string *getIdeaAddress(size_t i)const;
    // Setter
	    void setIdea(size_t i, std::string idea);

private :
    std::string m_ideas[100];
};

#endif