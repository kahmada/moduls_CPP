#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 10);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.decrementGrade();
        std::cout << bob << std::endl;
        Bureaucrat invalid_br("Invalid", 200);
        Bureaucrat invalid_br2("Invalid2", 0);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
