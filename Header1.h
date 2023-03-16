#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<vector>
using namespace std;

class Equip {
    int hpmax;
    int attk;
    int def;
public:
    Equip(int, int, int);
    vector<int> getstat();
};

class Skill {
    int hpmax;
    int attk;
    int def;
public:
    Skill(int, int, int);
    vector<int> getstat();
};

class buffStat {
    int hpmax;
    int attk;
    int def;
public:
    Stat(int, int, int);
    vector<int> getstat();
};

class unit {
    string name;
    string type;
    int hpmax;
    int hpcurrent;
    int attk;
    int def;
    bool guard_on;
    Equip* equipment;
    Skill* skilll;
    buffStat* stat;
public:
    void create(string);
    void newturn();
    int atk(unit &);
    int attaked(int);
    int heal();
    void guard();
    bool dead();
    void equip(Equip *);
    void skil(Skill*);
    void stat(buffStat*);
};


vector<int> Equip::getstat()
{
    vector<int> temp = { hpmax,attk,def };
    return temp;
}

void unit::equip(Equip* itm)
{
    if (equipment)
    {
        if (equipment->getstat() != itm->getstat())
        {
            hpmax -= equipment->getStat()[0];
            attk -= equipment->getStat()[1];
            def -= equipment->getStat()[2];
            equipment = item;
            hpmax += equipment->getStat()[0];
            attk += equipment->getStat()[1];
            def += equipment->getStat()[2];
        }
    }
    else
    {
        equipment = item;
        hpmax += equipment->getStat()[0];
        attk += equipment->getStat()[1];
        def += equipment->getStat()[2];
    }
    if (hpcurrent > hpmax) hpcurrent = hpmax;
}

Equip::Equip(int a, int b, int c)
{
    hpmax = a;
    attk = b;
    def = c;
}


vector<int> Skill::getstat()
{
    vector<int> temp = { hpmax,attk,def };
    return temp;
}

void unit::skil(Skill* a)
{
    if (skilll)
    {
        if (skilll->getstat() != a->getstat())
        {
            hpmax -= skilll->getStat()[0];
            attk -= skilll->getStat()[1];
            def -= skilll->getStat()[2];
            skilll = a;
            hpmax += skilll->getStat()[0];
            attk += skilll->getStat()[1];
            def += skilll->getStat()[2];
        }
    }
    else
    {
        skilll = a;
        hpmax += skilll->getStat()[0];
        attk += skilll->getStat()[1];
        def += skilll->getStat()[2];
    }
    if (hpcurrent > hpmax) hpcurrent = hpmax;
}

Skill::Skill(int a, int b, int c)
{
    hpmax = a;
    attk = b;
    def = c;
}


vector<int> buffStat::getstat()
{
    vector<int> temp = { hpmax,attk,def };
    return temp;
}

void unit::Stat(buffStat* b)
{
    if (stat)
    {
        if (stat->getstat() != b->getstat())
        {
            hpmax -= stat->getStat()[0];
            attk -= stat->getStat()[1];
            def -= stat->getStat()[2];
            stat = b;
            hpmax += stat->getStat()[0];
            attk += stat->getStat()[1];
            def += stat->getStat()[2];
        }
    }
    else
    {
        stat = b;
        hpmax += stat->getStat()[0];
        attk += stat->getStat()[1];
        def += stat->getStat()[2];
    }
    if (hpcurrent > hpmax) hpcurrent = hpmax;
}

buffStat::Stat(int a, int b, int c)
{
    hpmax = a;
    attk = b;
    def = c;
}


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
    hpcurrent = hpmax;
    guard_on = false;
    equipment = NULL;
    skilll = NULL;
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
