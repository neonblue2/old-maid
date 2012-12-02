/*
 * Game.h
 *
 *  Created on: 28/10/2012
 *      Author: jamesmadley
 */

#ifndef GAME_H_
#define GAME_H_

#include "Dealer.h"

class Game {
public:
	Game();

private:
	string difficulty;
	bool playerTurn;

	void take(Player players[], int playerNum);
	void place(Player players[], int playerNum);
	void done(Player players[], int playerNum);
};

#endif /* GAME_H_ */
