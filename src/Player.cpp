#include "Player.h"

using namespace std;

Player::Player() {
	skill = 100;
	inHand = 0;
	inGame = true;
}

void Player::setSkill(string gameDifficulty) {
	if (gameDifficulty == "easy") {
		skill = rand() % 33 + 1;
	} else if (gameDifficulty == "medium") {
		skill = rand() % 34 + 34;
	} else if (gameDifficulty == "hard") {
		skill = rand() % 33 + 68;
	}
}

void Player::recieveCard(Card card) {
	hand[inHand].setSuit(card.getSuit());
	hand[inHand].setValue(card.getValue());
	inHand++;
}

void Player::placePair(Card c1, Card c2) {
	if (c1.getValue() == c2.getValue()) {
		if ((c1.getSuit() == "Spade" && c2.getSuit() == "Club") ||
			(c1.getSuit() == "Club" && c2.getSuit() == "Spade") ||
			(c1.getSuit() == "Heart" && c2.getSuit() == "Diamond") ||
			(c1.getSuit() == "Diamond" && c2.getSuit() == "Heart")) {
			if (skill >= (rand() % 100 + 1) || inHand == 2) {
				loseCard(c1);
				loseCard(c2);
			}
		}
	}
}

void Player::loseCard(Card card) {
	for (int i = 0; i < inHand; i++) {
		if (hand[i] == card) {
			inHand--;
			hand[i].setSuit(hand[inHand].getSuit());
			hand[i].setValue(hand[inHand].getValue());
			hand[inHand].setSuit("");
			hand[inHand].setValue("");
			break;
		}
	}
}

void Player::leaveGame() {
	inGame = false;
}

Card Player::randCard() {
	Card card;
	
	int location = rand() % inHand;
	card.setValue(hand[location].getValue());
	card.setSuit(hand[location].getSuit());
	
	return card;
}

Card Player::specificCard(int location) {
	return hand[location];
}

int Player::cardsInHand() {
	return inHand;
}

bool Player::isInGame() {
	return inGame;
}

void Player::printHand() {
	for (int i = 0; i < inHand; i++) {
		cout << i+1 << ". " << hand[i] << endl;
	}
}
