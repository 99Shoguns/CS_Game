#ifndef ARCHER_H
#define ARCHER_H

#include "combatClass.h"
using namespace std;

class Archer : public CombatClass
{
private:
    int damageModifier;
    char type = 'A';
public:
    Archer();
};

#endif