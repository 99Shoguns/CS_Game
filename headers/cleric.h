#ifndef CLERIC_H
#define CLERIC_H

#include <string>
#include <vector>
#include "potion.h"
#include "trader.h"
using namespace std;

class Cleric : public Trader
{
private:
    char specialty = 'C';
    vector<Potion> inventory;
public:
    Cleric();
    Cleric(string name);
};

#endif