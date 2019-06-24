#ifndef ALLY_H
#define ALLY_H

#include <string>
#include <vector>
#include "item.h"
#include "monster.h"
using namespace std;

class Ally
{
private:
    string name;
    virtual char specialty = 0;
    int attack;
    int weaponDamage;
    int defense;
    int hp;
    int level;
    vector<Item> equipment;
public:
    Ally();
    Ally(string name);
    string GetName() const;
    void SetName(string name);
    char GetSpecialty() const;
    void SetSpecialty(char c);
    int GetLevel() const;
    void AddLevel(int num);
    void Combat(const Monster m);
    void Talk();
    void Equip(const Item i);
    void Unequip(const Item i);
    int GetAttack() const;
    void SetAttack(int att);
    int GetWeaponDamage() const;
    void SetWeaponDamage(int dmg);
    int GetDefense() const;
    int SetDefense(int def);
    int GetHp() const;
    void SetHp(int h);
};

#endif