#pragma once
#include <iostream>
#include<string>
using namespace std;
class Item
{
protected:
	int itemCount;
	int rarity;
public:
	Item();
	Item( int c, int r);
	int GetCount() { return itemCount; }
	int GetRarity() { return rarity; }
	void SetCount(int c) { itemCount = c; }
	void SetRarity(int r) { rarity = r; }
	void receiveItem();
	virtual bool useItem() = 0;
	virtual void printItem() = 0;
};

