#pragma once
#ifndef GAME_H
#define GAME_H
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
	bool newbattle();
};


#endif // !GAME_H


