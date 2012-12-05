/*
 * Dealer.cpp
 *
 *  Created on: 28/10/2012
 *      Author: jamesmadley
 */

#include "Dealer.h"

void Dealer::deal(const int playerNum, Player players[], Deck deck) {
	//Divide the deck by the number of players and deal an equal number of cards to each
	for (int i = 0; i < playerNum; i++) {
		for (int j = i*(53/playerNum); j < (i+1)*(53/playerNum); j++) {
			players[i].receiveCard(deck.cardLoc(j));
		}
	}

	//Determine how many cards are left over
	int leftover = (int)(53/playerNum) * playerNum;

	//Deal the remaining cards
	int i = 0;
	while (leftover < 53) {
		players[i].receiveCard(deck.cardLoc(leftover));
		leftover++;
		if (i < playerNum-1) {
			i++;
		} else {
			i = 0;
		}
	}
}

void Dealer::checkInGame(const int playerNum, Player player[]) {
	for (int i = 0; i < playerNum; i++) {
		if (player[i].cardsInHand() == 0) {
			player[i].leaveGame();
		}
	}
}

int Dealer::maxCardsInHands(const int playerNum, Player players[], const int takingPlayer) {
	int maxCards = 0;
	for (int i = 0; i < playerNum; i++) {
		if (playerNum != takingPlayer) {
			maxCards = (players[i].cardsInHand() > maxCards) ? (players[i].cardsInHand()) : maxCards;
		}
	}
	return maxCards;
}
