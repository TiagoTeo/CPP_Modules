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

void PmergeMe::merge(const T &container) {
    
}

void PmergeMe::execute() {
    struct timeval start, end;
    float miliseconds;

    std::cout << "before: " << std::endl;
    printContainer(_vector);
    gettimeofday(&start, NULL);
    merge(_vector);
    gettimeofday(&end, NULL);
    miliseconds = static_cast<float>(static_cast<float>(end.tv_sec - start.tv_sec) * 1000 + static_cast<float>(end.tv_usec - start.tv_usec) / 1000);
    std::cout << "after: " << std::endl;
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << miliseconds << " ms" << std::endl;
    printContainer(_vector);
}