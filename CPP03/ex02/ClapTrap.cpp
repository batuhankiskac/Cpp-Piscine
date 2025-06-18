#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " created with default values." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " created with specified name." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name), hitPoints(other.hitPoints),
	  energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << "ClapTrap " << name << " copied from another ClapTrap." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
		std::cout << "ClapTrap " << name << " assigned from another ClapTrap." << std::endl;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target) {
	if (energyPoints > 0 && hitPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target
				  << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " cannot attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
		return;
	}
	hitPoints = (amount >= hitPoints) ? 0 : hitPoints - amount;
	std::cout << "ClapTrap " << name << " takes " << amount
			  << " points of damage! Current hit points: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0) {
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name << " repaired itself for " << amount
				  << " points! Current hit points: " << hitPoints << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " cannot be repaired!" << std::endl;
	}
}
