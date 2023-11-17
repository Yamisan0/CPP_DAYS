#pragma once

#include "AForm.hpp"

class Intern{
    public:

    Intern();
    Intern(const Intern& src);
    Intern& operator = (const Intern& rhs);
    ~Intern();


    AForm * makeForm(std::string form_name, std::string target);
};