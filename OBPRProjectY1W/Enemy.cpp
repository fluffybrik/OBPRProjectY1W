#include "Enemy.h"

Enemy::Enemy(string n, int mH, int at, int ac, int de) {
	setName(n);
	setMaxHealth(mH);
	setHealth(mH);
	setAttack(at);
	setAccuracy(ac);
	setDefense(de);
}
