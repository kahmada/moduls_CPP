/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:11:38 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/01 13:01:18 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook!\n";

    while (1)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        getline(std::cin, command);
        if (std::cin.eof())
            break ;
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContacts();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command!\n";
    }
    return 0;
}
