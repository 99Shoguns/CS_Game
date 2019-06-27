#ifndef POTION_H
#define POTION_H

#include <string>
#include "item.h"
using namespace std;

enum PotionType {HealthPotion, XpPotion};

class Potion : public Item
{
private:
    int quantity;
    double price;
    double effectModifier;
    PotionType potionType;
public:
    Potion();
    Potion(string name);
    Potion(string name, double price);
    void ModifyQuantity(int num);
    void SetEffect(double change);
    bool HasEffect() const;
    double GetEffect();
    double GetEffectModifier() const;
    void SetEffectModifier(double num);
    bool SameAs(Potion p);
    PotionType GetPotionType();
    void SetPotionType(PotionType ptype);
};

#endif