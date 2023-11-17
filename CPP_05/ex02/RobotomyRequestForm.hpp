#ifndef ROBOTOMY_REQUEST_FORM
# define ROBOTOMY_REQUEST_FORM

#include "AForm.hpp"

class RobotomyRequestForm:public AForm{
    private:
        std::string _target;

        RobotomyRequestForm();

    public:
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm( const RobotomyRequestForm& src);
        ~RobotomyRequestForm();

        RobotomyRequestForm& operator = ( const RobotomyRequestForm& rhs);

        void execute( const Bureaucrat& executor) const;
};

#endif