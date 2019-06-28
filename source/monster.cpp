#include "monster.h"
#include <ctime>
#include <cstdlib>
using namespace std;

Monster::Monster()
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
    int r2 = rand() % 4;
    switch(r2) {//Randomize combat class when monster is created.
        case 0: combatClass = Warrior;
            break;
        case 1: combatClass = Archer;
            break;
        case 2: combatClass = Wizard;
            break;
        case 3: combatClass = None;
            break;
    }
    name = "Enemy";
    attack = r2; //Random attack from 0-3. (Allows for 'noob' enemies like a chicken)
    weaponDamage = r2; //Random weapon damage from 0-3.
    defense = r2; //Random defense from 0-3.
    int r3 = rand() % 5 + 5;
    hp = r3; //Random hp from 5-10.
    int r4 = rand() % 3 + 1;
    level = r4; //Random level from 1-3.
    int r5 = rand() % 45 + 5;
    xp = r5; //Random xp reward from 5-50.
    coins = r5; //Random coin reward from 5-50.
}
Monster::Monster(int level)
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
    int r2 = rand() % 4;
    switch(r2) {//Randomize combat class when monster is created.
        case 0: combatClass = Warrior;
            break;
        case 1: combatClass = Archer;
            break;
        case 2: combatClass = Wizard;
            break;
        case 3: combatClass = None;
            break;
    }
    name = "Enemy";
    attack = r2; //Random attack from 0-3. (Allows for 'noob' enemies like a chicken)
    weaponDamage = r2; //Random weapon damage from 0-3.
    defense = r2; //Random defense from 0-3.
    int r3 = rand() % 5 + 5;
    hp = r3; //Random hp from 5-10.
    this->level = level; //Set level equal to given level.
    int r4 = rand() % 45 + 5;
    xp = r4; //Random xp reward from 5-50.
    coins = r4; //Random coin reward from 5-50.
}
Monster::Monster(int level, Species spec, CombatClass combat)
{
    species = spec; //Species equals given species
    combatClass = combat; //Combat Class equals given combat class
    name = "Enemy";
    srand(time(NULL));
    int r1 = rand() % 4;
    attack = r1; //Random attack from 0-3. (Allows for 'noob' enemies like a chicken)
    weaponDamage = r1; //Random weapon damage from 0-3.
    defense = r1; //Random defense from 0-3.
    int r2 = rand() % 5 + 5;
    hp = r2; //Random hp from 5-10.
    this->level = level; //Set level equal to given level.
    int r3 = rand() % 45 + 5;
    xp = r3; //Random xp reward from 5-50.
    coins = r3; //Random coin reward from 5-50.
}
int Monster::GetAttack() const
{
    return attack;
}
void Monster::SetAttack(int att)
{
    attack = att;
}
int Monster::GetWeaponDamage() const
{
    return weaponDamage;
}
void Monster::SetWeaponDamage(int dmg)
{
    weaponDamage = dmg;
}
int Monster::GetDefense() const
{
    return defense;
}
void Monster::SetDefense(int def)
{
    defense = def;
}
int Monster::GetHp() const
{
    return hp;
}
void Monster::SetHp(int h)
{
    hp = h;
}
int Monster::GetLevel() const
{
    return level;
}
void Monster::SetLevel(int lvl)
{
    level = lvl;
}
double Monster::GetXp() const
{
    return xp;
}
void Monster::SetXp(double xp)
{
    this->xp = xp;
}
int Monster::GetCoins() const
{
    return coins;
}
void Monster::SetCoins(int num)
{
    coins = num;
}
Species Monster::GetSpecies()
{
    return species;
}
void Monster::SetSpecies(Species spec)
{
    species = spec;
}
CombatClass Monster::GetCombatClass()
{
    return combatClass;
}
void Monster::SetCombatClass(CombatClass combat)
{
    combatClass = combat;
}