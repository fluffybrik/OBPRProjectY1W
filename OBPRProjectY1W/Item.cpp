#include "Item.h"
Item:: Item() {
	itemCount = 0;
	rarity = 0;
}
Item::Item( int c, int r)
{
	itemCount = c;
	rarity = r;
}
int Item::GetCount() {
	return itemCount;
}
int Item::GetRarity() {
	return rarity;
}