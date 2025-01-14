/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:35:36 by kahmada           #+#    #+#             */
/*   Updated: 2024/12/07 20:54:45 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
private:
    std::string firstName;
    std::string lastName; 
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void setDetails();
    void displaySummary(int index);
    void displayDetails();
    bool isEmpty();
};

#endif
