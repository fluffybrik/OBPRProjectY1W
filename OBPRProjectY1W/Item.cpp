#include "Item.h"
Item:: Item() {
	itemCount = 0;
	rarity = 25;
}
Item::Item( int c, int r)
{
	itemCount = c;
	rarity = r;
}

bool Item::receiveItem() {
	int val = rand() % 100; // Generate random hit chance between 0 and 99
	if (val < rarity) { // if val is less than rarity, item recieved; the higher the rarity, the less rare it is
		itemCount++;

		return true;
	}
	else
		return false;
}