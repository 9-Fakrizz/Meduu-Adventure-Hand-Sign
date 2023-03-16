#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<vector>
using namespace std;

class unit {
    string name;
    string type;
    int hpmax;
    int hpcurrent;
    int attk;
    int def;
    bool guard_on;
public:
    void create(string);
    void newturn();
    int atk(unit &);
    int attaked(int);
    int heal();
    void guard();
    bool dead();
    vector<void> skill();
    vector<void> buffstat();
};

void unit::create(string nam)
{
    if (nam == "Player")
    {
        type = "Player";
        cout << "Enter name: "; getline(cin, name);
        hpmax = 100;
        attk = 25;
        def = 25;
    }
    else if (nam == "Mon")
    {
        type = "Monster";
        name = "Monster";
        hpmax = 1000;
        attk = 70;
        def = 50;
    }
    guard_on = false;
    hpcurrent = hpmax;
}

void unit::newturn()
{
    guard_on = false;
}

int unit::atk(unit &pla)
{
    return pla.attaked(attk);
}

int unit::attaked(int oppon)
{
    int damaged = 0;
    if (guard_on = false)
    {
        damaged = oppon - def;
        hpcurrent -= damaged;
    }
    else
    {
        damaged = (oppon - def) / 2;
        hpcurrent -= damaged;
    }
    return damaged;
}

int unit::heal()
{
    int full = 25;
    if (full + hpcurrent >= hpmax)
    {
        full = hpmax - hpcurrent;
    }
    hpcurrent += full;
    return full;
}

void unit::guard()
{
    guard_on = true;
}

bool unit::dead()
{
    if (hpcurrent <= 0) return true;
    else return false;
}

//vector<void> unit::skill(int a)
//{
//    if (a == 1)
//    {
//
//    }
//    else if (a == 2)
//    {
//
//    }
//    else if (a == 3)
//    {
//
//    }
//    else
//    {
//
//    }
//}
//
//vector<void> unit::buffstat(int a)
//{
//    if (a == 1)
//    {
//        attk += 1;
//    }
//    else if (a == 2)
//    {
//
//    }
//    else if (a == 3)
//    {
//
//    }
//    else
//}