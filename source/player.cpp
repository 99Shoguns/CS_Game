#include "player.h"
#include "monster.h"
#include "boss.h"
#include "trader.h"
#include "item.h"
#include "potion.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//Create default Player and Player with a name parameter.
Player::Player()
{
    name = "Default";
    coins = 0;
    attack = 1;
    weaponDamage = 0;
    defense = 1;
    hp = 10;
    maxHp = 10;
    level = 1;
    xp = 0;
    levelxp = 50;
    Item firstSword("First Sword", 20);
    firstSword.SetDamage(4);
    firstSword.SetTypeIdentifier(Weapon);
    Item firstHelmet("First Helmet", 15);
    firstHelmet.SetDefense(2);
    firstHelmet.SetTypeIdentifier(Helmet);
    Item firstBodyArmor("First BodyArmor", 50);
    firstBodyArmor.SetDefense(5);
    firstBodyArmor.SetTypeIdentifier(BodyArmor);
    Item firstLegArmor("First LegArmor", 25);
    firstLegArmor.SetDefense(3);
    firstLegArmor.SetTypeIdentifier(LegArmor);
    Item firstBoots("First Boots", 10);
    firstBoots.SetDefense(1);
    firstBoots.SetTypeIdentifier(Boots);
    Item firstGloves("First Gloves", 10);
    firstGloves.SetDefense(1);
    firstGloves.SetTypeIdentifier(Gloves);
    Item firstShield("First Shield", 25);
    firstShield.SetDefense(3);
    firstShield.SetTypeIdentifier(Shield);
    cout << "Player gear added.\n";
    //Add gear to backpack and then equip it
    equipment.push_back(firstSword);
    equipment.push_back(firstHelmet);
    equipment.push_back(firstBodyArmor);
    equipment.push_back(firstLegArmor);
    equipment.push_back(firstBoots);
    equipment.push_back(firstGloves);
    equipment.push_back(firstShield);
}
Player::Player(string name)
{
    this->name = name;
    coins = 0;
    attack = 1;
    weaponDamage = 0;
    defense = 1;
    hp = 10;
    maxHp = 10;
    level = 1;
    xp = 0;
    levelxp = 50;
    Item firstSword("First Sword", 20);
    firstSword.SetDamage(4);
    firstSword.SetTypeIdentifier(Weapon);
    Item firstHelmet("First Helmet", 15);
    firstHelmet.SetDefense(2);
    firstHelmet.SetTypeIdentifier(Helmet);
    Item firstBodyArmor("First BodyArmor", 50);
    firstBodyArmor.SetDefense(5);
    firstBodyArmor.SetTypeIdentifier(BodyArmor);
    Item firstLegArmor("First LegArmor", 25);
    firstLegArmor.SetDefense(3);
    firstLegArmor.SetTypeIdentifier(LegArmor);
    Item firstBoots("First Boots", 10);
    firstBoots.SetDefense(1);
    firstBoots.SetTypeIdentifier(Boots);
    Item firstGloves("First Gloves", 10);
    firstGloves.SetDefense(1);
    firstGloves.SetTypeIdentifier(Gloves);
    Item firstShield("First Shield", 25);
    firstShield.SetDefense(3);
    firstShield.SetTypeIdentifier(Shield);
    cout << "Player gear added.\n";
    //Add gear to backpack and then equip it
    equipment.push_back(firstSword);
    equipment.push_back(firstHelmet);
    equipment.push_back(firstBodyArmor);
    equipment.push_back(firstLegArmor);
    equipment.push_back(firstBoots);
    equipment.push_back(firstGloves);
    equipment.push_back(firstShield);
}
Player::Player(string name, Species spec, CombatClass combat)
{
    this->name = name;
    species = spec;
    combatClass = combat;
    coins = 0;
    attack = 1;
    weaponDamage = 0;
    defense = 1;
    hp = 10;
    maxHp = 10;
    level = 1;
    xp = 0;
    levelxp = 50;
    Item firstSword("First Sword", 20);
    firstSword.SetDamage(4);
    firstSword.SetTypeIdentifier(Weapon);
    Item firstHelmet("First Helmet", 15);
    firstHelmet.SetDefense(2);
    firstHelmet.SetTypeIdentifier(Helmet);
    Item firstBodyArmor("First BodyArmor", 50);
    firstBodyArmor.SetDefense(5);
    firstBodyArmor.SetTypeIdentifier(BodyArmor);
    Item firstLegArmor("First LegArmor", 25);
    firstLegArmor.SetDefense(3);
    firstLegArmor.SetTypeIdentifier(LegArmor);
    Item firstBoots("First Boots", 10);
    firstBoots.SetDefense(1);
    firstBoots.SetTypeIdentifier(Boots);
    Item firstGloves("First Gloves", 10);
    firstGloves.SetDefense(1);
    firstGloves.SetTypeIdentifier(Gloves);
    Item firstShield("First Shield", 25);
    firstShield.SetDefense(3);
    firstShield.SetTypeIdentifier(Shield);
    cout << "Player gear added.\n";
    //Add gear to backpack and then equip it
    equipment.push_back(firstSword);
    equipment.push_back(firstHelmet);
    equipment.push_back(firstBodyArmor);
    equipment.push_back(firstLegArmor);
    equipment.push_back(firstBoots);
    equipment.push_back(firstGloves);
    equipment.push_back(firstShield);
}

