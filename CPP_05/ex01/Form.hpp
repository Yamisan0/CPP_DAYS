#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        std::string const _name ;
        bool        _is_signed;
        int const        _grade_to_sign;
        int const        _grade_to_exec ;
        Form();
    public:
        Form(std::string name, bool is_signed, int to_sign, int to_exec);
        Form(Form& to_copy);
        Form& operator = (Form& rhs);
        ~Form();
        std::string getName(void);
        bool    getSigned(void);
        int     getGradeSign(void);
        int     getGradeExec(void);
        void    beSigned(Bureaucrat& signatory);

        class GradeTooHighException: public std::exception{
            public:
                virtual const char* what() const throw() {return "Form Grade too High";}
        };
        class GradeTooLowException: public std::exception{
            public:
                virtual const char* what() const throw() {return "Form Grade too low";}
        };

};

std::ostream&  operator << (std::ostream& out, Form& obj);


#endif