#ifndef BOSS_H
#define BOSS_H

#include "monster.h"
using namespace std;

class Boss : public Monster
{
private:
    double attackMultiplier;
    double defenseMultiplier;
    double hpMultiplier;
    double levelMultiplier;
public:
    Boss();
    Boss(int lvl);
    double GetAttackMultiplier() const;
    void SetAttackMultiplier(double mult);
    double GetDefenseMultiplier() const;
    void SetDefenseMultiplier(double mult);
    double GetHpMultiplier() const;
    void SetHpMultiplier(double mult);
    double GetLevelMultiplier() const;
    void SetLevelMultiplier(double mult);
};

#endif