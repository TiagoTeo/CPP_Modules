#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <sys/time.h>
#include <exception>
#include <cstdlib>

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

        std::vector<int> resolve(std::vector<int> &vec);
        std::list<int> resolve(std::list<int> &list);

        std::vector<int> merge(std::vector<int> &left, std::vector<int> &right);
        std::list<int> merge(std::list<int> &left, std::list<int> &right);

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
        typename T::const_iterator it;
        for (it = container.begin(); it != container.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};