#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <cstdlib>

using namespace std;

class Card {
public:
	Card();
	void setSuit(string suit);
	void setValue(string value);
	string getSuit();
	string getValue();
	
	friend bool operator ==(const Card& card, const string& str);
	friend bool operator ==(const Card& c1, const Card& c2);
	friend bool operator !=(const Card& card, const string& str);
	
	friend std::ostream& operator <<(std::ostream& out, const Card& c);

private:
	string suit_;
	string value_;
};

#endif
