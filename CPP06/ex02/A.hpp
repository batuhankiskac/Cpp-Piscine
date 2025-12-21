#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base {
public:
	A() { }
	A(const A& other) : Base(other) { }
	virtual ~A() { }
	A& operator=(const A& other) {
		Base::operator=(other);
		return *this;
	}
};

#endif
