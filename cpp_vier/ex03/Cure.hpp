#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria {
public:
    Cure();
    Cure(Cure const & other);
    Cure(AMateria const & amateria);
    ~Cure();

    AMateria* clone() const;
    void use(ICharacter& target);
};


#endif

