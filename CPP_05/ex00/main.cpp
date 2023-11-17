#include "Bureaucrat.hpp"

int main( void )
{
    try {
        Bureaucrat bureaucrat("ash", 150);

        std::cout << bureaucrat;

        bureaucrat.decrem();
        bureaucrat.increm();
        std::cout << bureaucrat;
        bureaucrat.decrem();
        std::cout << bureaucrat;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}