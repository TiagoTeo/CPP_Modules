#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av) {
    fillConteiners(av);
    execute();
}

PmergeMe::~PmergeMe() {
}

void PmergeMe::fillConteiners(char **av) {
    for (int i = 0; av[i]; i++) {
        int temp = std::atoi(av[i]);
        std::string s(av[i]);
        if (s.find_first_not_of("0123456789") != std::string::npos)
            throw notNumber();
        if (temp < 0)
            throw negativeNumber();
        _vector.push_back(temp);
        _list.push_back(temp);
    }
}

void PmergeMe::execute() {
    std::cout << "before: " << std::endl;
    printContainer(_vector);

    

    std::cout << "after: " << std::endl;
    printContainer(_vector);
}