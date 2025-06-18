#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap("Default"), FragTrap("Default"), name("Default") {
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << name << " created with default values." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << name << " created with specified name." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "DiamondTrap " << name << " copied from another DiamondTrap." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name << " destroyed." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		std::cout << "DiamondTrap " << name << " assigned from another DiamondTrap." << std::endl;
	}
	return (*this);
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints == 0) {
		std::cout << "DiamondTrap " << this->name << " is already destroyed!" << std::endl;
		return;
	}
	this->hitPoints = (amount >= this->hitPoints) ? 0 : this->hitPoints - amount;
	std::cout << "DiamondTrap " << this->name << " takes " << amount
			  << " points of damage! Current hit points: " << this->hitPoints << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "DiamondTrap " << this->name << " repaired itself for " << amount
				  << " points! Current hit points: " << this->hitPoints << std::endl;
	} else {
		std::cout << "DiamondTrap " << this->name << " cannot be repaired!" << std::endl;
	}
}

void DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}
