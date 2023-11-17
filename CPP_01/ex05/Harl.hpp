#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <string>

class Harl{
    void        debug(void);
    void        info(void);
    void        warning(void);
    void        error(void);
    void        (Harl::*fun_ptr[4])(void);
    public: 
    void        ft_assign(void);
    Harl();
    ~Harl();
    void        complain(std::string level);
};

#endif