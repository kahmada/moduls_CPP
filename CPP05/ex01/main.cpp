#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try
    {
        Bureaucrat b1("Alice", 50);
        Bureaucrat b2("Bob", 150);
        Form form1("Form1", 60, 60);
        Form form2("Form2", 40, 40);

        std::cout << form1 << std::endl;
        b1.signForm(form1);
        b2.signForm(form1);
        b1.signForm(form2);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