//Name functions
string Player::GetName() const
{
    return name;
}
void Player::SetName(string name)
{
    this->name = name;
}

//Xp function
void Player::AddXp(double xp)
{
    this->xp += xp;
    //level up if xp is >= xp required to level up.
    while (xp >= levelxp){//Allows for multiple levels in one xp gain (Boss kills)
        xp -= levelxp;//reduce xp to less than required xp to level up
        level++;//Level up
        cout << "Congratulations!! You have reached level " << level << "!\n";
        levelxp *= 1.25;//Increases xp required for level up.
        maxHp += 1;//Increase max hp by 1
    }
}

//Level functions
int Player::GetLevel() const
{
    return level;
}
void Player::SetLevel(int num)
{
    level = num;
    maxHp = (num + 9);//maxHp = 10 at lvl 1, 11 at 2, etc.
}

//Combat implementation
void Player::Combat(Monster *m)
{
    //Set stats for combat
    int mHp, mAtt, mDef, pHp, pAtt, pDef;
    CombatClass monster = m->GetCombatClass();//Get enemy combat class.
    SetCombatModifier(monster);//Implement combat modifier based on enemy combat class and player combat class.
    mHp = m->GetHp();
    mAtt = (m->GetAttack() + m->GetWeaponDamage() + m->GetLevel());//Monster attack = attack + weapon damage + level
    mDef = m->GetDefense();
    pHp = GetHp();
    pAtt = (GetCombatModifier() * (GetAttack() + GetWeaponDamage() + GetLevel()));//Player attack = attack + weapon damage + level
    pDef = (GetCombatModifier() * GetDefense());
    //Fight while the monster and the player are both alive
    while (mHp >= 0 && pHp >= 0){
        cout << "You attack!\n";
        int playerattackdmg = (pAtt - mDef);
        if (playerattackdmg <= 0){
            playerattackdmg = 2;
        }
        mHp -= playerattackdmg;
        if (mHp > 0){//If the monster is still alive after player's attack
            cout << "The monster has " << mHp << " health left!\n";
            cout << "The monster attacks!\n";
            int monsterattackdmg = (mAtt - pDef);
            if (monsterattackdmg <= 0){
                monsterattackdmg = 2;
            }
            pHp -= monsterattackdmg;
            SetHp(pHp);
        }
        if (pHp > 0){//If the player is still alive after the monster's attack
            cout << "You have " << pHp << " health left!\n";
        }
    }
    //After combat is over implement results
    if (mHp <= 0){
        cout << "You killed the monster!\n";
        cout << "You have gained " << m->GetXp() << " xp!\n";
        AddXp(m->GetXp());//Player gains xp rewarded by monster
        cout << "The monster dropped " << m->GetCoins() << " coins!\n";
        coins += m->GetCoins();//Player gains coins dropped by monster.
    }
    if (pHp <= 0){
        //Lose all items and set xp to 0 upon death of player.
        cout << "Oh No! You have died and lost all of your items!\n";
        xp = 0;
        //Clear all items in backpack and all items that are equipped.
        backpack.clear();
        equipment.clear();
    }
}

