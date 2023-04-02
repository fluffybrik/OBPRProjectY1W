#pragma once
#ifndef GREATSWORD_H
#define GREATSWORD_H

#include "Item.h"
class GreatSword : public Item
{
protected:
	int atkBoost;
public:
	GreatSword();
	GreatSword(int c);
	GreatSword(int c, int atkB, int r);
	int getAtkBoost() { return atkBoost; }
	void setAtkBoost(int atkB) { atkBoost = atkB; }
	bool useItem(Entity*);
	friend ostream& operator<< (ostream& out, GreatSword& obj);
};

#endif