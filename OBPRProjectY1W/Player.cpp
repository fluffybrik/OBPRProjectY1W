#include "Player.h"
Player::Player(string n) {
	setName(n);
	setHealth(120);
	setMaxHealth(120);
	setAttack(20);
	setAccuracy(75);
	setDefense(75);
}