#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array {
private:
	T *_arr;
	unsigned int _size;
public:
	Array() : _arr(NULL), _size(0) { }

	Array(unsigned int n) {
		_arr = new T[n]();
		_size = n;
	}

	Array(const Array& other) : _arr(NULL), _size(0) {
		if (other._size > 0) {
			_arr = new T[other._size];
			_size = other._size;
			for (unsigned int i = 0; i < _size; i++) {
				_arr[i] = other._arr[i];
			}
		}
	}

	~Array() {
		if (_arr)
			delete[] _arr;
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			if (_arr)
				delete[] _arr;
			_size = other._size;
			if (_size > 0) {
				_arr = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_arr[i] = other._arr[i];
			} else {
				_arr = NULL;
			}
		}
		return *this;
	}

	T& operator[](unsigned int index) {
		if (index >= _size)
			throw OutOfBoundsException();
		return _arr[index];
	}

	const T& operator[](unsigned int index) const {
		if (index >= _size)
			throw OutOfBoundsException();
		return _arr[index];
	}

	unsigned int size() const {
		return _size;
	}

	class OutOfBoundsException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Invalid index!";
			}
	};
};

#endif
