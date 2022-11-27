#include "Draw.h"
#include <iostream>

Draw::Draw(TrumpCard* card)
	: draw()
{
	draw.push_front(card);
}

Draw::~Draw()
{
	for (TrumpCard* card : draw) {
		delete card;
	}
	draw.clear();
}

void Draw::print()
{
	std::cout << "In my Hand: ";
	for (TrumpCard* card : draw) {
		card->print();
		std::cout << " ";
	}
}
