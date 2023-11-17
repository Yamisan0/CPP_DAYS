#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl << std::endl;
}

void    Harl::ft_assign()
{
    fun_ptr[0] = &Harl::debug;
    fun_ptr[1] = &Harl::info;
    fun_ptr[2] = &Harl::warning;
    fun_ptr[3] = &Harl::error;
}

void    Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            switch (level[0])
            {
                case ('D'):
                std::cout << "[DEBUG]" << std::endl;
                (this->*fun_ptr[0])();
                case ('I'):
                std::cout << "[INFO]" << std::endl;
                (this->*fun_ptr[1])();
                case ('W'):
                std::cout << "[WARNING]" << std::endl;
                (this->*fun_ptr[2])();
                case ('E'):
                std::cout << "[ERROR]" << std::endl;
                (this->*fun_ptr[3])();
                break;
            }
            return ;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}