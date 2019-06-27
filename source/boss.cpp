#include "boss.h"
#include "cstdlib"
#include "ctime"
using namespace std;

Boss::Boss()
{
    srand(time(NULL));
    int r1 = rand() % 6;
    switch(r1) {//Randomize species when monster is created.
        case 0: species = Elf;
            break;
        case 1: species = Dwarf;
            break;
        case 2: species = Man;
            break;
        case 3: species = Goblin;
            break;
        case 4: species = Ork;
            break;
        case 5: species = Troll;
    }
    name = "Boss";
    int r2 = rand() % 4 + 1;
    attack = (r2 * GetAttackMultiplier()); //Random attack from 1-4 times attack multiplier.
    weaponDamage = (r2 * GetAttackMultiplier()); //Random weapon damage from 1-4 times attack multiplier.
    defense = (r2 * GetAttackMultiplier()); //Random defense from 1-4 times defense multiplier.
    int r3 = rand() % 5 + 5;
    hp = (r3 * GetHpMultiplier()); //Random hp from 5-10 times hp multiplier.
    int r4 = rand() % 10 + 1;
    level = (r4 * GetLevelMultiplier()); //Random level from 1-10 times level multiplier.
    int r5 = rand() % 45 + 5;
    xp = (r5 * GetHpMultiplier()); //Random xp reward from 5-50 times hp multiplier.
    coins = (r5 * GetHpMultiplier()); //Random coin reward from 5-50 times hp multiplier.
}
Boss::Boss(int lvl)
{
    srand(time(NULL));
    int r1 = rand() % 6;
    switch(r1) {//Randomize species when monster is created.
        case 0: species = Elf;
            break;
        case 1: species = Dwarf;
            break;
        case 2: species = Man;
            break;
        case 3: species = Goblin;
            break;
        case 4: species = Ork;
            break;
        case 5: species = Troll;
    }
    name = "Boss";
    int r2 = rand() % 4 + 1;
    attack = (r2 * GetAttackMultiplier()); //Random attack from 1-4 times attack multiplier.
    weaponDamage = (r2 * GetAttackMultiplier()); //Random weapon damage from 1-4 times attack multiplier.
    defense = (r2 * GetAttackMultiplier()); //Random defense from 1-4 times defense multiplier.
    int r3 = rand() % 5 + 5;
    hp = (r3 * GetHpMultiplier()); //Random hp from 5-10 times hp multiplier.
    int r4 = rand() % 10 + 1;
    level = lvl; //Set level equal to given lvl
    int r5 = rand() % 45 + 5;
    xp = (r5 * GetHpMultiplier()); //Random xp reward from 5-50 times hp multiplier.
    coins = (r5 * GetHpMultiplier()); //Random coin reward from 5-50 times hp multiplier.
}
double Boss::GetAttackMultiplier() const
{
    return attackMultiplier;
}
void Boss::SetAttackMultiplier(double mult)
{
    attackMultiplier = mult;
}
double Boss::GetDefenseMultiplier() const
{
    return defenseMultiplier;
}
void Boss::SetDefenseMultiplier(double mult)
{
    defenseMultiplier = mult;
}
double Boss::GetHpMultiplier() const
{
    return hpMultiplier;
}
void Boss::SetHpMultiplier(double mult)
{
    hpMultiplier = mult;
}
double Boss::GetLevelMultiplier() const
{
    return levelMultiplier;
}
void Boss::SetLevelMultiplier(double mult)
{
    levelMultiplier = mult;
}