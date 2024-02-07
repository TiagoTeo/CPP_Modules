#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <vector>
# include <cstdlib>
# include <ctime>

template <typename T> 
class	MutantStack : public std::stack<T> {
	public:
		MutantStack() : std::stack<T> {};
		MutantStack(const MutantStack& other) : std::stack<T>(other) {};
		MutantStack& operator=(const MutantStack& other) {
            if (this !=  other)
                return (*this);
            return (NULL);
        };
		~MutantStack() {};

        typedef template std::deque<T>::iterator iterator;
        iterator begin() { return this->c.begin();}
        iterator end() { return this->c.end();}

};
#endif