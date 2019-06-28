#include "player.h"
#include "monster.h"
#include "boss.h"
#include "trader.h"
#include "item.h"
#include "potion.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

string GetSetPlayerName();
void Menu(Player &p, Trader &t, int &d, bool &ded, int &mk, int &bk, int &r);
void Scores();
void Sleep(bool inBed, int &day, Player &p);
void CombatSingle(Player &p, bool &ded, int &mk);
void CombatDungeon(Player &p, bool &ded, int &mk, int &bk);

int main(){
    bool dead = false;
    //Opening introductions and player creation.
    string king = "Garrett";
    cout << "King Garrett: Ah, I see you have received my message. Thank you for joining me to rid my kingdom of these beasts.\n";
    cout << "King Garrett: These monsters have been attacking our settlements and terrorizing my loyal citizens.\n";
    cout << "King Garrett: Where are my manners? Let's formally introduce ourselves. I am King " << king << ". What is your name?\n";
    Player player1(GetSetPlayerName());//Make the player and name it
    player1.SetSpecies(Man);//Player is a human
    player1.SetCombatClass(Warrior);//Player is a warrior
    cout << "King Garrett: I am pleased to meet you in person " << player1.GetName() << ".\n";

    //Continue into gameplay
    cout << "King Garrett: Now that the formalities are out of the way, I'll stop taking up your time.\n";
    cout << "King Garrett: Please go and protect my kingdom.\nI will tell my merchants that you are not an outsider and that they can trade with you.\n";

    //Make a trader
    Trader trader1("Trader");
    trader1.SetCoins(500);

    int running = 1;
    int day = 1;
    int monsterKills = 0;
    int bossKills = 0;
    int level = 1;
    ////////////////////////////////GAME////////////////////////////////
    while (running == 1 && (!(dead))){//Allows for continuous gameplay until the player is done playing or dies.
        level = player1.GetLevel();
        if (dead){//If player is dead.
            cout << "Your scores are: \n";
            Scores();//Archive any highscore changes and save playthrough scores
            running = 0;
            return 0;//End program if player is dead.
        }
        Menu(player1, trader1, day, dead, monsterKills, bossKills, running);
        if (dead){
            Scores();
            return 0;
        }
        cout << "Do you want to continue? (any number other than 1 to end.)\n";
        int ans;
        cin >> ans;
        cin.ignore(256, '\n');
        if (ans != 1){
            dead = true;
            Scores();
            return 0;
        }
        running = ans;
    }
    ////////////////////////////////GAME////////////////////////////////

    ////////////////////////////////scoring////////////////////////////////
    
    //Update scores
    ofstream fout;
    fout.open("scores.txt");
    if (fout.fail()){
        cout << "Error opening scores.txt\n";
        return 0;
    }
    //Current scores
    fout << "Current Scores:" << endl;
    fout << "Monsters killed: " << monsterKills << endl;
    fout << "Bosses killed: " << bossKills << endl;
    fout << "Level: " << level << endl;
    fout << "Day reached: " << day << endl;

    ////////////////////////////////Scoring////////////////////////////////
    
    return 0;
}

//Implementation of non class oriented functions
string GetSetPlayerName()
{
    cout << "What is your name?\n";
    string name;
    getline(cin, name);//Get player name
    cout << "Your name is " << name << ". Is this correct? (1 for yes, 2 for no)\n";
    int ans;
    cin >> ans;//Confirm player name.
    cin.ignore(256, '\n');//Ignore buffer new line
    while (ans < 1 || ans > 2)//If answer is invalid.
    {
        cout << "That is an invalid answer.\n";
        cout << "Your name is " << name << ". Is this correct? (1 for yes, 2 for no)\n";
        cin >> ans;
        cin.ignore(256, '\n');//Ignore buffer new line
    }
    if (ans == 1)//If the player confirms their name.
    {
        return name;//Return name.
    }
    while (ans == 2)//If player does not confirm their name.
    {
        cout << "You have declined that name. Please enter your new name.\n";
        getline(cin, name);//Get player name
        cout << "Your name is " << name << ". Is this correct? (1 for yes, 2 for no)\n";
        cin >> ans;
        cin.ignore(256, '\n');//Ignore buffer new line
        while (ans < 1 || ans > 2)//If answer is invalid.
        {
            cout << "That is an invalid answer.\n";
            cout << "Your name is " << name << ". Is this correct? (1 for yes, 2 for no)\n";
            cin >> ans;
            cin.ignore(256, '\n');//Ignore buffer new line
            if (ans == 1)
            {
                return name;//Return name.
            }
        }
        if (ans == 1)
        {
            return name;//Return name.
        }
    }
    return name;
}

