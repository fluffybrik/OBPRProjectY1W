#pragma once
#ifndef OPTICALS_H
#define OPTICALS_H

#include "Item.h"
class Opticals : public Item
{
protected:
	int accBoost;
public:
	Opticals();
	Opticals(int c);
	Opticals(int c, int accB, int r);
	int getAccBoost() { return accBoost; }
	void setAccBoost(int accB) { accBoost = accB; }
	bool useItem(Entity*);
	friend ostream& operator<< (ostream& out, Opticals& obj);
	void printItem();
};

#endif