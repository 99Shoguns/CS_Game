#include "potion.h"
using namespace std;

Potion::Potion()
{
    name = "Potion";
    quantity = 1;
    price = 10;
    effectModifier = 1;
    isPotion = true;
}
Potion::Potion(string name)
{
    this->name = name;
    quantity = 1;
    price = 10;
    effectModifier = 1;
    isPotion = true;
}
Potion::Potion(string name, double price)
{
    this->name = name;
    quantity = 1;
    this->price = price;
    effectModifier = 1;
    isPotion = true;
}
void Potion::ModifyQuantity(int num)
{
    quantity += num;
}

//Effect functions
void Potion::SetEffect(double change)
{
    effect = change;
}
bool Potion::HasEffect() const
{
    return true;
}
double Potion::GetEffect()
{
    return (effect * effectModifier);
}
double Potion::GetEffectModifier() const
{
    return effectModifier;
}
void Potion::SetEffectModifier(double num)
{
    effectModifier = num;
}
PotionType Potion::GetPotionType()
{
    return potionType;
}
void Potion::SetPotionType(PotionType ptype)
{
    potionType = ptype;
}

//Check if two potions are the same
bool Potion::SameAs(Potion p)
{
    if (GetPrice() == p.GetPrice() && GetEffectModifier() == p.GetEffectModifier() && GetPotionType() == p.GetPotionType())
        return true;
    else
        return false;
}