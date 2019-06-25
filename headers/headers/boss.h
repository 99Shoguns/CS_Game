#ifndef BOSS_H
#define BOSS_H

#include "monster.h"
using namespace std;

class Boss : public Monster
{
private:
    char specialty = 'B';
    double attackMultiplier;
    double defenseMultiplier;
    double hpMultiplier;
public:
    Boss();
    Boss(int lvl);
    double GetAttackMultiplier() const;
    void SetAttackMultiplier(double mult);
    double GetDefenseMultiplier() const;
    void SetDefenseMultiplier(double mult);
    double GetHpMultiplier() const;
    void SetHpMultiplier(double mult);
};

#endif