//Trading function.
void Player::Trade(Trader &t)
{
    cout << "The trader has " << t.GetCoins() << " coins available to trade with.\n";
    cout << "You have " << GetCoins() << " coins available to trade with.\n";
    cout << "Would you like to sell items or buy items? (1 to sell, 2 to buy, -1 to cancel trade)\n";
    int ans;
    cin >> ans;//Player's answer.
    while (ans != -1 && ans != 1 && ans != 2){//Allow for reentry of answer if the input number is invalid.
        cout << "The answer you have provided is invalid. Please try again.\n";
        cout << "1 for weapons and armor, 2 for potions, -1 to cancel trade.\n";
        cin >> ans;
    }
    //If the player wants to sell items.
    if (ans == 1){
        cout << "Would you like to sell weapons and armor, or potions? (1 for weapons and armor, 2 for potions, -1 to cancel trade)\n";
        while (ans != -1 && ans != 1 && ans != 2){//Allow for reentry of answer if the input number is invalid.
            cout << "The answer you have provided is invalid. Please try again.\n";
            cout << "1 for weapons and armor, 2 for potions, -1 to cancel trade.\n";
            cin >> ans;
        }
        if (ans == 1){//If the player wants to sell items and armor.
            CheckBackpack();
            cout << "What item number would you like to sell?\n";
            cin >> ans;//Get item list number of item to be sold.
            ans -= 1;//Make ans into an index for the player's vector of items.
            Item tradeItem = backpack.at(ans);//Make a trade item based on indicated index.
            if (t.GetCoins() >= tradeItem.GetPrice()){//If the trader has equal or more coins than the cost of the item.
                t.SetCoins( t.GetCoins() - tradeItem.GetPrice());//Remove coins from trader's coins.
                SetCoins(GetCoins() + tradeItem.GetPrice());//Add coins to player's coins.
                t.AddToInventory(tradeItem);//Add item to trader's inventory.
                backpack.erase(backpack.begin() + ans);//Remove item from player inventory.
            }
            else if (t.GetCoins() < tradeItem.GetPrice()){//If the trader can't affor the item.
                cout << "The trader only has " << t.GetCoins() << " coins but the item you are selling costs " << tradeItem.GetPrice() << " coins. Do you want to sell the item for " << t.GetCoins() << " coins? (1 for yes, 2 for no)\n";
                cin >> ans;
                while (ans != 1 && ans != 2){//If the player gives an invalid answer.
                    cout << "You have entered an invalid input. Please try again.\n";
                    cout << "1 to accept this trade, 2 to decline this trade\n";
                    cin >> ans;
                }
                if (ans == 1){
                    SetCoins(GetCoins() + t.GetCoins());//Add coins to player's coins.
                    t.SetCoins(0);//Remove coins from trader's coins.
                    t.AddToInventory(tradeItem);//Add item to trader's inventory.
                    backpack.erase(backpack.begin() + ans);//Remove item from player inventory.
                }
                else if (ans == 2){
                    cout << "You have declined the trade offer.\n";
                }
            }
        }
        else if (ans == 2){//If the player wants to sell Potions.
            CheckPotionsBag();
            cout << "What item number would you like to sell?\n";
            cin >> ans;//Get item list number of item to be purchased
            ans -= 1;//Make ans into an index for the player's vector of potions.
            Potion tradePotion = potionsBag.at(ans);//Make a trade item base on indicated index.
            if (t.GetCoins() >= tradePotion.GetPrice()){//If the trader has equal or more coins than the cost of the item.
                t.SetCoins(t.GetCoins() - tradePotion.GetPrice());//Remove coins from trader's coins.
                SetCoins(GetCoins() + tradePotion.GetPrice());//Add coins to player's coins.
                t.AddToPotions(tradePotion);//Add potion to trader's potions.
                potionsBag.erase(potionsBag.begin() + ans);//Remove potion from player's potions bag.
            }
            else if (t.GetCoins() < tradePotion.GetPrice()){//If the trader can't affor the potion.
                cout << "The trader only has " << t.GetCoins() << " coins but the potion you are selling costs " << tradePotion.GetPrice() << " coins. Do you want to sell the item for " << t.GetCoins() << " coins? (1 for yes, 2 for no)\n";
                cin >> ans;
                while (ans != 1 && ans != 2){//If the player gives an invalid answer.
                    cout << "You have entered an invalid input. Please try again.\n";
                    cout << "1 to accept this trade, 2 to decline this trade\n";
                    cin >> ans;
                }
                if (ans == 1){//If the player will accept the fewer coins
                    SetCoins(GetCoins() + t.GetCoins());//Add coins to player's coins.
                    t.SetCoins(0);//Remove coins from trader's coins.
                    t.AddToPotions(tradePotion);//Add potion to trader's potions.
                    potionsBag.erase(potionsBag.begin() + ans);//Remove potion from player's potions bag.
                }
                else if (ans == 2){
                    cout << "You have declined the trade offer.\n";
                }
            }
        }
        else if (ans == -1){
            cout << "You have cancelled the trade.\n";
        }
    }
    //If the player wants to buy items.
    else if (ans == 2){
        cout << "You begin trading. Please view the wares available for sale.\n";
        cout << "Would you like to browse weapons and armor, or potions? (1 for weapons and armor, 2 for potions, -1 to cancel trade)\n";
        cin >> ans;//Get confirmation of items or potions.
        while (ans != -1 && ans != 1 && ans != 2){//Allow for reentry of answer if the input number is invalid.
            cout << "The answer you have provided is invalid. Please try again.\n";
            cout << "1 for weapons and armor, 2 for potions, -1 to cancel trade.\n";
            cin >> ans;
        }
        if (ans == 1){//If player wants to buy items and armor.
            t.ListInventory();
            cout << "What item number would you like to buy?\n";
            cin >> ans;//Get item list number of item to be purchased
            ans -= 1;//Make ans into an index for the trader's vector of items.
            Item tradeItem = t.TradeItem(ans);
            if (GetCoins() >= tradeItem.GetPrice()){//If the player has equal or more coins than the cost of the item.
                SetCoins(GetCoins() - tradeItem.GetPrice());//Remove coins from player's coins.
                t.SetCoins(t.GetCoins() + tradeItem.GetPrice());//Add coins to trader's coins.
                backpack.push_back(tradeItem);//Add item to player's inventory.
                t.RemoveFromInventory(tradeItem);//Remove item from trader's inventory.
            }
            else if (GetCoins() < tradeItem.GetPrice()){//If the player can't afford the item.
                cout << "You can't afford this item!\n";
            }
        }
        else if (ans == 2){//If the player wants to buy potions.
            t.ListPotions();
            cout << "What item number would you like to buy?\n";
            cin >> ans;//Get item list number of item to be purchased
            ans -= 1;//Make ans into an index for the trader's vector of items.
            Potion tradePotion = t.TradePotion(ans);
            if (GetCoins() >= tradePotion.GetPrice()){//If the player has equal or more coins than the cost of the potion.
                SetCoins(GetCoins() - tradePotion.GetPrice());//Remove coins from player's coins.
                t.SetCoins(t.GetCoins() + tradePotion.GetPrice());//Add coins to trader's coins.
                potionsBag.push_back(tradePotion);//Add potion to player's potions bag.
                t.RemoveFromPotions(tradePotion);//Remove potion from player's inventory.
            }
            else if (GetCoins() < tradePotion.GetPrice()){
                cout << "You can't afford this potion!\n";
            }
        }
        else if (ans == -1){//If player cancels the trade.
            cout << "You have cancelled the trade.\n";
        }
    }
    else if (ans == -1){//If player cancels the trade.
        cout << "You have cancelled the trade.\n";
    }
}

