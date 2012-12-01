/*
 * Game.cpp
 *
 *  Created on: 28/10/2012
 *      Author: jamesmadley
 */

#include "Game.h"

using namespace std;

Game::Game() {
	Deck deck;
	string command;
	playerTurn = true;
	int playerNum;

	cout << "Number of players: ";
	cin >> playerNum;
	cout << endl;

	Player players[playerNum];

	Dealer::deal(playerNum, players, deck);

	players[0].printHand();
	cout << endl;

	while (cin >> command) {
		cout << endl;
		if (command == "Take" && playerTurn) {
			take(players, playerNum);
		} else if (command == "Place") {
			place(players, playerNum);
		} else if (command == "Done") {
			done(players, playerNum);
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
}

void Game::take(Player players[], int playerNum) {
	int player;
	cin >> player;
	if (players[player].isInGame()) {
		Card chosenCard = players[player].randCard();
		players[player].loseCard(chosenCard);
		players[0].recieveCard(chosenCard);
		cout << "You received the " << chosenCard << endl << endl;
		Dealer::checkInGame(players, playerNum);
		playerTurn = false;
	} else {
		cout << "That player is out of the game!" << endl;
	}
}

void Game::place(Player players[], int playerNum) {
	int c1, c2;
	while (cin >> c1 >> c2
			&& (c1 > players[0].cardsInHand() || c2 > players[0].cardsInHand())) {
		cout << "Not a valid card." << endl << endl;
		cout << "Place ";
	}
	players[0].placePair(players[0].specificCard(c1-1), players[0].specificCard(c2-1));
	cout << endl;
	Dealer::checkInGame(players, playerNum);
}

void Game::done(Player players[], int playerNum) {
	for (int pN = 1; pN < playerNum; pN++) {
		if (players[pN].isInGame()) {
			int chosenPlayer;
			do {
				chosenPlayer = rand() % playerNum;
			} while (chosenPlayer == pN || !players[chosenPlayer].isInGame());
			Card chosenCard = players[chosenPlayer].randCard();
			players[chosenPlayer].loseCard(chosenCard);
			players[pN].recieveCard(chosenCard);
			Dealer::checkInGame(players, playerNum);
			if (chosenPlayer == 0) {
				cout << "You lost the " << chosenCard << endl;
			}
			for (int i = 0; i < players[pN].cardsInHand()-1; i++) {
				for (int j = i+1; j < players[pN].cardsInHand(); j++) {
					players[pN].placePair(players[pN].specificCard(i),
						players[pN].specificCard(j));
				}
			}
			Dealer::checkInGame(players, playerNum);
		}
	}
	playerTurn = true;
}
