#ifndef TRADER_H
#define TRADER_H

#include <string>
#include <vector>
#include "item.h"
using namespace std;

Class Trader
{
private:
    string name;
    int coins;
    virtual char specialty = 0;
    virtual vector<Item> inventory;
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
    void AddToInventory(const Item stock);
    double GetPriceMultiplier() const;
    void SetPriceMultiplier(double mult);
};

#endif