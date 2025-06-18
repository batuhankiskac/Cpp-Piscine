#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called for " << name << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		std::cout << "FragTrap assignment operator called" << std::endl;
	}
	return (*this);
}

void FragTrap::attack(const std::string &target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout << "FragTrap " << this->name << " attacks " << target
				  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	} else {
		std::cout << "FragTrap " << this->name << " cannot attack!" << std::endl;
	}
}

void FragTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints == 0) {
		std::cout << "FragTrap " << this->name << " is already destroyed!" << std::endl;
		return;
	}
	this->hitPoints = (amount >= this->hitPoints) ? 0 : this->hitPoints - amount;
	std::cout << "FragTrap " << this->name << " takes " << amount
			  << " points of damage! Current hit points: " << this->hitPoints << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "FragTrap " << this->name << " repaired itself for " << amount
				  << " points! Current hit points: " << this->hitPoints << std::endl;
	} else {
		std::cout << "FragTrap " << this->name << " cannot be repaired!" << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	if (this->hitPoints > 0 && this->energyPoints > 0)
		std::cout << "FragTrap " << this->name << " requests a high five!" << std::endl;
	else
		std::cout << "FragTrap " << this->name << " cannot request a high five!" << std::endl;
}
