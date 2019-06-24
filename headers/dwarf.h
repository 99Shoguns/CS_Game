#ifndef DWARF_H
#define DWARF_H

#include <string>
#include "ally.h"

class Dwarf : public Ally
{
private:
    char specialty = 'D';
    double defenseMultiplier;
public:
    Dwarf();
    Dwarf(string name);
    double GetDefenseMultiplier() const;
    void SetDefenseMultiplier(double mult);
};

#endif