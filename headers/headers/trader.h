#ifndef TRADER_H
#define TRADER_H

#include <string>
#include <vector>
#include "item.h"
using namespace std;

class Trader
{
private:
    string name;
    int coins;
    char specialty;
    vector<Item> inventory;
    double priceMultiplier;
public:
    Trader();
    Trader(string name);
    string Getname() const;
    void SetName(string n);
    int GetCoins() const;
    void SetCoins(int c);
    char GetSpecialty() const;
    void SetSpecialty(char spec);
    void ListInventory() const;
    Item ListInventory(int index) const;
    void AddToInventory(const Item stock);
    double GetPriceMultiplier() const;
    void SetPriceMultiplier(double mult);
};

#endif