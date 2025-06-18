#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &other);
		virtual ~ClapTrap();

		ClapTrap &operator=(const ClapTrap &other);

		virtual void attack(const std::string &target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
};

#endif
