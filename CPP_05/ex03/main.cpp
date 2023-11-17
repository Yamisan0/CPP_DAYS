
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{

    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        std::cout << rrf->getSigned() << std::endl;
    }

    try {
        Bureaucrat bureaucrat("ash", 2);
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

        std::cout << "Signed :" << form1.getSigned() << std::endl;
        // bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);
        std::cout << "Signed :" << form1.getSigned() << std::endl;
        std::cout << std::endl << "--------------Form2---------------" << std::endl;

        bureaucrat.signForm(form2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}