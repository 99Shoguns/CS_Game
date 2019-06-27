#ifndef ITEM_H
#define ITEM_H

enum Type {Weapon, Helmet, BodyArmor, LegArmor, Boots, Gloves, Shield};

#include <string>
using namespace std;

class Item
{
protected:
    string name;
    Type typeIdentifier;
    int quantity;
    double price;
    int damage;
    int defense;
    double effect;
    bool hasEffect;
    double effectModifier;
    bool isPotion;
public:
    Item();
    Item(string name);
    Item(string name, double price);
    string GetName() const;
    void SetName(string n);
    Type GetTypeIdentifier();
    void SetTypeIdentifier(Type t);
    int GetQuantity() const;
    void SetQuantity(int qty);
    float GetPrice() const;
    void SetPrice(double p);
    int GetDamage() const;
    void SetDamage(int dmg);
    int GetDefense() const;
    void SetDefense(int def);
    virtual void SetEffect(bool eff);
    virtual bool HasEffect() const;
    virtual double GetEffect();
    void ActivateEffect();
    virtual double GetEffectModifier() const;
    virtual void SetEffectModifier(double mod);
    bool Compare(Item item);
    bool IsPotion() const;
};

#endif