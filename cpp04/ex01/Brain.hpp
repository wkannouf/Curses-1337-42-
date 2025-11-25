#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class	Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain &brain);
		Brain &operator=(const Brain &brain);
		std::string	getIdea(int i) const;
		void		setIdea(int i, const std::string idea);
		~Brain();
};
#endif