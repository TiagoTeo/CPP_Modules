#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <sys/time.h>
#include <exception>

class PmergeMe {
    private:
        std::vector<int> _vector;
        std::list<int> _list;
    public:
        PmergeMe(char **av);
        PmergeMe(PmergeMe &other);
        PmergeMe& operator=(PmergeMe &other);
        ~PmergeMe();

        void fillConteiners(char ** av);
        void execute();

        class negativeNumber : public std::exception{
		public:
			virtual const char* what() const throw() { return "Error negative number in input"; };
		};
        class notNumber : public std::exception{
		public:
			virtual const char* what() const throw() { return "Error not a number in input"; };
		};

    template<typename T>
    void printContainer(const T& container) {
        for (const auto& elem : container) {
            std::cout << elem << " ";
        }
    }
};