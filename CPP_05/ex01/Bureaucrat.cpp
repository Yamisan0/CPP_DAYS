#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade){
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& to_copy){
    *this = to_copy;
    std::cout << "Initialization by copy" << std::endl;
}

std::string Bureaucrat::getName() const{
    return (this->_name);
}

int Bureaucrat::getGrade() const{
    return (this->_grade);
}

Bureaucrat&    Bureaucrat::operator = (const Bureaucrat& rhs){
    if (this != &rhs)
    {
        this->_grade = rhs.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(){}

void    Bureaucrat::increm(void){
    if ( _grade - 1 < 1 )
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrem(void){
    if ( _grade + 1 > 150 )
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void    Bureaucrat::signForm(Form& formulaire){
    try{
        formulaire.beSigned(*this);
        std::cout << this->_name << " signed " << formulaire.getName();
    }
    catch(Form::GradeTooLowException &e){
        std::cout << this->_name << " couldn't sign " << formulaire.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator << (std::ostream& stream, Bureaucrat& obj)
{
    stream << obj.getName() << ", bureaucrat grade "<< obj.getGrade() << std::endl; 
    return stream;
}