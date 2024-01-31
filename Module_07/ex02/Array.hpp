#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>
# include <ctime>

template <typename T>
class Array {
	private:
		T 		*_arr;
		size_t	_size;
	public:
		Array<T>() : _size(0) {
			std::cout << "Default Constructor called of Array" << std::endl;
			_arr = new T[0];
		}
		~Array<T>() {
			std::cout << "Destructer called of Array" << std::endl;
			delete [] _arr;
		}
		Array<T>(const Array<T> &other) : _size(other._size) {
			std::cout << "Copy Constructor called of Array" << std::endl;
			_arr = new T[other._size];
			for (unsigned int i = 0; i < other._size; i++)
				_arr[i] = other._arr[i];
		}
		Array<T> &operator=(const Array<T> &other) {
			std::cout << "Assignment Operator called of Array" << std::endl;
			if (this != &other)
			{
				delete [] _arr;
				_arr = new T[other._size];
				for (unsigned int i = 0; i < other._size; i++)
					_arr[i] = other._arr[i];
			}
			return *this;
		}
		Array<T>(unsigned int n) : _size(n) {
			std::cout << "Constructor called of Array" << std::endl;
			_arr = new T[n];
		}

		T &operator[](unsigned int index) {
			if (index >= _size)
				throw outOfBoundsException();
			return _arr[index];
		}
		unsigned int size(void) const {
			return _size;
		}
		void	printArray(void) {
			std::cout << "{";
			for (unsigned int i = 0; i < _size; i++) {
				if (i + 1 < _size)
					std::cout << _arr[i] << "; ";
				else
					std::cout << _arr[i];
			}
			std::cout << "}" << std::endl;
		}

		class outOfBoundsException : public std::exception{
		public:
			virtual const char* what() const throw() { return "Out of bounds"; };
	};
};


#endif