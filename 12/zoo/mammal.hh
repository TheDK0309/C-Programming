#ifndef MAMMAL_HH
#define MAMMAL_HH

#endif // MAMMAL_HH
#include "animal.hh"

class Mammal: public Animal
{
public:
    Mammal();
    void suckle(std::ostream& output);
};
