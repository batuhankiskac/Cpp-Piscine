#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		this->learnedMaterias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	for (int i = 0; i < 4; ++i) {
		this->learnedMaterias[i] = NULL;
	}
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			if (this->learnedMaterias[i] != NULL) {
				delete this->learnedMaterias[i];
				this->learnedMaterias[i] = NULL;
			}
		}
		for (int i = 0; i < 4; ++i) {
			if (other.learnedMaterias[i] != NULL) {
				this->learnedMaterias[i] = other.learnedMaterias[i]->clone();
			}
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		if (this->learnedMaterias[i] != NULL) {
			delete this->learnedMaterias[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (m == NULL) {
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (this->learnedMaterias[i] == NULL) {
			this->learnedMaterias[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; ++i) {
		if (this->learnedMaterias[i] != NULL && this->learnedMaterias[i]->getType() == type) {
			return (this->learnedMaterias[i]->clone());
		}
	}
	return (0);
}
