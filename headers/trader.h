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
    /*
    Item purchase = t.ListInventory(ans);
    cout << "So you want to purchase a " << purchase.GetName() << "? (1 to confirm, 2 to cancel)\n";
    cin >> ans;//Comfirm purchase
    if (ans == 1){//Implement Trade function to verify player input and debug any issues within Trader class functions///////////////////////////////////////////////////////////
        if (coins > purchase.GetPrice()){
            coins -= purchase.GetPrice();//Pay for item
            backpack.push_back(purchase);//Add item to backpack
        }
        else{//If player can't afford item
            cout << "You do not have enough coins for this purchase!\n";
        }
    }
    else if (ans == 2){//If player cancels trade
        cout << "You don't want to purchase this item.\n";
    }
    else{//Invalid input
        cout << "You have input an invalid answer. You need to input a 1 to confirm, or a 2 to cancel.\n";
    }
    */
};

#endif