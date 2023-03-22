#ifndef ENTITY_H
#define ENTITY_H
#pragma once
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Entity
{
protected:
	string name;
	int health;
	int maxHealth;
	int attack;
	int accuracy;
	int defense;
public:
	Entity();
	Entity(string, int, int, int, int);
	string getName() { return name; }
	int getHealth() { return health; }
	int getMaxHealth() { return maxHealth; }
	int getAttack() { return attack; }
	int getAccuracy() { return accuracy; }
	int getDefense() { return defense; }
	void setName(string n) { name = n; }
	void setHealth(int h) { health = h; }
	void setMaxHealth(int mH) { maxHealth = mH; }
	void setAttack(int at) { attack = at; }
	void setAccuracy(int ac) { accuracy = ac; }
	void setDefense(int de) { defense = de; }
	void takeDmg(int);
	bool attackEnemy(Entity& enemy);
};

#endif // !ENTITY_H