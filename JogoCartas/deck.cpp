#include "deck.h"

Deck::Deck() {
	// Initialize the deck with 52 cards
	int index = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			cards_[index] = Card(static_cast<Card::Suit>(i), static_cast<Card::Rank>(j));
			index++;
		}
	}
}
