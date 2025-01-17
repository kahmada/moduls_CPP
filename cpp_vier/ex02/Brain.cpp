/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:57:44 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/12 18:57:45 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Brain.cpp
#include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "\0";
    std::cout << "Brain constructor called!" << std::endl;
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    std::cout << "Brain copy constructor called!" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destructor called!" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
   for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

// void Brain::setIdea(int index, const std::string& idea) {
//     if (index >= 0 && index < 100)
//         ideas[index] = idea;
// }

// std::string Brain::getIdea(int index) const {
//     if (index >= 0 && index < 100)
//         return ideas[index];
//     return "";
// }
