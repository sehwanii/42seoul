#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
protected:
    std::string type;
public:
    Animal(/* args */);
    ~Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
};

Animal::Animal(/* args */)
{
}

Animal::~Animal()
{
}


#endif