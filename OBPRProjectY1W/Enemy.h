#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"

class Enemy : public Entity
{
protected:
	int level;
public:
	Enemy(string, int, int, int, int);
};

#endif // !ENEMY.H