#pragma once
#ifndef TOUGHSHIELD_H
#define TOUGHSHIELD_H

#include "Item.h"
class ToughShield : public Item
{
protected:
	int defBoost;
public:
	ToughShield();
	ToughShield(int c, int defB, int r);
	int getDefBoost() { return defBoost; }
	void setDefBoost(int defB) { defBoost = defB; }
	bool useItem(Entity&);
	friend ostream& operator<< (ostream& out, ToughShield& obj);
};

#endif