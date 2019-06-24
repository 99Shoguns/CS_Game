#ifndef ORK_H
#define ORK_H

#include "monster.h"
using namespace std;

class Ork : public Monster
{
private:
    char specialty = 'O';
    double defenseMultiplier;
public:
    Ork();
    Ork(int lvl);
    double GetDefenseMultiplier() const;
    void SetDefenseMultiplier(double mult);
};

#endif