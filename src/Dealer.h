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
	static void deal(const int playerNum, Player players[], Deck deck);
	static void checkInGame(const int playerNum, Player player[]);
};

#endif /* DEALER_H_ */
