#include "Game.h"
Game::Game() {
	setScore(0);
	setLevel(0);
}

int Game::GamePlay(Player* player) { //adam's baby
	HealthPot* hp = new HealthPot(player->getInv(0));
	BigHeart* bh = new BigHeart(player->getInv(1));
	GreatSword* gs = new GreatSword(player->getInv(2));
	ToughShield* ts = new ToughShield(player->getInv(3));
	Opticals* o = new Opticals(player->getInv(4));
	int outcome;
	outcome = Battle(player, bh, gs, hp, o ,ts); //executes battle function
	switch (outcome) {
	case 1: { //winners case
		//save score, reward item...
		Game::setLevel(getLevel() + 1);
		Game::setScore(Game::getScore() + 100);
		bool chkRI = false;
		chkRI = hp->receiveItem();
		if (chkRI == true) {
			player->setInv(0, player->getInv(0) + 1);
			cout << "You've recieved a Health Potion!\n";
			chkRI = false;
		}
		chkRI = bh->receiveItem();
		if (chkRI == true) {
			player->setInv(1, player->getInv(1) + 1);
			cout << "You've recieved a Bigger Heart!\n";
			chkRI = false;
		}
		chkRI = gs->receiveItem();
		if (chkRI == true) {
			player->setInv(2, player->getInv(2) + 1);
			cout << "You've recieved a Greater Sword!\n";
			chkRI = false;
		}
		chkRI = ts->receiveItem();
		if (chkRI == true) {
			player->setInv(3, player->getInv(3) + 1);
			cout << "You've recieved a Tougher Shield!\n";
			chkRI = false;
		}
		chkRI = o->receiveItem();
		if (chkRI == true) {
			player->setInv(4, player->getInv(4) + 1);
			cout << "You've recieved Opticals!\n";
			chkRI = false;
		}
		//add item to inv

		cout << "VICTORY! You have defeated the monster.\n"
			<< "But alas... another one arrives.\n\n";

		return 0;
		break;
	}
		
	case 2: { //losers case
		//write score.. vlagwdiuhaw
		saveHighScore();
		delete player;

		cout << "You have been SLAIN...\n";
		bool chkGO;
		chkGO = gameOver();
		switch (chkGO) { //"Try Again?" function
			case true:
				return 1;
				break;
			case false:
				return 2;
				break;
			}
		}
		

	}
	
}

int Game::Battle(Player* player, BigHeart* bh, GreatSword* gs, HealthPot* hp, Opticals* o, ToughShield* ts) { //andrew's baby
	//initialize stats!!!!
	string eName = "Goblin";
	int eLevel = Game::getLevel();
	int eMHp = 100.00 + (100.00 * eLevel/4);
	int eAtk = 20.00 + (20.00 * eLevel / 4);
	int eAcc = 75.00 + (eLevel * 2);
		if (eAcc > 100) {
			eAcc = 100;
		}
	int eDef = 50.00 + (eLevel * 4);
	if (eDef > 100) {
		eDef = 100;
	}

	Enemy* enemy = new Enemy(eName, eMHp, eAtk, eAcc, eDef); // allocate a new enemy
	cout << "An enemy approaches!\n";

	int outcome = 0; // initialize 0
	do {
		// output the stats of enemy and players, separately using overloaded cout 
		cout << "Player stats: \n";
		player->printEnt(); // overloaded for the player class
		cout << "Enemy stats: \n";
		enemy->printEnt();


		// ask the player what their move is,

		int Move = 0;
		do {

			cout << "Select your move: ";
			cin >> Move;
			switch (Move) {
			case 1:
				player->setMove(1);
				break;
			case 2:
				player->setMove(2);
				break;
			case 3:
				player->setMove(3);
				break;
			default:
				cout << "Invalid move. Please select 1 (attack), 2 (defend), or 3 (use item).\n\n";
				break;
			}
		} while (Move < 1 || Move > 3);

		// randomize the enemy's choice
		int enemyMove = rand() % 2 + 1; // 1 for att 2 for defen
		enemy->setMove(enemyMove);

		//put it into pointers
		outcome = Outcome(player, enemy, bh, gs, hp, o, ts);

	} while (outcome == 0);// Do loop will loop while the return value of Outcome() is 0


	// this might need to be changed !below!
	delete enemy; // deallocate the enemy object

	return outcome; // Battle() will return Outcome()'s value when condition is broken
}

