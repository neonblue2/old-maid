#ifndef DECK_H_
#define DECK_H_

#include "Card.h"

class Deck {
public:
	Deck();
	Card cardLoc(const int location);
	void printDeck();
	
private:
	Card deck[53];
};

#endif
