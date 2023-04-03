#include "GreatSword.h"
#include<iostream>
using namespace std;

GreatSword::GreatSword() {
	setRarity(20);
	setAtkBoost(10);
	setCount(0);
}

GreatSword::GreatSword(int c) {
	setRarity(20);
	setAtkBoost(10);
	setCount(c);
	cout << "init!\n";
}

GreatSword::GreatSword(int c, int atkB, int r) {
	setAtkBoost(atkB);
	setRarity(r);
	setCount(c);
}

bool GreatSword::useItem(Entity* e) {
	if (GreatSword::getCount() <= 0) { //checks if theres 0 items, if so, then dont use.
		return false; //"Cant use it! No items.."
	}
	else {
		e->setAttack(e->getAttack() + GreatSword::getAtkBoost());
		setCount(getCount() - 1);
		cout << "You've equipped a Greater Sword!\n+" << GreatSword::getAtkBoost() << " ATK\n\n";
		return true; //item is used
	}
}

ostream& operator<< (ostream& out, GreatSword& obj) {
	//remember to make an exeption to not display anything when there are zero items                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	out << obj.getCount() << " GREATER SWORD\n"
		<< "\t It's somehow sharper than the last one!\n"
		<< "\t Adds " << obj.getAtkBoost() << " ATK to your character when used.\n\n";
	return out;
}