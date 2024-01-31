#include "Array.hpp"

# define MAX_VAL 750

int main( void ) {
	Array <int> a(5);
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		const int n = rand();
		std::cout << "n: " << n << std::endl; 
		a[i] = n;
	}
	try {
		std::cout << "trying to access index 6 on a array of " << a.size() << std::endl;
		a[6] = 6;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "trying to access index 4 on a array of " << a.size() << std::endl;
		a[4] = 4;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Array <int> b(5);
	Array <int> c(5);
	b = a;
	c = b;
	std::cout << "this arrays all should be equal: " << std::endl;
	a.printArray();
	b.printArray();
	c.printArray();

	std::cout << "Checking with another type" << std::endl;
	Array <std::string> s(3);
	std::cout << "Assigning to the array: 0 = ola; 1 = naoSeiQue; 2 = adeus" << std::endl;
	s[0] = "ola";
	s[1] = "naoSeiQue";
	s[2] = "adeus";
	s.printArray();

	std::cout << "now running code from main.cpp of project page, it shouldnt crash or say: didn't save the same value!!" << std::endl;
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	return 0;
}