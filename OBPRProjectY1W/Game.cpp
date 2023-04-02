#include "Game.h"
Game::Game() {
	setScore(0);
	setLevel(1);
}

int Game::GamePlay(Player* player) { //adam's baby
	Game::setLevel(0);
	HealthPot* hp = new HealthPot(player->getInv(0));
	BigHeart* bh = new BigHeart(player->getInv(1));
	GreatSword* gs = new GreatSword(player->getInv(2));
	ToughShield* ts = new ToughShield(player->getInv(3));
	Opticals* o = new Opticals(player->getInv(4));
	int outcome;
	outcome = Battle(player);
	switch (outcome) {
	case 1: { //winners case
		//save score, reward item...
		Game::setLevel(getLevel() + 1);
		Game::setScore(Game::getScore() + 100);

		hp->receiveItem();
		bh->receiveItem();
		gs->receiveItem();
		ts->receiveItem();
		o->receiveItem();
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

		switch (gameOver()) { //"Try Again?" function
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

int Game::Battle(Player* player) { //andrew's baby
	//initialize stats!!!!
	string eName = "Goblin";
	int eLevel = Game::getLevel();
	int eMHp = 100 + (100 * (eLevel/4));
	int eAtk = 20 + (20 * (eLevel / 4));
	int eAcc = 75 + (15 * round((pow(-1.25,-(eLevel))))); //using equation -1.25^(-x)+1
	int eDef = 50 + (50 * round((pow(-1.05, -(eLevel)))));//using equation -1.05^(-x)+1

	Enemy* enemy = new Enemy(eName, eMHp, eAtk, eAcc, eDef); // allocate a new enemy

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

		//put it into pointers
		outcome = Outcome(player, enemy);

	} while (outcome == 0);// Do loop will loop while the return value of Outcome() is 0


	// this might need to be changed !below!
	delete enemy; // deallocate the enemy object

	return outcome; // Battle() will return Outcome()'s value when condition is broken
}

int Game::Outcome(Player* player, Enemy* enemy) { //adam's? baby //TAKE ITEM CLASSES TOO(?)
	//initalize items
	HealthPot* hp = new HealthPot(player->getInv(0));
	BigHeart* bh = new BigHeart(player->getInv(1));
	GreatSword* gs = new GreatSword(player->getInv(2));
	ToughShield* ts = new ToughShield(player->getInv(3));
	Opticals* o = new Opticals(player->getInv(4));


	//execute the player move using switch:
	switch (player->getMove()) {
	case 1://attack
		bool atkcheck; //checks if the attack lands or not
		atkcheck = player->attackEnemy(enemy);
		if (enemy->getMove() == 2) {
			cout << "The enemy blocks your attack and blocks some damage!\n";
		}
		if (atkcheck == true) {
			cout << "You attack and hit the enemy with " << player->getAttack() << " damage\n\n";
		}
		else {
			cout << "You missed your attack!\n";
		}
		break;

	case 3:

		ChooseItem(player, bh, gs, hp, o, ts);//REMEMBER TO LOOP IF NO ITEMS!!!
		break;
	}
	

	//check for enemy vitals
	if (enemy->getHealth() == 0) {
		cout << "The enemy falls!\n";
		return 1;
	}
		
	//enemy's turn
	switch (enemy->getMove()) {
	case 1: // Attack
		enemy->attackEnemy(player);
		cout << "It attacks! You take " << enemy->getAttack() << " damage.\n\n";
		break;
	}

	//check for player vitals
	if (player->getHealth() == 0) {
		cout << "You are defeated...\n";
		return 2;
	}

	return 0;// if no one dies
}

bool Game::ChooseItem(Player* p, BigHeart* bh, GreatSword* gs, HealthPot* hp, Opticals* o, ToughShield* ts) { //nathan's baby
	//check if there are any items?
	int temp = 0;
	for (int i = 0; i < 5; i++) {
		p->getInv(i);//haha i knew we were gonna use this member, gotta remember to use it in the main program
	}
	if (temp <= 0) {
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