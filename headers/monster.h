#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <iostream>
using namespace std;

enum Species {Elf, Dwarf, Man, Goblin, Ork, Troll};
enum CombatClass {Warrior, Archer, Wizard, None};

class Monster
{
protected:
    Species species;
    CombatClass combatClass;
    string name;
    int attack;
    int weaponDamage;
    int defense;
    int hp;
    int level;
    double xp;
    int coins;
public:
    Monster();
    Monster(int level);
    Monster(int level, Species spec, CombatClass combat);
    int GetAttack() const;
    void SetAttack(int att);
    int GetWeaponDamage() const;
    void SetWeaponDamage(int dmg);
    int GetDefense() const;
    void SetDefense(int def);
    int GetHp() const;
    void SetHp(int h);
    int GetLevel() const;
    void SetLevel(int lvl);
    double GetXp() const;
    void SetXp(double xp);
    int GetCoins() const;
    void SetCoins(int num);
    Species GetSpecies();
    void SetSpecies(Species spec);
    CombatClass GetCombatClass();
    void SetCombatClass(CombatClass combat);
};

#endif