#include "Game.h"
Game::Game() {
	setScore(0);
	setLevel(0);
}

int Game::GamePlay(Player* player, BigHeart* bh, GreatSword* gs, HealthPot* hp, Opticals* o, ToughShield* ts) { //adam's baby
	int outcome;
	outcome = Battle(player, bh, gs, hp, o ,ts); //executes battle function
	switch (outcome) {
	case 1: { //winners case
		//save score, reward item...
		Game::setLevel(getLevel() + 1);
		Game::setScore(Game::getScore() + 100);
		cout << "\n\n\nVICTORY! You have defeated the monster.\n+100 Points\n";
			//add item to inv
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
		
		cout << "But alas... another one arrives.\n\n";
		system("pause");
		return 0;
		break;
	}
		
	case 2: { //losers case
		//write score.. vlagwdiuhaw
		saveHighScore();
		delete player;

		cout << "\n\n\nYou have been SLAIN...\n";
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
	string eName;
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

	int bossNum = 0;
	bossNum = (rand() % 3);
	if (bossNum == 0)
		eName = "Impersonator";
	else if (bossNum == 1)
		eName = "Rick, Destroyer of Souls";
	else if (bossNum == 2)
		eName = "Goblin";
	else
		eName = "Brick";

	Enemy* enemy = new Enemy(eName, eMHp, eAtk, eAcc, eDef); // allocate a new enemy
	cout << "LEVEL " << getLevel() + 1  << endl;
	cout << enemy->getName() << " approaches!\n";

	//graphics, prod. ben

	cout << "---------------------------------------------------------" << endl << endl;

	if (bossNum == 0) {
		cout << " o/" << "                                              " << ",''," << endl;
		cout << "/|_" << "                                             " << "(__)||" << endl;
		cout << "/  |" << "                                            " << "|_|_|" << endl;
		cout << "---------------------------------------------------------" << endl;
	}
	else if (bossNum == 1) {
		cout << " o/" << "                                              " << ",''," << endl;
		cout << "/|_" << "                                              " << "=-=|" << endl;
		cout << "/  |" << "                                             " << "|__|" << endl;
		cout << "---------------------------------------------------------" << endl;
	}
	else if (bossNum == 2) {
		cout << " o/" << "                                              " << "////" << endl;
		cout << "/|_" << "                                              " << "0_0}" << endl;
		cout << "/  |" << "                                             " << "(__)" << endl;
		cout << "---------------------------------------------------------" << endl;
	}
	else if (bossNum == 3) {
		cout << " o/" << "                                              " << " __ " << endl;
		cout << "/|_" << "                                              " << "/' |" << endl;
		cout << "/  |" << "                                             " << "/__|" << endl;
		cout << "---------------------------------------------------------" << endl;
	}


	int outcome = 0; // initialize 0
	do {
		// output the stats of enemy and players, separately using overloaded cout 
		cout << "Player stats: \n";
		player->printEnt(); // overloaded for the player class
		cout << "Enemy stats: \n";
		enemy->printEnt();


		// ask the player what their move is,

		int Move = 0;
		bool chkItem = false;//chcks if user has items
		do {

			cout << "WHAT IS YOUR MOVE? \n"
				<< "1. ATTACK\n"
				<< "2. DEFEND\n"
				<< "3. USE ITEM\n"
				<< "Selection: ";
			cin >> Move;
			switch (Move) {
			case 1:
				player->setMove(1);
				break;
			case 2:
				player->setMove(2);
				break;
			case 3:
				if (bh->getCount() == 0 && gs->getCount() == 0 && hp->getCount() == 0 && o->getCount() == 0 && ts->getCount() == 0) {
					cout << "\n\nYou have no items!\n\n";
					chkItem = false;
				}
				else {
					player->setMove(3);
					ChooseItem(player, bh, gs, hp, o, ts);
					system("pause");
					chkItem = false;
				}
				break;
			default:
				cout << "Invalid move. Please select 1 (attack), 2 (defend), or 3 (use item).\n\n";
				break;
			}
			if (Move == 1 || Move == 2)
				chkItem = true;
		} while (Move < 1 || Move > 3 || chkItem == false);

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
	
	//check for blocks

	if (enemy->getMove() == 2) {
		cout << enemy->getName() << " sets up for a block...\n\n";
	}

	if (player->getMove() == 2) {
		cout << "You set up for a block...\n\n";
	}

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
			cout << "You missed your attack!\n\n";
		}
		break;

	case 3:

		ChooseItem(player, bh, gs, hp, o, ts);//REMEMBER TO LOOP IF NO ITEMS!!!
		break;
	}
	

	//check for enemy vitals
	if (enemy->getHealth() == 0) {
		cout << enemy->getName() << " falls!\n";
		return 1;
	}
		
	//enemy's turn

	switch (enemy->getMove()) {
	case 1: // Attack
		bool eAtkCheck;
		int tempPHP;
		tempPHP = player->getHealth();
		eAtkCheck = enemy->attackEnemy(player);
		if (eAtkCheck == true) {
			cout << enemy->getName() << " attacks! You take " << tempPHP - player->getHealth() << " damage.\n";
		}
		else {
			cout << enemy->getName() << " misses!\n";
		}
		break;
	}

	//check for player vitals
	if (player->getHealth() == 0) {
		return 2;
	}

	cout << endl;
	system("pause");
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
		hp->printItem();
	if (gs->getCount() > 0)
		gs->printItem();
	if (ts->getCount() > 0)
		ts->printItem();
	if (o->getCount() > 0)
		o->printItem();
	if (bh->getCount() > 0)
		bh->printItem();
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