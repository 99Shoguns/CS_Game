#ifndef WARRIOR_H
#define WARRIOR_H

#include "combatClass.h"
using namespace std;

class Warrior : public CombatClass
{
private:
    int damageModifier;
    char type = 'W';
public:
    Warrior();
};

#endif