/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:19:37 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/12 20:59:21 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("ClapTrap"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap constructor called!" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap constructor called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called!" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const &other) : Name(other.Name), HitPoints(other.HitPoints), EnergyPoints(other.EnergyPoints), AttackDamage(other.AttackDamage)
{
    std::cout << "ClapTrap copy constructor called!" << std::endl;
}
ClapTrap	&ClapTrap::operator=(ClapTrap const &other)
{
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this != &other)
    {
        this->Name = other.Name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (HitPoints> 0 && EnergyPoints > 0)
    {
        EnergyPoints--;
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " has no energy or health left to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(int amount)
{
    if (HitPoints > 0)
    {
        if (HitPoints < amount)
            HitPoints = amount;
        else
            HitPoints -= amount;
        std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage, remaining HP: " << HitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " is already out of health!" << std::endl;
    }
}

void ClapTrap::beRepaired(int amount)
{
    if (HitPoints > 0 && EnergyPoints > 0)
    {
        EnergyPoints--;
        HitPoints += amount;
        std::cout << "ClapTrap " << Name << " repairs itself for " << amount << " points, new HP: " << HitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " has no energy or health left to repair!" << std::endl;
    }
}