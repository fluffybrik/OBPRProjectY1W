#pragma once
#pragma once
#ifndef BIGHEART_H
#define BIGHEART_H

#include "Item.h"
class BigHeart : public Item
{
protected:
	int maxHpBoost;
public:
	BigHeart();
	BigHeart(int c);
	BigHeart(int c, int mHpB, int r);
	int getMaxHpBoost() { return maxHpBoost; }
	void setMaxHpBoost(int mHpB) { maxHpBoost = mHpB; }
	bool useItem(Entity*);
	friend ostream& operator<< (ostream& out, BigHeart& obj);
	void printItem();
};

#endif