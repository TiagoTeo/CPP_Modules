#include "Base.hpp"
#include <iostream>

int main()
{
	Base *base = NULL;
	base = generate();
	std::cout << "ID by ptr: "; 
	identify(base);
	std::cout << "ID by ref: "; 
	identify(*base);
	delete base;
}