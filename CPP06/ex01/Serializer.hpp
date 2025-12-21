#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer {
private:
	Serializer() { }
	~Serializer() { }
	Serializer(const Serializer& src) { (void)src; }
	Serializer& operator=(const Serializer& rhs) { (void)rhs; return *this; }
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
