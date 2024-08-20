#ifndef Dog_HPP
#define Dog_HPP

#include <iostream>

class Dog
{
private:
    std::string type;

public:
    Dog(void);
    Dog(const Dog &obj);
    Dog &operator=(const Dog &obj);
    virtual ~Dog(void);
    virtual void makeSound(void) const;
    std::string getType(void) const;
};

#endif