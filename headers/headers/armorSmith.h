#ifndef ARMORSMITH_H
#define ARMORSMITH_H

#include <vector>
#include <string>
#include "armor.h"
using namespace std;

class ArmorSmith : public Trader
{
private:
    char specialty = 'A';
    vector<Armor> inventory;
public:
    ArmorSmith();
    ArmorSmith(string name);
};

#endif