#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called for " << name << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		std::cout << "ScavTrap assignment operator called" << std::endl;
	}
	return (*this);
}

void ScavTrap::attack(const std::string &target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout << "ScavTrap " << this->name << " attacks " << target
				  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	} else {
		std::cout << "ScavTrap " << this->name << " cannot attack!" << std::endl;
	}
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints == 0) {
		std::cout << "ScavTrap " << this->name << " is already destroyed!" << std::endl;
		return;
	}
	this->hitPoints = (amount >= this->hitPoints) ? 0 : this->hitPoints - amount;
	std::cout << "ScavTrap " << this->name << " takes " << amount
			  << " points of damage! Current hit points: " << this->hitPoints << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "ScavTrap " << this->name << " repaired itself for " << amount
				  << " points! Current hit points: " << this->hitPoints << std::endl;
	} else {
		std::cout << "ScavTrap " << this->name << " cannot be repaired!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	if (this->hitPoints > 0 && this->energyPoints > 0)
		std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode!" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " cannot enter Gate Keeper mode!" << std::endl;
}
