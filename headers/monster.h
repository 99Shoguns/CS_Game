#ifndef MONSTER_H
#define MONSTER_H

#include <string>
using namespace std;

class Monster
{
private:
    virtual char specialty = 0;
    int attack;
    int weaponDamage;
    int defense;
    int hp;
    int level;
public:
    Monster();
    Monster(int level);
    int GetAttack() const;
    void SetAttack(int att);
    int GetWeaponDamage() const;
    void SetWeaponDamage(int dmg);
    int GetDefense() const;
    void SetDefense();
    int GetHp() const;
    void SetHp(int h);
    int GetLevel() const;
    void SetLevel(int lvl);
};

#endif