#include "trader.h"
#include "item.h"
#include <iostream>
using namespace std;

Trader::Trader()
{
    name = "Trader";
    coins = 200;
    priceMultiplier = 1;
    Item sword("Sword", 50);
    sword.SetDamage(10);
    sword.SetTypeIdentifier(Weapon);
    AddToInventory(sword);
    Item helmet("First Helmet", 30);
    helmet.SetDefense(4);
    helmet.SetTypeIdentifier(Helmet);
    AddToInventory(helmet);
    Item bodyArmor("First BodyArmor", 100);
    bodyArmor.SetDefense(10);
    bodyArmor.SetTypeIdentifier(BodyArmor);
    AddToInventory(bodyArmor);
    Item legArmor("First LegArmor", 50);
    legArmor.SetDefense(6);
    legArmor.SetTypeIdentifier(LegArmor);
    AddToInventory(legArmor);
    Item boots("First Boots", 20);
    boots.SetDefense(2);
    boots.SetTypeIdentifier(Boots);
    AddToInventory(boots);
    Item gloves("First Gloves", 20);
    gloves.SetDefense(2);
    gloves.SetTypeIdentifier(Gloves);
    AddToInventory(gloves);
    Item shield("First Shield", 50);
    shield.SetDefense(6);
    shield.SetTypeIdentifier(Shield);
    AddToInventory(shield);
}
Trader::Trader(string name)
{
    this->name = name;
    coins = 200;
    priceMultiplier = 1;
    Item sword("Sword", 50);
    sword.SetDamage(10);
    sword.SetTypeIdentifier(Weapon);
    AddToInventory(sword);
    Item helmet("First Helmet", 30);
    helmet.SetDefense(4);
    helmet.SetTypeIdentifier(Helmet);
    AddToInventory(helmet);
    Item bodyArmor("First BodyArmor", 100);
    bodyArmor.SetDefense(10);
    bodyArmor.SetTypeIdentifier(BodyArmor);
    AddToInventory(bodyArmor);
    Item legArmor("First LegArmor", 50);
    legArmor.SetDefense(6);
    legArmor.SetTypeIdentifier(LegArmor);
    AddToInventory(legArmor);
    Item boots("First Boots", 20);
    boots.SetDefense(2);
    boots.SetTypeIdentifier(Boots);
    AddToInventory(boots);
    Item gloves("First Gloves", 20);
    gloves.SetDefense(2);
    gloves.SetTypeIdentifier(Gloves);
    AddToInventory(gloves);
    Item shield("First Shield", 50);
    shield.SetDefense(6);
    shield.SetTypeIdentifier(Shield);
    AddToInventory(shield);
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
    coins = c;
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
    int size = inventory.size();//Set size of inventory.
    cout << "Shop item stock:\n";
    for (int i = 0; i < size; i++){//List out inventory items.
        int j = i + 1;//Item numbering.
        cout << j << ": " << inventory.at(i).GetQuantity() << ", " << inventory.at(i).GetName() << ", " << inventory.at(i).GetPrice() << endl;
    }
}
void Trader::ListPotions() const
{
    int size = potions.size();//Set size of potions supply.
    cout << "Shop potion stock:\n";
    for (int i = 0; i < size; i++){//List out potions.
        int j = i + 1;//Potion numbering
        cout << j << ": " << potions.at(i).GetQuantity() << ", " << potions.at(i).GetName() << ", " << potions.at(i).GetPrice() << endl;
    }
}
void Trader::AddToInventory(Item stock)
{
    inventory.push_back(stock);
}
void Trader::RemoveFromInventory(Item stock)
{
    int size = inventory.size();//Set size of inventory.
    for (int i = 0; i < size; i++){
        if (inventory.at(i).GetTypeIdentifier() == stock.GetTypeIdentifier()){//If there is already an item of new item's type equipped, switch them.
            if (inventory.at(i).GetName() == stock.GetName()){//If the two item names are the smae
                if (inventory.at(i).HasEffect() == stock.HasEffect()){//And if the two items have effects
                    inventory.erase(inventory.begin() + i);//Erase that item from the inventory
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
    potions.push_back(stock);//Add a potion to potion supply
}
void Trader::RemoveFromPotions(Potion stock)
{
    int size = potions.size();//Set size of potions stock.
    for (int i = 0; i < size; i++){
        if (potions.at(i).GetTypeIdentifier() == stock.GetTypeIdentifier()){//If there is already an item of new item's type equipped, switch them.
            if (potions.at(i).GetName() == stock.GetName()){//If the names are the same
                if (potions.at(i).HasEffect() == stock.HasEffect()){//If the effects are the same
                    potions.erase(potions.begin() + i);//Erase that item
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