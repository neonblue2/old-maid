/*
 * Dealer.cpp
 *
 *  Created on: 28/10/2012
 *      Author: jamesmadley
 */

#include "Dealer.h"

void Dealer::deal(int playerNum, Player players[], Deck deck) {
	//Divide the deck by the number of players and deal an equal number of cards to each
	for (int i = 0; i < playerNum; i++) {
		for (int j = i*(53/playerNum); j < (i+1)*(53/playerNum); j++) {
			players[i].recieveCard(deck.cardLoc(j));
		}
	}

	//Determine how many cards are left over
	int leftover = (int)(53/playerNum) * playerNum;

	//Deal the remaining cards
	int i = 0;
	while (leftover < 53) {
		players[i].recieveCard(deck.cardLoc(leftover));
		leftover++;
		if (i < playerNum-1) {
			i++;
		} else {
			i = 0;
		}
	}
}

void Dealer::checkInGame(Player player[], int playerNum) {
	for (int i = 0; i < playerNum; i++) {
		if (player[i].cardsInHand() == 0) {
			player[i].leaveGame();
		}
	}
}
