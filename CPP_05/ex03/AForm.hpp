#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        std::string const   _name ;
        bool                _is_signed;
        int const           _grade_to_sign;
        int const           _grade_to_exec ;
        AForm();
    public:
        AForm(std::string name, bool is_signed, int to_sign, int to_exec);
        AForm( const AForm& src );
        AForm& operator = (AForm& rhs);
        ~AForm();
        std::string getName (void) const;
        bool    getSigned(void) const;
        int     getGradeSign(void) const;
        int     getGradeExec(void) const;
        void    beSigned(Bureaucrat& signatory);

        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException: public std::exception{
            public:
                virtual const char* what() const throw() {return "Form Grade too High";}
        };
        class GradeTooLowException: public std::exception{
            public:
                virtual const char* what() const throw() {return "Form Grade too low";}
        };
        class NotSignedException: public std::exception{
            public:
                virtual const char *what() const throw() {return "Form not signed";}
        };
};

std::ostream&  operator << (std::ostream& out, AForm& obj);


#endif