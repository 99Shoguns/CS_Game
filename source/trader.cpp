#include "trader.h"
#include "item.h"
#include <iostream>
using namespace std;

Trader::Trader()
{
    name = "Trader";
    coins = 200;
    priceMultiplier = 1;
}
Trader::Trader(string name)
{
    this->name = name;
    coins = 200;
    priceMultiplier = 1;
}
string Trader::Getname() const
{
    return name;
}
void Trader::SetName(string n)
{
    name = n;
}
int Trader::GetCoins() const
{
    return coins;
}
void Trader::SetCoins(int c)
{
    coins += c;
}
Specialty Trader::GetSpecialty() const
{
    return specialty;
}
void Trader::SetSpecialty(Specialty spec)
{
    specialty = spec;
}
void Trader::ListInventory() const
{
    int size = inventory.size();
    cout << "Shop item stock:\n";
    for (int i = 0; i < size; i++){
        int j = i + 1;
        cout << j << ": " << inventory.at(i).GetQuantity() << ", " << inventory.at(i).GetName() << ", " << inventory.at(i).GetPrice() << endl;
    }
}
void Trader::ListPotions() const
{
    int size = potions.size();
    cout << "Shop potion stock:\n";
    for (int i = 0; i < size; i++){
        int j = i + 1;
        cout << j << ": " << potions.at(i).GetQuantity() << ", " << potions.at(i).GetName() << ", " << potions.at(i).GetPrice() << endl;
    }
}
void Trader::AddToInventory(Item stock)
{
    inventory.push_back(stock);
}
void Trader::RemoveFromInventory(Item stock)
{
    int size = inventory.size();
    for (int i = 0; i < size; i++){
        if (inventory.at(i).GetTypeIdentifier() == stock.GetTypeIdentifier()){//If there is already an item of new item's type equipped, switch them.
            if (inventory.at(i).GetName() == stock.GetName()){
                if (inventory.at(i).HasEffect() == stock.HasEffect()){
                    inventory.erase(inventory.begin() + i);
                }
                else{
                    cout << "That item is not in the inventory.\n";
                }
            }
            else{
                    cout << "That item is not in the inventory.\n";
            }
        }
        else{
                    cout << "That item is not in the inventory.\n";
        }
    }
}
void Trader::AddToPotions(Potion stock)
{
    potions.push_back(stock);
}
void Trader::RemoveFromPotions(Potion stock)
{
    int size = potions.size();
    for (int i = 0; i < size; i++){
        if (potions.at(i).GetTypeIdentifier() == stock.GetTypeIdentifier()){//If there is already an item of new item's type equipped, switch them.
            if (potions.at(i).GetName() == stock.GetName()){
                if (potions.at(i).HasEffect() == stock.HasEffect()){
                    potions.erase(potions.begin() + i);
                }
                else{
                    cout << "That item is not in the inventory.\n";
                }
            }
            else{
                    cout << "That item is not in the inventory.\n";
            }
        }
        else{
                    cout << "That item is not in the inventory.\n";
        }
    }
}
double Trader::GetPriceMultiplier() const
{
    return priceMultiplier;
}
void Trader::SetPriceMultiplier(double mult)
{
    priceMultiplier = 1;
}
Item Trader::TradeItem(int index)
{
    return inventory.at(index);
}
Potion Trader::TradePotion(int index)
{
    return potions.at(index);
}
