/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:46:47 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/13 13:11:57 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "FragTrap constructor called!" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap constructor called!" << std::endl;
}
FragTrap::FragTrap(FragTrap const &other)
{
	std::cout << "FragTrap copy constructor called!" << std::endl;
	*this = other;
}
FragTrap	&FragTrap::operator=(FragTrap const &other)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
    this->Name = other.Name;
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
    return (*this);
}
FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << Name << " requests a high five!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (HitPoints > 0 && EnergyPoints > 0) {
        EnergyPoints--;
        std::cout << "FragTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "FragTrap " << Name << " has no energy or health left to attack!" << std::endl;
    }
}
