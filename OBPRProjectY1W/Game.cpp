#include "Game.h"
Game::Game() {
	setScore(0);
	setLevel(1);
}

int Game::GamePlay() {
	return 0;
}

int Game::Battle() {
	return 0;
}
int Game::Outcome() {
	return 0;
}

void Game::ChooseItem(Player& p, BigHeart& bh, GreatSword& gs, HealthPot& hp, Opticals& o, ToughShield& ts) {
	//check if there are any items?
	int temp = 0;
	for (int i = 0; i < 5; i++) {
		p.getInv(i);//haha i knew we were gonna use this member, gotta remember to use it in the main program
	}
	if (temp <= 0) {
		return;//if there are no items, return
	}


	int selection;
	cout << "What item would you like to use?\n";
	if (hp.getCount() > 0)
		cout << "1. " << hp;
	if (gs.getCount() > 0)
		cout << "2. " << gs;
	if (ts.getCount() > 0)
		cout << "3. " << ts;
	if (o.getCount() > 0)
		cout << "4. " << o;
	if (bh.getCount() > 0)
		cout << "5. " << bh;
	cout << "Your selection: ";
	cin >> selection;

	switch (selection) {
	case(1):
		hp.useItem(p);
		break;
	case(2):
		gs.useItem(p);
		break;
	case(3):
		ts.useItem(p);
		break;
	case(4):
		o.useItem(p);
		break;
	case(5):
		bh.useItem(p);
		break;
	}
	return;
}