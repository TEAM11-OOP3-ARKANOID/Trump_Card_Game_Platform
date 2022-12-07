#pragma once

#include <deque>;
#include "Card.h"

class Deck
{
public:
	Deck();
	~Deck();

	void print();
	void shuffle();

	TrumpCard* TopCard();
	void PopCard();
	TrumpCard* DrawCard();
	void BacktoDeck(TrumpCard* card);

private:
	std::deque<TrumpCard*> deck;
};

