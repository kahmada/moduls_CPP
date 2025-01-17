#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <array>
#include <string>

class Character : public ICharacter {
private:
    std::string _name;
    AMateria *_inventory[4];

public:
    Character(std::string const & name);
    Character(Character const & other);
    Character & operator=(Character const & other);
    ~Character();

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif


