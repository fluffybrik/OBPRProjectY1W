#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"

class Enemy : public Entity
{
protected:
	int level;
public:
	Enemy(); //adam is constructing this class
		
};

#endif // !ENEMY.H