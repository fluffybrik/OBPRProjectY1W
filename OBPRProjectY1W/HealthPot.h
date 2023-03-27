#pragma once
#include "Item.h"
class HealthPot :
    public Item
{
protected:
    int hpBoost;
public:
    HealthPot();
    HealthPot(int c, int hp, int r);
    int GetHpBoost();
    
    void SetHpBoost(int hp) { hpBoost = hp; }
    
};

