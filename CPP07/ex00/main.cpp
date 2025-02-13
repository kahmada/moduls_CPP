
#include <iostream>
#include "whatever.hpp"

int main(void) {
    int a = 2;
    int b = 3;
    
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;


    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    return 0;
}
/*
Plus spécifiquement, voici les objectifs visés par cet exercice :

Comprendre les templates de fonction :

Cet exercice montre comment créer des fonctions génériques, c'est-à-dire des fonctions qui peuvent être utilisées avec n'importe quel type de données, tant que ce type supporte les opérateurs de comparaison (comme <, >, etc.).
Vous allez apprendre à utiliser template <typename T> pour définir des fonctions qui peuvent être réutilisées pour plusieurs types sans dupliquer le code.
Apprendre à manipuler des types génériques :

En créant des fonctions comme swap, min et max, vous allez apprendre à manipuler des variables de types inconnus à l'avance. Cela vous permet d'écrire du code plus flexible et réutilisable.
Renforcer les connaissances sur les opérateurs de comparaison :

Les fonctions min et max nécessitent de comparer les valeurs de leurs arguments. Cela vous permet de travailler avec les opérateurs de comparaison (<, >, ==, etc.) et de comprendre comment les appliquer à différents types (comme int ou std::string).
Améliorer la compréhension de l'encapsulation et de la réutilisation de code :

En utilisant des templates, vous encapsulez la logique dans des fonctions réutilisables, ce qui rend votre code plus propre et maintenable.
En résumé, cet exercice vise à vous familiariser avec les templates en C++ et à vous aider à écrire des fonctions génériques qui peuvent être appliquées à une large variété de types de données tout en respectant certaines contraintes, comme la possibilité de comparer ces types.
*/

/*
::swap appelle la fonction swap dans l'espace de noms global, même si d'autres versions de swap existent dans des espaces de noms comme std.
Le :: garantit que vous appelez une version spécifique de la fonction, et cela est souvent utilisé pour éviter des conflits de noms lorsque plusieurs versions de la même fonction existent.
*/