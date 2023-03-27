#include "HealthPot.h"
#include<iostream>
using namespace std;

HealthPot::HealthPot() {
	rarity = 50;
	hpBoost = 30;
}
HealthPot::HealthPot(int count, int hp, int r) {
	hpBoost = hp;
	rarity = r;
}
int HealthPot::GetHpBoost() {
	return hpBoost;
}

