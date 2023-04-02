#pragma once
#ifndef GAME_H
#define GAME_H
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "mainFuncts.h"
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
	int eneDef;
public:
	Game();
	int getScore() { return score; }
	int getLevel() { return level; }
	int getEneDef() { return eneDef; }
	void setScore(int s) { score = s; }
	void setLevel(int l) { level = l; }
	void setEneDef(int e) { eneDef = e; }
	int GamePlay(Player*);
	int Battle(Player*);
	int Outcome(Player* player, Enemy* enemy);
	bool ChooseItem(Player* p, BigHeart* bh, GreatSword* gs, HealthPot* hp, Opticals* o, ToughShield* ts);
	void saveHighScore();
	int loadHighScore();

};


#endif // !GAME_H


