#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "BigHeart.h"
#include "GreatSword.h"
#include "HealthPot.h"
#include "Opticals.h"
#include "ToughShield.h"

class Player : public Entity, public BigHeart, public GreatSword, 
	public HealthPot, public Opticals, public ToughShield //ive had other things in mind but ig we dont need it..????
{
protected:
	int inv[5]; 	//item count in this order: hp,bigh,gs,ts,opt
public:
	Player(string);
	void setInv(int i, int x) { inv[i] = x; }
	int getInv(int i) { return inv[i]; }
};

#endif // !1
