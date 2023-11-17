#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::Intern( const Intern& src ){
    *this = src;
}

Intern::~Intern(){}

Intern&   Intern::operator= ( const Intern& rhs){
    (void)rhs;
    return (*this);
}

AForm*   Intern::makeForm(std::string name, std::string target)
{
    std::string tab[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

    AForm* Forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == tab[i])
        {
            std::cout << "Intern creates " << Forms[i]->getName() << std::endl;
            return (Forms[i]);
        }
    }
    std::cout << name << " Form cannot be created" << std::endl;
    return (NULL);
}
