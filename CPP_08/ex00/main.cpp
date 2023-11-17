#include "easyfind.hpp"

int main(void)
{
    std::list<int> contain = {1, 2, 3, 4, 5};

    std::list<int>::iterator iter;
    int nb = 4;

    for (iter = contain.begin(); iter != contain.end(); ++iter)
        std::cout << *iter << std::endl;

    std::list<int>::iterator result = easyfind(contain, nb);

    if (result != contain.end()) {
        std::cout << "Position of the number " << nb << " in the container: " << std::distance(contain.begin(), result) << std::endl;
    } else {
        std::cout << "Value not found in the container." << std::endl;
    }

    std::vector<std::string> vec = { "salut", "tout", "le", "monde"};
    std::vector<std::string>::iterator finding;
    
    std::string str = "le";
    finding = easyfind(vec, str);

    if (finding != vec.end())
        std::cout << "Position of " << str << " in the container: " << std::distance(vec.begin(), finding) <<  std::endl;
    else
        std::cout << "Value not found in the container." << std::endl;
    

    return 0;
}
