#pragma once
#ifndef HEALTHPOT_H
#define HEALTHPOT_H

#include "Item.h"
class HealthPot : public Item
{
protected:
    int hpBoost;
public:
    HealthPot();
    HealthPot(int c);
    HealthPot(int c, int hp, int r);
    int getHpBoost();
    void setHpBoost(int hp) { hpBoost = hp; }
    virtual bool useItem(Entity*);
    friend ostream& operator<< (ostream& out, HealthPot& obj);
};

#endif // !HEALTHPOT_H                                                                   