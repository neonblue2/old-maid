#include "Deck.h"

using namespace std;

Deck::Deck() {
	string suits[] = {"Spade", "Diamond", "Heart", "Club"};
	string values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
	srand(time(NULL));
	for (int s = 0; s < 4; s++) {
		for (int v = 0; v < 13; v++) {
			int loc = rand() % 53;
			if (deck[loc] == "") {
				deck[loc].setSuit(suits[s]);
				deck[loc].setValue(values[v]);
			} else {
				v--; //To counter to increment in the loop
			}
		}
	}
	//Insert Joker into last available space
	for (int i = 0; i < 53; i++) {
		if (deck[i] == "") {
			deck[i].setValue("Joker");
			break;
		}
	}
}

Card Deck::cardLoc(int location) {
	return deck[location];
}

void Deck::printDeck() {
	for (int i = 0; i < 53; i++) {
		cout << deck[i].getValue() << " of " << deck[i].getSuit() << endl;
	}
}
