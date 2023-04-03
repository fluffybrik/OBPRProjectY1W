#include "Entity.h"
Entity::Entity() {
	setName("");
	setHealth(0);
	setMaxHealth(0);
	setAttack(0);
	setAccuracy(0);
	setDefense(0);
}

Entity::Entity(string n, int mH, int at, int ac, int de) {
	setName(n);
	setMaxHealth(mH);
	setHealth(mH);
	setAttack(at);
	setAccuracy(ac);
	setDefense(de);
}

void Entity::takeDmg(int dmg) {
	health -= dmg;
	if (health < 0)
		health = 0;
}

bool Entity::attackEnemy(Entity* enemy) {
	srand((unsigned) time(NULL)); // Seed random number generator
	int hit_chance = rand() % 100; // Generate random hit chance between 0 and 99
	cout << hit_chance << "hitchance" << endl;																	//debug

	if (hit_chance < accuracy) { // If the attack hits
		//take damage based on defending or not, check enemy's def and whatnot
		if (enemy->getMove() == 2) { //if they defend....
			enemy->takeDmg(Entity::attack *  (enemy->getDefense() / 100));
		}
		enemy->takeDmg(Entity::attack);
		return true;
	}
	else {
		return false;
	}
}

ostream& operator <<  (ostream& out, Entity& obj) {
	out << "~~~~" << obj.getName() << "~~~~" << '\n'
		<< "HP: " << obj.getHealth() << '/' << obj.getMaxHealth() << '\n'
		<< "ATK: " << obj.getAttack() << '\n'
		<< "ACC: " << obj.getAccuracy() << '\n'
		<< "DEF: " << obj.getDefense() << "\n\n";
	return out;
}

void Entity::printEnt() {
	cout << "~~~~" << Entity::getName() << "~~~~" << '\n'
		<< "HP: " << Entity::getHealth() << '/' << Entity::getMaxHealth() << '\n'
		<< "ATK: " << Entity::getAttack() << '\n'
		<< "ACC: " << Entity::getAccuracy() << '\n'
		<< "DEF: " << Entity::getDefense() << "\n\n";
}