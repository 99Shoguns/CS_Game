#ifndef WIZARD_H
#define WIZARD_H

#include "combatClass.h"
using namespace std;

class Wizard : public CombatClass
{
private:
    int damageModifier;
    char type = 'W';
public:
    Wizard();
};

#endif