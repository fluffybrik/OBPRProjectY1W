#include "HealthPot.h"
#include<iostream>
using namespace std;

HealthPot::HealthPot() {
	rarity = 95;
	hpBoost = 30;
	setCount(0);
}

HealthPot::HealthPot(int c) {
	setRarity(95);
	setHpBoost(30);
	setCount(0);
}

HealthPot::HealthPot(int c, int hp, int r) {
	hpBoost = hp;
	rarity = r;
	setCount(c);
}
int HealthPot::getHpBoost() {
	return hpBoost;
}

bool HealthPot::useItem(Entity* e) {
	if (getCount() < 0) {//checks if theres 0 items, if so, then dont use.
		return false; //"Cant use it! No items.."
	}
	else {
		e->setHealth(e->getHealth() + getHpBoost());
		setCount(getCount() - 1);
		cout << "You've drank a Health Potion!\n+" << getHpBoost() << " HP\n\n";
		return true; //item is used
	}
}

ostream& operator<< (ostream& out, HealthPot& obj) {
	//remember to make an exeption to not display anything when there are zero items                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	out << "1. " << obj.getCount() << " HEALTH POTION\n"
		<< "\t Strawberry flavored...\n"
		<< "\t Restores " << obj.getHpBoost() << " HP when consumed.\n\n";
	return out;
}

void HealthPot::printItem() {
	cout << "1. " << getCount() << "x HEALTH POTION\n"
		<< "\t Strawberry flavored...\n"
		<< "\t Restores " << getHpBoost() << " HP when consumed.\n\n";
}