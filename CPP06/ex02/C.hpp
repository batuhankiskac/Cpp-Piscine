#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base {
public:
	C() { }
	C(const C& other) : Base(other) { }
	virtual ~C() { }
	C& operator=(const C& other) {
		Base::operator=(other);
		return *this;
	}
};

#endif
