#include <iostream>
#include "Array.hpp"

int main()
{
    try {
        Array<int> arr(5);
        
        for (unsigned int i = 0; i < arr.size(); ++i)
        {
            arr[i] = i * 10;
        }

        // Afficher les éléments
        std::cout << "Tableau arr: ";
        for (unsigned int i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        // Tester l'opérateur de copie
        Array<int> arr_copy = arr;
        std::cout << "Tableau copié arr_copy: ";
        for (unsigned int i = 0; i < arr_copy.size(); ++i) {
            std::cout << arr_copy[i] << " ";
        }
        std::cout << std::endl;

        // Tester l'affectation
        Array<int> arr_assign;
        arr_assign = arr;
        std::cout << "Tableau après affectation arr_assign: ";
        for (unsigned int i = 0; i < arr_assign.size(); ++i) {
            std::cout << arr_assign[i] << " ";
        }
        std::cout << std::endl;

        // Tester l'exception en accédant à un index hors limites
        std::cout << "Accès à un index hors limites : ";
        std::cout << arr[10] << std::endl;  // Cette ligne doit lancer une exception

    } catch (const std::exception& e) {
        std::cout << "Erreur : tentative d'accès à un index hors limites." << std::endl;
    }

    return 0;
}
