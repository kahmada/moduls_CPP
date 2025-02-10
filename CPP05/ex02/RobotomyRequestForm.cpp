#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm(target, 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    if (this != &other)
    {
        *this = other;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getSignStatus())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "BZZZ... DRRR... VRRR..." << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << getName() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed for " << getName() << "!" << std::endl;
}
/*
Implémenter execute
Vérifier si le formulaire est bien signé.
Vérifier si le Bureaucrat qui exécute a un grade suffisant.
Si une condition échoue, lever une exception appropriée.
4. Simuler la robotisation
Générer un bruit de forage en affichant un message du type "BZZZ... DRRR... VRRR...".
Générer un nombre aléatoire (0 ou 1) pour décider du succès ou de l’échec.
Afficher "Target <target> has been robotomized successfully!" si c’est un succès.
Sinon, afficher "Robotomy of <target> failed!".
5. Gérer les exceptions
Si le formulaire n'est pas signé → Lever une exception.
Si le grade de l'exécuteur est insuffisant → Lever une exception.
Si tout est bon, exécuter l’action.
Une fois ces étapes suivies, RobotomyRequestForm pourra être exécuté correctement avec une probabilité de 50% de réussite.
*/