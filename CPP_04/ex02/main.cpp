#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    // Animal* animal[4] = { new Cat(), new Cat(), new Dog(), new Dog()};

    // for (int i = 0; i < 4; i++)
    // {
    //     delete animal[i];
    // }
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

}