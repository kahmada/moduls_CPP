/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:01:04 by kahmada           #+#    #+#             */
/*   Updated: 2024/12/16 10:15:44 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    std::cout << "Memory address of the string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << "Value of the string variable: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}
// int main()
// {
//     int  a = 3;
//     int &b = a;
//     int &c = b;
//     int *p = &a;

//     std::cout <<&a<<std::endl;
//     std::cout<< &b<< std::endl;
//     std::cout << &c<<std::endl;
//     std::cout << c << std::endl;
//     std::cout << *p << std::endl;
//      std::cout << p << std::endl;
//     std::cout << &p << std::endl;

// }