//Equip from backpack or unequip from equipment
void Player::Equip(int index)
{
    int size = backpack.size();
    if (size >= index){//If there are at least index + 1 items in the backpack.
        for (int i = 0; i < size; i++){
            if (backpack.at(index).GetTypeIdentifier() == equipment.at(i).GetTypeIdentifier()){//If there is already an item of new item's type equipped, switch them.
                cout << "You already have an item of that type equipped. Switching items.\n";
                backpack.push_back(equipment.at(i));//Move old item from equipment to backpack.
                equipment.erase(equipment.begin() + i);//Remove old item from equipment.
                equipment.push_back(backpack.at(index));//Equip indexed item.
                backpack.erase(backpack.begin() + index);//Remove item from backpack.
            }
            else{
                cout << "Equipping Item.\n";
                equipment.push_back(backpack.at(index));//Equip indexed item.
                backpack.erase(backpack.begin() + index);//Remove item from backpack.
            }
        }    
    }
}
void Player::AddToBackpack(Item i)
{
    backpack.push_back(i);
}
void Player::UnEquip(int index)
{
    int size = equipment.size();
    if (size >= index){//If there are at least index + 1 items equipped
        backpack.push_back(equipment.at(index));//Move item from equipment to backpack.
        equipment.erase(equipment.begin() + index);//Remove item from equipment.
    }
}

