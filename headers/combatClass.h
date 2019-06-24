#ifndef COMBATCLASS_H
#define COMBATCLASS_H

class CombatClass
{
private:
    int virtual damageModifier = 0;
    char type;
    virtual char _class;
public:
    CombatClass();
    int GetDamageModifier() const;
    void SetDamageModifier(int dmg);
    char GetType() const;
    void SetType(char t);
    char GetClass() const;
    void SetClass(char c);
    int GetLevel() const;
    void SetLevel(int lvl);
};

#endif