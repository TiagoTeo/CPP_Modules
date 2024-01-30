#include "Whatever.hpp"


Whatever::Whatever(void) {
    std::cout << "Default Constructor called of Whatever" << std::endl;
}

Whatever & Whatever::operator=(const Whatever &other)
{
	(void)other;
	return *this;
}

Whatever::Whatever(const Whatever& other) {
	(void) other;
	std::cout << "Copy Constructor called of Whatever" << std::endl;
}

Whatever::~Whatever() {
	std::cout << "Destructer called of Whatever" << std::endl;
}