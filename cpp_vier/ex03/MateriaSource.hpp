#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <array>

class MateriaSource : public IMateriaSource {
private:
    AMateria *_templates[4];

public:
    MateriaSource();
    MateriaSource(MateriaSource const & other);
    MateriaSource & operator=(MateriaSource const & other);
    ~MateriaSource();

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};
/*learnMateria(AMateria*)
Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias
maximum. Ces dernières ne sont pas forcément uniques.*/

/*
createMateria(std::string const &)
Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédemment par la MateriaSource et dont le type est le même que celui passé en paramètre. Retourne 0 si le type est inconnu.*/
#endif
