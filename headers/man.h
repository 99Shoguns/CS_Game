#ifndef MAN_H
#define MAN_H

#include <string>
#include "ally.h"
using namespace std;

class Man : public Ally
{
private:
    char specialty = 'M';
    double hpMultiplier;
public:
    Man();
    Man(string name);
    double GetHpMultiplier() const;
    void SetHpMultiplier(double mult);
};

#endif