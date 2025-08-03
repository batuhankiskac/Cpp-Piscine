#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name) {
	for (int i = 0; i < 4; ++i) {
		this->inventory[i] = NULL;
	}
}

Character::Character(const Character &other) {
	for (int i = 0; i < 4; ++i) {
		this->inventory[i] = NULL;
	}
	*this = other;
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			if (this->inventory[i] != NULL) {
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
		}
		this->name = other.name;
		for (int i = 0; i < 4; ++i) {
			if (other.inventory[i] != NULL) {
				this->inventory[i] = other.inventory[i]->clone();
			}
		}
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; ++i) {
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
		}
	}
}

std::string const & Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	if (m == NULL) {
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			return;
		}
	}

}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL) {
		this->inventory[idx]->use(target);
	}
}
