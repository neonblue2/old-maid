#include "Card.h"

Card::Card() {
	suit_ = "";
	value_ = "";
}

void Card::setSuit(string suit) {
	suit_ = suit;
}

void Card::setValue(string value) {
	value_ = value;
}

string Card::getSuit() {
	return suit_;
}

string Card::getValue() {
	return value_;
}

bool operator ==(const Card& card, const string& str) {
	return (card.value_ == str);
}

bool operator ==(const Card& c1, const Card& c2) {
	return (c1.value_ == c2.value_ && c1.suit_ == c2.suit_);
}

bool operator !=(const Card& card, const string& str) {
	return (card.value_ != str);
}

std::ostream& operator <<(std::ostream& out, const Card& c) {
	out << c.value_;
	if (c != "" && c != "Joker") {
		out << " of " << c.suit_ << "s";
	}
	return out;
}
