#include "Opticals.h"
#include<iostream>
using namespace std;

Opticals::Opticals() {
	setRarity(20);
	setAccBoost(10);
	setCount(0);
}

Opticals::Opticals(int c) {
	setRarity(20);
	setAccBoost(10);
	setCount(0);
}

Opticals::Opticals(int c, int defB, int r) {
	setAccBoost(defB);
	setRarity(r);
	setCount(c);
}

bool Opticals::useItem(Entity* e) {
	if (getCount() <= 0) { //checks if theres 0 items, if so, then dont use.
		return false; //"Cant use it! No items.."
	}
	else {
		e->setAccuracy(e->getAccuracy() + Opticals::getAccBoost());
		setCount(getCount() - 1);
		cout << "You've equiped the Mapper's Opticals!\n+" << Opticals::getAccBoost() << " ACC\n\n";
		return true; //item is used
	}
}

ostream& operator<< (ostream& out, Opticals& obj) {
	//remember to make an exeption to not display anything when there are zero items                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	out << obj.getCount() << " MAPPER'S OPTICALS\n"
		<< "\t Four-eyes!\n"
		<< "\t Adds " << obj.getAccBoost() << " ACC to your character when used.\n\n";
	return out;
}

void Opticals::printItem() {
	cout << "4. " << getCount() << "x MAPPER'S OPTICALS\n"
		<< "\t Four-eyes!\n"
		<< "\t Adds " << getAccBoost() << " ACC to your character when used.\n\n";
}