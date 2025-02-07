#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 10);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.decrementGrade();
        std::cout << bob << std::endl;
        Bureaucrat invalid("Invalid", 200);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}



/*
✔️ std::exception → C'est la classe de base pour toutes les exceptions standard en C++.
✔️ const → L'objet e ne peut pas être modifié dans le bloc catch.
✔️ & e (Référence constante) → Permet d'éviter une copie de l'exception (plus efficace).*/
/*
catch (const std::exception& e) { ... }

Si une exception est levée dans le bloc try, elle est capturée ici.
const std::exception& e capture l'exception pour en afficher le message.
e.what() retourne une chaîne de caractères décrivant l'erreur. Ce message est défini dans les classes d'exception (GradeTooLowException ou GradeTooHighException).
Exemple de message affiché :

Si le grade est trop élevé : "Exception: Grade too high!"
Si le grade est trop bas : "Exception: Grade too low!"
*/

/*
Le bloc try exécute les opérations normales.
Si une exception est levée (comme dans le cas de invalid), elle est capturée et un message est affiché grâce au bloc catch.
Cela permet de gérer les erreurs proprement sans que le programme ne plante.
*/

/*
Le compilateur utilise le mécanisme d'exceptions pour gérer les blocs try-catch. Voici comment cela fonctionne en bref :

Analyse du code :

Le compilateur identifie les blocs try et les blocs catch associés.
Il génère du code pour enregistrer les points où l'exécution peut reprendre en cas d'exception.
Pendant l'exécution :

Lorsqu'une exception est levée dans un bloc try, le programme interrompt l'exécution normale.
Il recherche le premier bloc catch capable de gérer le type de l'exception.
Gestion de l'exception :

Si un bloc catch approprié est trouvé, il exécute ce code pour gérer l'exception.
Si aucun bloc catch n'est trouvé, le programme termine brutalement.
Optimisations :

Les compilateurs modernes optimisent le code pour minimiser l'impact des exceptions sur les performances.
*/