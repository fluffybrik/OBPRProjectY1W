#include "ToughShield.h"
#include<iostream>
using namespace std;

ToughShield::ToughShield() {
	setRarity(20);
	setDefBoost(4);
	setCount(0);
}

ToughShield::ToughShield(int c) {
	setRarity(20);
	setDefBoost(10);
	setCount(0);
}

ToughShield::ToughShield(int c, int defB, int r) {
	setDefBoost(defB);
	setRarity(r);
	setCount(c);
}

bool ToughShield::useItem(Entity* e) {
	if (getCount() <= 0) { //checks if theres 0 items, if so, then dont use. //DEBUGDEBUG
		return false; //"Cant use it! No items.."
	}
	else{
		e->setDefense(e->getDefense() + getDefBoost());
		setCount(getCount() - 1);
		cout << "You've equipped a Tougher Shield!\n+" << getDefBoost() << " DEF\n\n";
		return true; //item is used
	}
}

ostream& operator<< (ostream& out, ToughShield& obj) {
	//remember to make an exeption to not display anything when there are zero items                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	out << obj.getCount() << " TOUGHER SHIELD\n"
		<< "\t Now in Yellow(TM)!\n"
		<< "\t Adds " << obj.getDefBoost() << " DEF to your character when used.\n\n";
	return out;
}

void ToughShield::printItem() {
	cout << "3. " << getCount() << "x TOUGHER SHIELD\n"
		<< "\t Now in Yellow(TM)!\n"
		<< "\t Adds " << getDefBoost() << " DEF to your character when used.\n\n";
}