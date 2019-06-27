#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "item.h"
#include "monster.h"
#include "trader.h"
#include "potion.h"
using namespace std;

class Player
{
private:
    string name;
    Species species;
    CombatClass combatClass;
    int coins;
    int attack;
    int weaponDamage;
    int defense;
    int hp;
    int level;
    double xp;
    double levelxp;
    double combatModifier;
    vector<Item> backpack;
    vector<Item> equipment;
    vector<Potion> potionsBag;
public:
    Player();
    Player(string name);
    Player(string name, Species spec, CombatClass combat);
    string GetName() const;
    void SetName(string name);
    void AddXp(double xp);
    int GetLevel() const;
    void SetLevel(int num);
    void Combat(Monster *m);
    void Trade(Trader &t);
    void Equip(int index);
    void UnEquip(int index);
    void CheckBackpack() const;
    void CheckPotionsBag() const;
    void DrinkPotion(Potion &p);
    int GetAttack() const;
    void SetAttack(int att);
    int GetWeaponDamage() const;
    void SetWeaponDamage(int dmg);
    int GetDefense() const;
    void SetDefense(int def);
    int GetHp() const;
    void SetHp(int h);
    virtual int GetCoins() const;
    void SetCoins(int c);
    void SpendCoins(int c);
    Species GetSpecies();
    void SetSpecies(Species spec);
    CombatClass GetCombatClass();
    void SetCombatClass(CombatClass combat);
    double GetCombatModifier();
    void SetCombatModifier(CombatClass enemy);
};

#endif