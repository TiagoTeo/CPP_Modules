#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T> 
class	MutantStack : public std::stack<T> {
	public:
		MutantStack() : std::stack<T>() {std::cout << "MutantStack Default Constructor called" << std::endl;};
		MutantStack(const MutantStack& other) : std::stack<T>(other) {std::cout << "MutantStack Copy Constructor called" << std::endl;};
		MutantStack& operator=(const MutantStack& other) {
            std::cout << "MutantStack Operator Constructor called" << std::endl;
            if (this !=  other)
                return (*this);
            static_cast<std::stack<T>&>(*this) = static_cast<const std::stack<T>&>(other);
			return (*this);
        };
		~MutantStack() {std::cout << "MutantStack Deconstructor called" << std::endl;};

        typedef typename std::deque<T>::iterator iterator;
        iterator begin() { return this->c.begin();}
        iterator end() { return this->c.end();}

};
#endif