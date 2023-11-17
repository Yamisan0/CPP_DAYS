#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        Harl harlito;

        harlito.ft_assign();
        harlito.complain(av[1]);
    }

    
}