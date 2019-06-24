#ifndef ARMOR_H
#define ARMOR_H

#include <string>
#include "item.h"
using namespace std;

class Armor : public Item
{
private:
    int defense;
public:
    Armor();
    Armor(string name);
    Armor(string name, float price);
    int GetDefense() const;
    void SetDefense(int def);
};

#endif