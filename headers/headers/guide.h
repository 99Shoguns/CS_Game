#ifndef GUIDE_H
#define GUIDE_H

#include <string>
using namespace std;

class Guide
{
private:
    string name;
public:
    Guide();
    Guide(string name);
    string GetName() const;
    void SetName(string n);
    void GiveAdvice();
    void GiveDirections();
};

#endif