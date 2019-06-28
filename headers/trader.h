#ifndef TRADER_H
#define TRADER_H

#include <string>
#include <vector>
#include "item.h"
#include "potion.h"
using namespace std;

enum Specialty {WeaponSmith, ArmorSmith, Cleric};

class Trader
{
private:
    string name;
    int coins;
    Specialty specialty;
    vector<Item> inventory;
    vector<Potion> potions;
    double priceMultiplier;
public:
    Trader();
    Trader(string name);
    string Getname() const;
    void SetName(string n);
    int GetCoins() const;
    void SetCoins(int c);
    Specialty GetSpecialty() const;
    void SetSpecialty(Specialty spec);
    void ListInventory() const;
    void ListPotions() const;
    void AddToInventory(Item stock);
    void RemoveFromInventory(Item stock);
    void AddToPotions(Potion stock);
    void RemoveFromPotions(Potion stock);
    double GetPriceMultiplier() const;
    void SetPriceMultiplier(double mult);
    Item TradeItem(int index);
    Potion TradePotion(int index);
   
};

#endif