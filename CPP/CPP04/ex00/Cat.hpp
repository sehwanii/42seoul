#ifndef Cat_HPP
#define Cat_HPP

#include <iostream>

class Cat
{
private:
    std::string type;

public:
    Cat(void);
    Cat(const Cat &obj);
    Cat &operator=(const Cat &obj);
    virtual ~Cat(void);
    virtual void makeSound(void) const;
    std::string getType(void) const;
};

#endif