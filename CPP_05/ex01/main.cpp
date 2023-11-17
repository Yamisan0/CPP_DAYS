
#include "Form.hpp"

int main( void )
{
    

    try{
        Bureaucrat bureauc("Aziz", 23);
        Form   formulaire("24b", true, 22, 50);

        bureauc.signForm(formulaire);

        std::cout << formulaire << std::endl;
    }catch(std::exception   &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}