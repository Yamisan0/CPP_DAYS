#include "Form.hpp"



Form::Form(std::string name, bool is_signed, int to_sign, int to_exec):_name(name), _is_signed(is_signed), _grade_to_sign(to_sign), _grade_to_exec(to_exec)
{
    if (to_sign > 150 || to_exec > 150)
        throw(Form::GradeTooLowException());
    if (to_sign < 1 || to_sign < 1)
        throw(Form::GradeTooHighException());
}

Form::Form(Form& to_copy):_name(to_copy.getName()), _grade_to_sign(to_copy.getGradeSign()), _grade_to_exec(to_copy.getGradeExec()){
    *this = to_copy;
}

Form& Form::operator=(Form& rhs){
    if (this != &rhs)
    {
        this->_is_signed = rhs._is_signed;
    }
    return (*this);
}

Form::~Form(){}

std::string Form::getName(){
    return (this->_name);
}

bool Form::getSigned(){
    return (this->_is_signed);
}

int Form::getGradeSign(){
    return (this->_grade_to_sign);
}

int Form::getGradeExec(){
    return (this->_grade_to_exec);
}

void    Form::beSigned(Bureaucrat& signatory){
    if (signatory.getGrade() > this->_grade_to_sign)
        throw (Form::GradeTooLowException());
    this->_is_signed = true;
}

std::ostream&  operator << (std::ostream& out, Form& obj){
    out << "-------------------------------------------------------------------------------------" << std::endl;
    out << "Name:   " <<  obj.getName() << " | Signed:   "<< obj.getSigned() << " | Grade to Sign:   "<< obj.getGradeSign()<< " | Grade Exec:   "<< obj.getGradeExec() << std::endl;
    return (out);
}