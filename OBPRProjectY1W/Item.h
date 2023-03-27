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
	int GetCount();
	int GetRarity();
	void SetCount(int c) { itemCount = c; }
	void SetRarity(int r) { rarity = r; }
	void receiveItem() {
		srand(time(0));
		int val = rand() % 100;
		if (val < rarity)
			itemCount++;
	}
};

