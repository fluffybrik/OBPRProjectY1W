#include "BigHeart.h"
#include<iostream>
using namespace std;

BigHeart::BigHeart() {
	setRarity(20);
	setMaxHpBoost(5);
	setCount(0);
}

BigHeart::BigHeart(int c) {
	setRarity(20);
	setMaxHpBoost(5);
	setCount(c);
	cout << "init!\n";
}

BigHeart::BigHeart(int c, int defB, int r) {
	setMaxHpBoost(defB);
	setRarity(r);
	setCount(c);
}

bool BigHeart::useItem(Entity* e) {
	if (BigHeart::getCount() <= 0) { //checks if theres 0 items, if so, then dont use.
		return false; //"Cant use it! No items.."
	}
	else {
		int temp[2];
		temp[0] = e->getHealth() / e->getMaxHealth();				//current health ratio of the entity
		temp[1] = e->getMaxHealth() + BigHeart::getMaxHpBoost();	//new max hp
		e->setMaxHealth(temp[1]);								//set max health
		e->setHealth(round(temp[1] * temp[0]));							//set new health based on ratio
		setCount(getCount() - 1);
		cout << "You've implanted Bigger Heart!\n+" << BigHeart::getMaxHpBoost() << " MAX HP\n\n";
		return true; //item is used
	}
}

ostream& operator<< (ostream& out, BigHeart& obj) {
	//remember to make an exeption to not display anything when there are zero items                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	out << obj.getCount() << " BIGGER HEART\n"
		<< "\t *applying Bigger Heart does not constitute in increased kindness.*\n"
		<< "\t Increases maximum HP by " << obj.getMaxHpBoost() << " points when surgically implanted.\n\n";
	return out;
}

void BigHeart::printItem() {
	return;
}