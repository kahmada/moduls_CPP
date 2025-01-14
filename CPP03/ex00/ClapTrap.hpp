/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:43:08 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/12 21:37:53 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
    std::string Name;
    int HitPoints;
    int EnergyPoints;
    int AttackDamage;

public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const &other);
    ClapTrap	&operator=(ClapTrap const &other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(int amount);
    void beRepaired(int amount);
};

#endif
