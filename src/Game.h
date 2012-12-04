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
	bool playerTurn;

	void take(const int playerNum, Player players[]);
	void place(const int playerNum, Player players[]);
	void done(const int playerNum, Player players[]);
	void printOppNumCardsInHand(const int playerNum, Player players[]);
};

#endif /* GAME_H_ */
