/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:19:29 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/12 18:30:23 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap hi;
    
    ClapTrap clapTrap("Clappy");
    ScavTrap scavTrap("Scavvy");
    clapTrap.attack("Target1");
    clapTrap.beRepaired(3);
    scavTrap.attack("Clappy");
    clapTrap.takeDamage(10);
    scavTrap.takeDamage(100);
    scavTrap.attack("Scavvy");
    scavTrap.guardGate();

    return 0;
}
