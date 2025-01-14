/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:19:29 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/13 13:13:30 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clapTrap("Clappy");

    FragTrap fragTrap("Fraggy");
    fragTrap.attack("Target1");
    fragTrap.highFivesGuys();
    fragTrap.takeDamage(20);
    fragTrap.beRepaired(30);
    ScavTrap scavTrap("Scavvy");
    scavTrap.attack("Clappy");
    scavTrap.guardGate();
    scavTrap.takeDamage(10);

    return 0;
}

