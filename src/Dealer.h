/*
 * Dealer.h
 *
 *  Created on: 28/10/2012
 *      Author: jamesmadley
 */

#ifndef DEALER_H_
#define DEALER_H_

#include "Deck.h"
#include "Player.h"

class Dealer {
public:
	static void deal(int playerNum, Player players[], Deck deck);
	static void checkInGame(Player player[], int playerNum);
};

#endif /* DEALER_H_ */
