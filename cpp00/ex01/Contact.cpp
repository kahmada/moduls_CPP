/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:45:33 by kahmada           #+#    #+#             */
/*   Updated: 2024/12/07 20:54:59 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


std::string    read_line(std::string str, std::string name);

int just_spaces(std::string s)
{
    int i = 0;
    while(s[i])
    {
        if (!std::isspace(s[i]))
            return (0);
        i++;
    }
    return (1);
}

int valid_phone(std::string s)
{
	int i = 0;
	while(s[i])
	{
		if(!std::isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void Contact::setDetails()
{
    std::cout << "Enter First Name: ";
    firstName = read_line(firstName, "Enter First Name: ");
    std::cout << "Enter Last Name: ";
    lastName = read_line(lastName, "Enter Last Name: ");
    std::cout << "Enter Nickname: ";
    nickname= read_line(nickname, "Enter Nick Name: ");
    std::cout << "Enter Phone Number: ";
    phoneNumber = read_line(phoneNumber, "Enter Phone Number: ");
	while (!valid_phone(phoneNumber))
	{
		std::cout << "Invalid phone number\n";
		std::cout << "Enter Phone Number: ";
		phoneNumber = read_line(phoneNumber, "Enter Phone Number: ");
	}
    std::cout << "Enter Darkest Secret: ";
    darkestSecret = read_line(darkestSecret, "Enter Darkest Secret: ");
}

void Contact::displaySummary(int index)
{
    std::cout << "|";
    std::cout << std::setw(10) << index << "|";

    if (firstName.size() > 10)
        std::cout << std::setw(10) << firstName.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << firstName;
    std::cout << "|";
    if (lastName.size() > 10)
        std::cout << std::setw(10) << lastName.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << lastName;
    std::cout << "|";
    if (nickname.size() > 10)
        std::cout << std::setw(10) << nickname.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << nickname;
    std::cout << "|" << std::endl;
}

void Contact::displayDetails()
{
    std::cout << "First Name: " << firstName << "\n";
    std::cout << "Last Name: " << lastName << "\n";
    std::cout << "Nickname: " << nickname << "\n";
    std::cout << "Phone Number: " << phoneNumber << "\n";
    std::cout << "Darkest Secret: " << darkestSecret << "\n";
}

bool Contact::isEmpty()
{
    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
        return true;
    else
        return false;
}
