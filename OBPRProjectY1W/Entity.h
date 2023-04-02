#ifndef ENTITY_H
#define ENTITY_H
#pragma once
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
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
	int move;
public:
	Entity();
	Entity(string, int, int, int, int);
	string getName() { return name; }
	int getHealth() { return health; }
	int getMaxHealth() { return maxHealth; }
	int getAttack() { return attack; }
	int getAccuracy() { return accuracy; }
	int getDefense() { return defense; }
	int getMove() { return move; }
	void setName(string n) { name = n; }
	void setHealth(int h) { health = h; }
	void setMaxHealth(int mH) { maxHealth = mH; }
	void setAttack(int at) { attack = at; }
	void setAccuracy(int ac) { accuracy = ac; }
	void setDefense(int de) { defense = de; }
	void setMove(int m) { move = m; }
	void takeDmg(int);
	bool attackEnemy(Entity* enemy);
	//how the heck do i overload cout again imma check
	friend ostream& operator<< (ostream& out, Entity& obj); //this is not working
	void printEnt();
};

#endif // !ENTITY_H