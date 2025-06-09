#include "Fixed.hpp"

Fixed::Fixed() : raw(0) { }

Fixed::Fixed(const int intValue) {
	this->raw = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	this->raw = static_cast<int>(roundf(floatValue * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed &other) {
	this->raw = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other)
		this->raw = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() { }

int Fixed::getRawBits(void) const {
	return (this->raw);
}

void Fixed::setRawBits(int const raw) {
	this->raw = raw;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(this->raw) / (1 << fractionalBits));
}

int Fixed::toInt(void) const {
	return (this->raw >> fractionalBits);
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->raw == other.raw);
}

bool Fixed::operator!=(const Fixed &other) const {
	return !(*this == other);
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->raw < other.raw);
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->raw <= other.raw);
}

bool Fixed::operator>(const Fixed &other) const {
	return (this->raw > other.raw);
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->raw >= other.raw);
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->raw + other.raw);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->raw - other.raw);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	long temp = static_cast<long>(this->raw) * static_cast<long>(other.raw);
	result.setRawBits(static_cast<int>(temp >> fractionalBits));
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	long temp = (static_cast<long>(this->raw) << fractionalBits) / other.raw;
	result.setRawBits(static_cast<int>(temp));
	return (result);
}

Fixed &Fixed::operator++() {
	this->raw++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++(*this);
	return (temp);
}

Fixed &Fixed::operator--() {
	this->raw--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--(*this);
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}
