#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Default Constructor called of Serializer" << std::endl;
}

Serializer::Serializer(const Serializer &other) {
	(void) other;
	std::cout << "Copy Constructor called of Serializer" << std::endl;
}

// Destructor
Serializer::~Serializer() {
	std::cout << "Destructor called of Serializer" << std::endl;
}

size_t	Serializer::serialize(Data* ptr) {
	return reinterpret_cast<size_t>(ptr);
}

Data*	Serializer::deserialize(size_t raw) {
	 return reinterpret_cast<Data*>(raw);
}