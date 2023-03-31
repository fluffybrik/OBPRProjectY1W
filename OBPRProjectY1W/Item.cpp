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

void Item::receiveItem() {
	srand(time(0));
	int val = rand() % 100;
	if (val < rarity) // if val is less than rarity, item recieved; the higher the rarity, the less rare it is
		itemCount++;
}