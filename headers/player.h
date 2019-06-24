#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "item.h"
#include "monster.h"
#include "trader.h"
#include "guide.h"
#include "potion.h"
using namespace std;

class Player
{
private:
    string name;
    int coins;
    int attack;
    int weaponDamage;
    int defense;
    int hp;
    int level;
    double xp;
    double levelxp;
    vector<Item> backpack;
    vector<Item> equipment;
public:
    Player();
    Player(string name);
    string GetName() const;
    void SetName(string name);
    void AddXp(double xp);
    double GetLevelXP() const;
    void AddLevelXp(double xp);
    int GetLevel() const;
    void AddLevel(int num);
    void Combat(const Monster m);
    void Trade(const Trader t);
    void Talk(const Guide g);
    void Equip(const Item i);
    void UnEquip(const Item i);
    void DrinkPotion(const Potion p);
    void AddToBackpack(const Item i);
    void CheckBackpack() const;
    int GetAttack() const;
    void SetAttack(int att);
    int GetWeaponDamage() const;
    void SetWeaponDamage(int dmg);
    int GetDefense() const;
    void SetDefense(int def);
    int GetHp() const;
    void SetHp(int h);
    int GetCoins() const;
    void AddCoins(int c);
    void SpendCoins(int c);
};

#endif