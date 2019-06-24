#ifndef GOBLIN_H
#define GOBLIN_H

#include "monster.h"
using namespace std;

class Goblin : public Monster
{
private:
    char specialty = 'G';
    double attackMultiplier;
public:
    Goblin();
    Goblin(int level);
    double GetAttackMultiplier() const;
    void SetAttackMultiplier(double mult);
};

#endif