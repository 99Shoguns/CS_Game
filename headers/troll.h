#ifndef TROLL_H
#define TROLL_H

#include "monster.h"
using namespace std;

class Troll : public Monster
{
private:
    char specialty = 'T';
    double hpMultiplier;
public:
    Troll();
    Troll(int lvl);
    double GetHpMultiplier() const;
    void SetHpMultiplier(double mult);
};

#endif