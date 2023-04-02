#pragma once
#include<iostream>
#include<string>
#include "Entity.h"
using namespace std;
class Item
{
protected:
	int itemCount;
	int rarity;
public:
	Item();
	Item( int c, int r);
	int getCount() { return itemCount; }
	int getRarity() { return rarity; }
	void setCount(int c) { itemCount = c; }
	void setRarity(int r) { rarity = r; }
	void receiveItem();
	virtual bool useItem(Entity*) = 0;
};

