#include <iostream>
#include "deck.h"


using namespace std;

int main() {
	Deck deck;
	deck.Shuffle();
	vector<Card> hand = deck.GiveCards(5);
	for (int i = 0; i < 5; i++) {
		cout << hand[i].GetRank() << " of " << hand[i].GetSuit() << endl;
	}
	return 0;

}
