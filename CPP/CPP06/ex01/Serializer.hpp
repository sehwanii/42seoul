#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <iomanip>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
    private:
    
    public:
        Serializer(void);
        Serializer(Serializer const &src);
        ~Serializer(void);
        Serializer &operator=(Serializer const &src);

        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif