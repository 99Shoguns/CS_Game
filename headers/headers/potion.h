#ifndef POTION_H
#define POTION_H

#include <string>
#include "item.h"
using namespace std;

class Potion : public Item
{
private:
    int quantity;
    int effect;
    double effectMultiplier;
public:
    Potion();
    Potion(string name);
    Potion(string name, float price);
    int GetQuantity() const;
    void ModifyQuantity(int num);
    void SetEffect(int eff);
    void ActivateEffect();
    double GetEffectMultiplier() const;
    void SetEffectMultiplier(double mult);
};

#endif