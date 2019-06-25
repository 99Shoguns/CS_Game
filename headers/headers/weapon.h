#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "item.h"
using namespace std;

class Weapon : public Item
{
private:
    int damage;
public:
    Weapon();
    Weapon(string name);
    Weapon(string name, float price);
    int GetDamage() const;
    void SetDamage(int dmg);
};

#endif