//Check inventory
void Player::CheckBackpack() const
{
    cout << "Backpack: \n";//Header of inventory
    int size = backpack.size();
    for (int i = 0; i < size; i++){
        int j = i + 1;//Numbering inventory slots
        cout << j << ": " << backpack.at(i).GetName() << ", " << backpack.at(i).GetPrice() << endl;//Inventory contents
    }
}
void Player::CheckPotionsBag() const
{
    cout << "Potions bag: \n";//Header of inventory
    int size = potionsBag.size();
    for (int i = 0; i < size; i++){
        int j = i + 1;//Numbering inventory slots
        cout << j << ": " << potionsBag.at(i).GetName() << ", " << potionsBag.at(i).GetPrice() << endl;//Potions bag contents
    }
}

//Potion
void Player::DrinkPotion(int index)
{
    if (potionsBag.at(index).GetPotionType() == HealthPotion){
        hp += potionsBag.at(index).GetEffect();
    }
    else if(potionsBag.at(index).GetPotionType() == XpPotion){
        xp += potionsBag.at(index).GetEffect();
    }
}

//Player Stats
int Player::GetAttack() const
{
    return attack;
}
void Player::SetAttack(int att)
{
    attack = att;
}
int Player::GetWeaponDamage() const
{
    return weaponDamage;
}
void Player::SetWeaponDamage(int dmg)
{
    weaponDamage = dmg;
}
int Player::GetDefense() const
{
    return defense;
}
void Player::SetDefense(int def)
{
    defense = def;
}
int Player::GetHp() const
{
    return hp;
}
void Player::SetHp(int h)
{
    hp = h;
}
int Player::GetMaxHp() const
{
    return maxHp;
}
void Player::SetMaxHp(int num)
{
    maxHp = num;
}
int Player::GetCoins() const
{
    return coins;
}
void Player::SetCoins(int c)
{
    coins = c;
}
void Player::SpendCoins(int c)
{
    coins -= c;
}
Species Player::GetSpecies()
{
    return species;
}
void Player::SetSpecies(Species spec)
{
    species = spec;
}
CombatClass Player::GetCombatClass()
{
    return combatClass;
}
void Player::SetCombatClass(CombatClass combat)
{
    combatClass = combat;
}
double Player::GetCombatModifier()
{
    return combatModifier;
}
void Player::SetCombatModifier(CombatClass enemy)
{
    //If fighting with combat advantage
    if ((combatClass == Warrior && enemy == Archer) || (combatClass == Archer && enemy == Wizard) || (combatClass == Wizard && enemy == Warrior)){
        combatModifier = 1.25;
    }
    //If fighting with a combat disadvantage
    else if ((combatClass == Warrior && enemy == Wizard) || (combatClass == Archer && enemy == Warrior) || (combatClass == Wizard && enemy == Archer)){
        combatModifier = 0.75;
    }
    //If fighting with no combat advantage or disadvantage
    else{
        combatModifier = 1;
    }
}
void Player::Sleep(bool inBed)
{
    if (inBed){
        hp = maxHp;//Fully heal player if sleeping in bed.
    }
    else{ //If player isn't sleeping in a bed, heal by 10% of max hp.
        int heal = (maxHp * 0.1);
        //If the player isn't already at full health.
        if (hp < maxHp){
            if (hp < (maxHp + heal)){//If player won't go over max hp if healed by 10% of max hp
                hp += heal;//Heal player by 10% of max health.
            }
            else if(hp >= (maxHp + heal)){//If hp will go over max hp if healed by 10% of max health.
                hp = maxHp;//Fully heal
            }
        }
    }
}