#ifndef HARL_FILTER_H
# define HARL_FILTER_H

#include <string>
#include <iostream>

class Harl{
    void        debug(void);
    void        info(void);
    void        warning(void);
    void        error(void);
    void        (Harl::*fun_ptr[4])(void);
    public: 
    Harl();
    ~Harl();
    void        ft_assign(void);
    void        complain(std::string level);
};


#endif