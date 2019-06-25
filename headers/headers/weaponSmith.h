#ifndef WEAPONSMITH_H
#define WEAPONSMITH_H

#include "weapon.h"
#include <vector>
#include <string>
using namespace std;

class WeaponSmith : public Trader
{
private:
    char specialty = 'W';
    vector<Weapon> inventory;
public:
    WeaponSmith();
    Weaponsmith(string name);
};

#endif