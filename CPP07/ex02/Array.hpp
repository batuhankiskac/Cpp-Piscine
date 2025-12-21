#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
private:
	T *arr;
	unsigned int size;
public:
	Array() : arr(NULL), size(0) { }

	Array(unsigned int n) {
		arr = new T[n]();
		size = n;
	}

	Array(const Array& other) : arr(NULL), size(0) {
		if (other.size > 0) {
			arr = new T[other.size];
			size = other.size;
			for (int i = 0; i < size; i++) {
				arr[i] = other.arr[i];
			}
		}
	}

	~Array() {
		if (arr)
			delete[] arr;
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			if (arr)
				delete[] arr;
			size = other.size;
			if (size > 0) {
				arr = new T[size];
				for (int i = 0; i < size; i++)
					arr[i] = other.arr[i];
			} else {
				arr = NULL;
			}
		}
	}

	T& operator[](unsigned int index) {
		if (index >= size)
			throw OutOfBoundsException();
		return arr[index];
	}

	const T& operator[](unsigned int index) const {
		if (index >= size)
			throw OutOfBoundsException();
		return arr[index];
	}

	unsingned int size() const {
		return size;
	}

	class OutOfBoundsException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Invalid index!";
			}
	};
};

#endif