int Game::Outcome(Player* player, Enemy* enemy, BigHeart* bh, GreatSword* gs, HealthPot* hp, Opticals* o, ToughShield* ts) { //adam's? baby //TAKE ITEM CLASSES TOO(?)
	//initalize items
	/*HealthPot* hp = new HealthPot(player->getInv(0)); //OLD
	BigHeart* bh = new BigHeart(player->getInv(1));
	GreatSword* gs = new GreatSword(player->getInv(2));
	ToughShield* ts = new ToughShield(player->getInv(3));
	Opticals* o = new Opticals(player->getInv(4)); */


	cout << endl;

	//execute the player move using switch:
	switch (player->getMove()) {
	case 1://attack
		bool pAtkCheck; //checks if the attack lands or not
		int tempEHP;
		tempEHP = enemy->getHealth();
		pAtkCheck = player->attackEnemy(enemy);
		if (pAtkCheck == true) {
			cout << "You attack and hit the enemy with " << tempEHP - enemy->getHealth() << " damage\n\n";
		}
		else {
			cout << "You missed your attack!\n";
		}
		break;

	case 3:

		ChooseItem(player, bh, gs, hp, o, ts);//REMEMBER TO LOOP IF NO ITEMS!!!
		break;
	}
	
	if (enemy->getMove() == 2) {
		cout << "The enemy sets up for a block...\n";
	}

	//check for enemy vitals
	if (enemy->getHealth() == 0) {
		cout << "The enemy falls!\n";
		return 1;
	}
		
	//enemy's turn

	if (player->getMove() == 2) {
		cout << "You set up for a block...\n";
	}

	switch (enemy->getMove()) {
	case 1: // Attack
		bool eAtkCheck;
		int tempPHP;
		tempPHP = player->getHealth();
		eAtkCheck = enemy->attackEnemy(player);
		if (eAtkCheck == true) {
			cout << "It attacks! You take " << tempPHP - player->getHealth() << " damage.\n";
		}
		else {
			cout << "It misses!\n";
		}
		break;
	}

	//check for player vitals
	if (player->getHealth() == 0) {
		cout << "You are defeated...\n";
		return 2;
	}

	cout << endl;

	return 0;// if no one dies
}

bool Game::ChooseItem(Player* p, BigHeart* bh, GreatSword* gs, HealthPot* hp, Opticals* o, ToughShield* ts) { //nathan's baby
	//check if there are any items?
	/*int temp = 0; //OLD
	for (int i = 0; i < 5; i++) {
		temp =+ p->getInv(i);//haha i knew we were gonna use this member, gotta remember to use it in the main program
	}
	if (temp <= 0) {
		cout << "You have no items!\n";
		return false;//if there are no items, return false
	}*/

	if (bh->getCount() == 0 && gs->getCount() == 0 && hp->getCount() == 0 && o->getCount() == 0 && ts->getCount() == 0) {
		cout << "You have no items!\n";
		return false;//if there are no items, return false
	}

	int selection;
	cout << "What item would you like to use?\n";
	if (hp->getCount() > 0)
		cout << "1. " << hp;
	if (gs->getCount() > 0)
		cout << "2. " << gs;
	if (ts->getCount() > 0)
		cout << "3. " << ts;
	if (o->getCount() > 0)
		cout << "4. " << o;
	if (bh->getCount() > 0)
		cout << "5. " << bh;
	cout << "Your selection: ";
	cin >> selection;
	//there's nothing protecting against wrong choices, lets hope the player doesnt do that
	switch (selection) {
	case(1):
		hp->useItem(p);
		break;
	case(2):
		gs->useItem(p);
		break;
	case(3):
		ts->useItem(p);
		break;
	case(4):
		o->useItem(p);
		break;
	case(5):
		bh->useItem(p);
		break;
	}
	return true; //return true when there are items
} //DONE

//save and load score stuff

void Game::saveHighScore() { //adam's baby
	std::ofstream file("highscore.txt");
	if (file.is_open()) {
		file << Game::getScore();
		file.close();
	}
}

int Game::loadHighScore() { //adam's baby
	int highScore = 0;
	std::ifstream file("highscore.txt");
	if (file.is_open()) {
		file >> highScore;
		file.close();
	}
	return highScore;
}