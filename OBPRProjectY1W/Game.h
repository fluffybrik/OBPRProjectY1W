#pragma once
#ifndef GAME_H
#define GAME_H
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "BigHeart.h"
#include "GreatSword.h"
#include "HealthPot.h"
#include "Opticals.h"
#include "ToughShield.h"


using namespace std;

class Game
{
protected:
	int score;
	int level;
public:
	Game();
	int getScore() { return score; }
	int getLevel () { return level; }
	void setScore(int s) { score = s; }
	void setLevel(int l) { level = l; }
	int GamePlay();
	int Battle();
	int Outcome();
	void ChooseItem(Player& p, BigHeart& bh, GreatSword& gs, HealthPot& hp, Opticals& o, ToughShield& ts);
};


#endif // !GAME_H


