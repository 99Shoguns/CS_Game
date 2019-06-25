#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item
{
private:
    string name;
    float price;
public:
    Item();
    Item(string name);
    string GetName() const;
    void SetName(string n);
    float GetPrice() const;
    void SetPrice(float p);
};

#endif