#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):AForm("RobotomyRequestForm", false, 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src):AForm(src), _target( src._target){}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& rhs){
    (void)rhs;
    return (*this);
}

void RobotomyRequestForm::execute( const Bureaucrat& executor) const{
    if (this->getSigned() == false)
        throw AForm::NotSignedException();

    if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowException();
    else {
        static int i = 0;
        if (i % 2 == 0)
            std::cout << "BRRRRRRRRRR! " << this->_target << " has been robotomized successfully" << std::endl;
        else
            std::cout << "The robotomy have failed" << std::endl;
        i++;
    }
}