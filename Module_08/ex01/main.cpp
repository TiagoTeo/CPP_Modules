#include "Span.hpp"

int	main ()
{
	Span test(12345);
	
	try {
		test.shortestSpan();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
    }
	try {
		test.addListNumber(12345);
	}
	catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	try {
		test.addListNumber(5);
	}
	catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	for (unsigned int i = 0;  i < test.getVector().size(); i++)
		std::cout << "Vector: " << test.getVector()[i] << std::endl;
	std::cout << "Vector size: " << test.getVector().size() <<  std::endl;
	std::cout << "Shortest Span for test: " << test.shortestSpan() << std::endl;
	std::cout  << "Longest Span for test: " << test.longestSpan() << std::endl;
	//checking it range
	std::cout  << "Starting iterator tests" << std::endl;
	Span itTest(10);
	std::vector<int> vc_1(10);
	for(int i = 0; i < 10; i++){
            vc_1[i]=  i;
    }
	std::vector<int> vc_2(20);
	for(int i = 0; i < 20; i++){
            vc_2[i]=  i;
    }
	//test vector size 
	try {
		itTest.addRange(vc_2.begin(), vc_2.end());
	} catch (const std::exception &e) {
		std::cerr << e.what() << " Vector to big" << std::endl;
	}
	//testing range of it
	try {
		itTest.addRange(vc_1.begin(), vc_1.end());
	} catch (const std::exception &e) {
		std::cerr << e.what() << " Unexpected error" << std::endl;
	}
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest Span for sp: " << sp.shortestSpan() << std::endl;
	std::cout  << "Longest Span for sp: " << sp.longestSpan() << std::endl;
}