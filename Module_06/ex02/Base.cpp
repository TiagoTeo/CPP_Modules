#include "Base.hpp"

Base::~Base()
{
	std::cout << "Destructor called of Base" << std::endl;
}

Base *generate(void)
{
	Base *base;
	srand(time(0));
	
	int random = rand() % 3;
	switch(random){
		case 1:
			base = new A;
			break ;
		case 2:
			base = new B;
			break ;
		default:
			base = new C;
	}
	return base;
}

void identify(Base* p)
{
	A* a;
	B* b;
	C* c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	return ;
}