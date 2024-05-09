#pragma once

#include <vector>
#include <algorithm>
#include "card.h"

using namespace std;

class Deck {
public:
	Deck();
	~Deck();

private:
	Card cards_[52];
	vector<Card> GiveCards(int quantity);

};
