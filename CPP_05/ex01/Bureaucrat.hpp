#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat{
    private:
        std::string const _name;
        int               _grade;
        Bureaucrat();
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& to_copy);
        Bureaucrat& operator = (const Bureaucrat& rhs);
        ~Bureaucrat();



        std::string getName() const;
        int         getGrade() const;

        void increm(void);
        void decrem(void);

        void signForm(Form& formulaire);
        class GradeTooHighException:public std::exception{
            public:
                virtual const char* what() const throw(){return "Grade too high";}
        };
        class GradeTooLowException:public std::exception{
            public:
                virtual const char* what() const throw(){return "Grade too low";}
        };
};

std::ostream& operator << (std::ostream& stream, Bureaucrat& obj);

#endif