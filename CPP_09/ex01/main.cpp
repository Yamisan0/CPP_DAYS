#include "RPN.hpp"

int main(int ac, char **argv){
    
    RPN rpn;
    int result;

    if (ac != 2)
        return (std::cout << "Error: Expected 2 arguments!" << std::endl, 0 );

    result = rpn.calculate(argv[1]);

    if (rpn.getError() == 1)
        return 0;
    std::cout << result << std::endl;


}