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

std::vector<int> PmergeMe::merge(std::vector<int> &left, std::vector<int> &right) {
    std::vector<int> result(left.size() + right.size());
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) 
            result[k] = left[i++];
		else 
            result[k] = right[j++];
        k++;
    }
    while (i < left.size()) 
        result[k++] = left[i++];
    while (j < right.size())
        result[k++] = right[j++];
   return (result);
}

std::list<int> PmergeMe::merge(std::list<int> &left, std::list<int> &right) {
    std::list<int> result;
    std::list<int>::const_iterator it_left = left.begin();
    std::list<int>::const_iterator it_right = right.begin();
    while (it_left != left.end() && it_right != right.end())
    {
        if (*it_left <= *it_right)
            result.push_back(*it_left++);
        else
            result.push_back(*it_right++);
    }
    while (it_left != left.end())
        result.push_back(*it_left++);
    while (it_right != right.end())
        result.push_back(*it_right++);
    return (result);
}

std::vector<int> PmergeMe::resolve(std::vector<int> &vec) {
    if (vec.size() == 1)
        return (vec);
    int mid = vec.size() / 2;
    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());
    left = resolve(left);
    right = resolve(right);
    return (merge(left, right));
}

std::list<int> PmergeMe::resolve(std::list<int> &list) {
    if (list.size() == 1)
        return (list);
    std::list<int>::iterator it = list.begin();
    std::advance(it, list.size() / 2);
    std::list<int> left(list.begin(), it);
    std::list<int> right(it, list.end());
    left = resolve(left);
    right = resolve(right);
    return (merge(left, right));
}

void PmergeMe::execute() {
    struct timeval start, end;
    float miliseconds;

    //vector
    std::cout << "before: ";
    printContainer(_vector);
    gettimeofday(&start, NULL);
    _vector = resolve(_vector);
    gettimeofday(&end, NULL);
    miliseconds = static_cast<float>(static_cast<float>(end.tv_sec - start.tv_sec) * 1000 + static_cast<float>(end.tv_usec - start.tv_usec) / 1000);
    std::cout << "after: ";
    printContainer(_vector);
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << miliseconds << " ms" << std::endl;

    //list
    std::cout << "before: ";
    printContainer(_list);
    gettimeofday(&start, NULL);
    _list = resolve(_list);
    gettimeofday(&end, NULL);
    miliseconds = static_cast<float>(static_cast<float>(end.tv_sec - start.tv_sec) * 1000 + static_cast<float>(end.tv_usec - start.tv_usec) / 1000);
    std::cout << "after: ";
    printContainer(_list);
    std::cout << "Time to process a range of " << _list.size() << " elements with std::list : " << miliseconds << " ms" << std::endl;
}