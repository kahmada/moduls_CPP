#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        _templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const & other) {
    for (int i = 0; i < 4; ++i) {
        if (other._templates[i]) {
            _templates[i] = other._templates[i]->clone();
        } else {
            _templates[i] = NULL;
        }
    }
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete _templates[i];
            if (other._templates[i]) {
                _templates[i] = other._templates[i]->clone();
            } else {
                _templates[i] = NULL;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete _templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)//c est just pour ajouter un materiel ou tableau template qui existe dans materiasource donc il parcourt le tableu pour trouver une place vide et ajout le materiel
{
    if (!m)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (!_templates[i])
        {
            _templates[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)//c est pour return le type d amateriea ice ou bie cure donc il ceck le type et il le clone(ice ou cure)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_templates[i] && _templates[i]->getType() == type)
            return _templates[i]->clone();
    }
    return NULL;
}

