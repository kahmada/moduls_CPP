
#include <iostream>
#include "iter.hpp"

void print_int(int& n)
{
    std::cout << n << " ";
}

void add_one(int& n)
{
    n += 1;
}
void print_string(std::string& str)
{
    std::cout << str << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Affichage des éléments du tableau : ";
    iter(arr, length, print_int);
    std::cout << std::endl;

    std::cout << "Ajout de 1 à chaque élément du tableau : ";
    iter(arr, length, add_one);
    iter(arr, length, print_int);
    std::cout << std::endl;

    std::string str_arr[] = {"hello", "world", "iter", "template"};
    size_t str_length = sizeof(str_arr) / sizeof(str_arr[0]);

    std::cout << "Affichage des chaînes : ";
    iter(str_arr, str_length, print_string);
    std::cout << std::endl;

    return 0;
}
