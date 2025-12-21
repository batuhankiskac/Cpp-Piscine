#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
	Base() { }
	Base(const Base& other) { (void)other; }
	virtual ~Base() { }
	Base& operator=(const Base& other) {
		(void)other;
		return *this;
	}
};

#endif
