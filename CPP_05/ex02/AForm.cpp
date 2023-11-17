#include "AForm.hpp"



AForm::AForm(std::string name, bool is_signed, int to_sign, int to_exec):_name(name), _is_signed(is_signed), _grade_to_sign(to_sign), _grade_to_exec(to_exec)
{
    if (to_sign > 150 || to_exec > 150)
        throw(AForm::GradeTooLowException());
    if (to_sign < 1 || to_sign < 1)
        throw(AForm::GradeTooHighException());
}

AForm::AForm( const AForm& src ) : _name( src.getName() ), _grade_to_sign( src.getGradeSign() ), _grade_to_exec( src.getGradeExec() ) {}

AForm& AForm::operator=(AForm& rhs){
    if (this != &rhs)
    {
        this->_is_signed = rhs._is_signed;
    }
    return (*this);
}

AForm::~AForm(){}

std::string AForm::getName()const{
    return (this->_name);
}

bool AForm::getSigned() const{
    return (this->_is_signed);
}

int AForm::getGradeSign()const{
    return (this->_grade_to_sign);
}

int AForm::getGradeExec() const{
    return (this->_grade_to_exec);
}

void    AForm::beSigned(Bureaucrat& signatory){
    if (signatory.getGrade() > this->_grade_to_sign)
        throw (AForm::GradeTooLowException());
    this->_is_signed = true;
}

std::ostream&  operator << (std::ostream& out, AForm& obj){
    out << "-------------------------------------------------------------------------------------" << std::endl;
    out << "Name:   " <<  obj.getName() << " | Signed:   "<< obj.getSigned() << " | Grade to Sign:   "<< obj.getGradeSign()<< " | Grade Exec:   "<< obj.getGradeExec() << std::endl;
    return (out);
}