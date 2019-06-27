#include "item.h"
#include "potion.h"
#include "typeinfo"
#include <string>
#include <iostream>
using namespace std;

//Constructors
Item::Item()
{
    name = "Default Item";
    quantity = 1;
    price = 10;
    damage = 0;
    defense = 0;
}
Item::Item(string name)
{
    this->name = name;
    quantity = 1;
    price = 10;
    damage = 0;
    defense = 0;
}
Item::Item(string name, double price)
{
    this->name = name;
    quantity = 1;
    this->price = price;
    damage = 0;
    defense = 0;
}

//Data functions
string Item::GetName() const
{
    return name;
}
void Item::SetName(string n)
{
    name = n;
}
Type Item::GetTypeIdentifier()
{
    return typeIdentifier;
}
void Item::SetTypeIdentifier(Type t)
{
    typeIdentifier = t;
}
int Item::GetQuantity() const
{
    return quantity;
}
void Item::SetQuantity(int qty)
{
    quantity = qty;
}
float Item::GetPrice() const
{
    return price;
}
void Item::SetPrice(double p)
{
    price = p;
}
int Item::GetDamage() const
{
    return damage;
}
void Item::SetDamage(int dmg)
{
    damage = dmg;
}
int Item::GetDefense() const
{
    return defense;
}
void Item::SetDefense(int def)
{
    defense = def;
}

//Effect
void Item::SetEffect(bool eff)
{
    effect = eff;
}
bool Item::HasEffect() const
{
    return hasEffect;
}
double Item::GetEffect()
{
    return effect;
}
void Item::ActivateEffect()
{//Weapon, Helmet, BodyArmor, LegArmor, Boots, Gloves, Shield
    if (typeIdentifier == Weapon)
    {
        damage *= effectModifier;
    }
    else if (typeIdentifier == Helmet || typeIdentifier == BodyArmor || typeIdentifier == LegArmor || typeIdentifier == Boots || typeIdentifier == Gloves || typeIdentifier == Shield)
    {//If typeIdentifier is equal to one of the types of armor.
        defense *= effectModifier;
    }
}
double Item::GetEffectModifier() const
{
    return effectModifier;
}
void Item::SetEffectModifier(double mod)
{
    effectModifier = mod;
}

//Check if two items are the same thing.
bool Item::Compare(Item item)
{   
    if (IsPotion())
    {
        cout << "Error. These items are potions. Use the potion SameAs(Potion p) function.\n";
        return false;
    }
    bool normalItems;
    //Check to see if all data except the quantity are the same for both items for a normal (non-potion) item.
    if (GetName() == item.GetName())//If the names are the same
    {
        if (GetPrice() == item.GetPrice())//And if the prices are the same
        {
            if (GetDamage() == item.GetDamage())//And if the damages are the same
            {
                if (GetDefense() == item.GetDefense())//And if the defenses are the same
                {
                    return true;//Then the items are the same
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

//Check if an item is a potion
bool Item::IsPotion() const
{
    return isPotion;
}