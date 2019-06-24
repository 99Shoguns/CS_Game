#ifndef ELF_H
#define ELF_H

#include <string>
#include "ally.h"
using namespace std;

class Elf : public Ally
{
private:
    char specialty = 'E';
    double attackMultiplier;
public:
    Elf();
    Elf(string name);
    double GetAttackMultiplier() const;
    void SetAttackMultiplier(double mult);
};

#endif