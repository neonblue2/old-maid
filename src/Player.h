#ifndef PLAYER_H_
#define PLAYER_H_

#include "Player.h"
#include "Card.h"

class Player {
public:
	Player();
	void setSkill(const string gameDifficulty);
	void receiveCard(Card card);
	void placePair(Card c1, Card c2);
	void loseCard(Card card);
	void leaveGame();
	Card randCard();
	Card specificCard(int location);
	int cardsInHand();
	bool isInGame();
	void printHand();
	
private:
	Card hand[53];
	int skill;
	int inHand;
	bool inGame;
};

#endif
