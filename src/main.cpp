#include "Deck.h"
#include "Player.h"

void deal(int playerNum, Player players[], Deck deck);
void checkInGame(Player player[], int playerNum);

using namespace std;

int main() {
	Deck deck;
	string command;
	bool playerTurn = true;
	int playerNum;
	
	cout << "Number of players: ";
	cin >> playerNum;
	cout << endl;
	
	Player players[playerNum];
	
	deal(playerNum, players, deck);
	
	players[0].printHand();
	cout << endl;
	
	while (cin >> command) {
		cout << endl;
		if (command == "Take" && playerTurn) {
			int player;
			cin >> player;
			if (players[player].isInGame()) {
				Card chosenCard = players[player].randCard();
				players[player].loseCard(chosenCard);
				players[0].recieveCard(chosenCard);
				cout << "You received the " << chosenCard << endl << endl;
				checkInGame(players, playerNum);
				playerTurn = false;
			} else {
				cout << "That player is out of the game!" << endl;
			}
		} else if (command == "Place") {
			int c1, c2;
			cin >> c1 >> c2;
			while (c1 > players[0].cardsInHand() || c2 > players[0].cardsInHand()) {
				cout << "Not a valid card." << endl << endl;
				cout << "Place ";
				cin >> c1 >> c2;
			}
			players[0].placePair(players[0].specificCard(c1-1), players[0].specificCard(c2-1));
			cout << endl;
			checkInGame(players, playerNum);
		} else if (command == "Done") {
			for (int pN = 1; pN < playerNum; pN++) {
				if (players[pN].isInGame()) {
					int chosenPlayer = rand() % playerNum;
					while (chosenPlayer == pN || !players[chosenPlayer].isInGame()) {
						chosenPlayer = rand() % playerNum;
					}
					Card chosenCard = players[chosenPlayer].randCard();
					players[chosenPlayer].loseCard(chosenCard);
					players[pN].recieveCard(chosenCard);
					checkInGame(players, playerNum);
					if (chosenPlayer == 0) {
						cout << "You lost the " << chosenCard << endl;
					}
					for (int i = 0; i < 52; i++) {
						for (int j = i+1; j < 53; j++) {
							players[pN].placePair(players[pN].specificCard(i),
								players[pN].specificCard(j));
						}
					}
					checkInGame(players, playerNum);
				}
			}
			playerTurn = true;
		}
		if (players[0].isInGame()) { 
			int playersIn = 1;
			for (int i = 1; i < playerNum; i++) {
				if (players[i].isInGame()) {
					playersIn++;
				}
			}
			if (playersIn == 1) {
				cout << "You lost the game!" << endl;
				break;
			}
			for (int i = 1; i < playerNum; i++) {
				cout << "Player " << i << " has " << players[i].cardsInHand()
					<< " cards in hand." << endl;
			}
			cout << endl;
			players[0].printHand();
			cout << endl;
		} else {
			cout << "You didn't lose the game!" << endl;
			break;
		}
	}
	
	return 0;
}

void deal(int playerNum, Player players[], Deck deck) {
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

void checkInGame(Player player[], int playerNum) {
	for (int i = 0; i < playerNum; i++) {
		if (player[i].cardsInHand() == 0) {
			player[i].leaveGame();
		}
	}
}
