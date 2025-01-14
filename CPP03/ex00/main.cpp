/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:43:04 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/12 21:22:52 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap defaultClap;
    ClapTrap clap("Clap");
    ClapTrap copieClap(defaultClap);
    ClapTrap assignedClap;
    assignedClap = clap;
    defaultClap.attack("Target1");
    clap.takeDamage(5);
    assignedClap.takeDamage(3);
    copieClap.beRepaired(10);
    defaultClap.beRepaired(6);
    assignedClap.attack("Bot");
    defaultClap.takeDamage(4);
    copieClap.takeDamage(2);
    return 0;
}