void Menu(Player &p, Trader &t, int &d, bool &ded, int &mk, int &bk, int &rng)////////////////////////////////////////////
{
    cout << "Menu:\n";
    cout << "1: Fight a single troublesome monster\n";
    cout << "2: Fight through a dungeon\n";
    cout << "3: Trade with a merchant\n";
    cout << "4: Interact with inventory and worn items\n";
    cout << "5: Go to sleep on ground\n";
    cout << "6: Buy a room at an inn for 5 coins and go to sleep\n";
    cout << "7: Scores\n";
    cout << "8: End Game\n";
    int ans;
    cin >> ans;
    cin.ignore(256, '\n');
    while (ans < 1 || ans > 8){//If player gives an invalid response
        cout << "You have entered and invalid response. Please enter a valid response.\n";
        cout << "Menu:\n";
        cout << "1: Fight a single troublesome monster\n";
        cout << "2: Fight through a dungeon\n";
        cout << "3: Trade with a merchant\n";
        cout << "4: Interact with inventory and worn items\n";
        cout << "5: Go to sleep on ground\n";
        cout << "6: Buy a room at an inn for 5 coins and go to sleep\n";
        cout << "7: Scores\n";
        cout << "8: End Game\n";
        cin >> ans;
        cin.ignore(256, '\n');
    }
    switch(ans){
        case 1:
            CombatSingle(p, ded, mk);
            break;
        case 2:
            CombatDungeon(p, ded, mk, bk);
            break;
        case 3:
            p.Trade(t);
            break;
        case 4:
            p.CheckBackpack();
            p.CheckPotionsBag();

            cout << "Do you want to interact with any items? (1 equip, 2 unequp, 3 drink potion)\n";
            int ans;
            cin >> ans;
            cin.ignore(256, '\n');
            while (ans < 1 || ans > 3){
                cout << "You have entered an invalid input. Try again. (1 equip, 2 unequp, 3 drink potion)\n";
                cin >> ans;
                cin.ignore(256, '\n');
            }
            if (ans == 1){
                cout << "What item do you want to equip?\n";
                cin >> ans;
                cin.ignore(256, '\n');
                p.Equip(ans);
            }
            else if (ans == 2){
                cout << "What item do you want to unequip?\n";
                cin >> ans;
                cin.ignore(256, '\n');
                p.UnEquip(ans);
            }
            else{
                cout << "What potion do you want to drink?\n";
                cin >> ans;
                cin.ignore(256, '\n');
                p.DrinkPotion(ans);
            }
            break;
        case 5:
            Sleep(false, d, p);
            break;
        case 6:
            Sleep(true, d, p);
            break;
        case 7:
            Scores();
            break;
        case 8:
            ded = true;
            Scores();
            break;
    }
}

void Scores()
{
    ifstream fin;
    fin.open("scores.txt");
    if (fin.fail()){
        cout << "Can't open scores.txt\n";
    }
    string line;
    while ((getline(fin, line))){//Output Scores
        cout << line << endl;
    }
    fin.close();
}

void Sleep(bool inBed, int &day, Player &p)
{
    if (p.GetCoins() > 5){
        cout << "You pay 5 coins and go to sleep at the inn.\n";
        p.Sleep(true);
        p.SpendCoins(5);
    }
    else {
        cout << "You sleep on the ground.\n";
        p.Sleep(false);
    }
    day++;
}

void CombatSingle(Player &p, bool &ded, int &mk)
{
    Monster *monster = new Monster;

    cout << "You fight the monster.\n";
    p.Combat(monster);
    cout << "Your health is at " << p.GetHp() << ".\n";
    if (p.GetHp() <= 0){
        ded = true;
    }
    mk++;
    delete monster;
}

void CombatDungeon(Player &p, bool &ded, int &mk, int &bk)
{
    vector<Monster*> monsters;//Make a vector of monster pointers
    
    //Make temporary monsters to fight
    monsters.push_back(new Monster);
    monsters.push_back(new Monster);
    monsters.push_back(new Monster);
    monsters.push_back(new Boss);

    //Player fights monsters
    int num = 0;
    while (num < 4){
        Monster* m = monsters.at(num);
        cout << "You fight monster " << num << ".\n";
        p.Combat(m);
        cout << "Your health is at " << p.GetHp() << ".\n";
        cout << "Do you want to continue in this dungeon? (1 for yes, 2 for no)\n";
        int ans;
        cin >> ans;
        cin.ignore(256, '\n');
        while (ans < 1 || ans > 2){
            cout << "Your answer is invalid! (1 to continue, 2 to run)\n";
            cin >> ans;
            cin.ignore(256, '\n');
        }
        if (ans == 1){
            num++;
        }
        else if (ans == 2){
            num = 4;
        }
        if (p.GetHp() <= 0){
            ded = true;
        }
        mk++;
    }
    bk++;

    //Delete the temporary monsters.
    for (int i = 0; i < 4; i++){
        Monster* temp = monsters[i];
        delete temp;
    }
    monsters.clear();//Clear out the vector
}
