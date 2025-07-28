#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>


class Brain
{
private:
	std::string	ideas[100];

public:
	Brain();
	Brain(std::string idea);
	Brain(const Brain &other);
	Brain	&operator=(const Brain &other);
	~Brain();

	std::string	getIdea(int i) const;
    std::string setIdea(int i, std::string idea);
};


#endif
