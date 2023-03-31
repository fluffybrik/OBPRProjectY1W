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

bool Entity::attackEnemy(Entity& enemy) {
	srand(time(0)); // Seed random number generator
	int hit_chance = rand() % 100; // Generate random hit chance between 0 and 99

	if (hit_chance < accuracy) { // If the attack hits
		//take damage based on defending or not, check enemy's def and whatnot
		enemy.takeDmg(Entity::attack);
		return true;
	}
	else {
		return false;
	}
}
