#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal
{
private:
    std::string type;

public:
    WrongCat(void);
    WrongCat(const WrongCat &obj);
    WrongCat &operator=(const WrongCat &obj);
    virtual ~WrongCat(void);
    virtual void makeSound(void) const;
    std::string getType(void) const;
};

#endif