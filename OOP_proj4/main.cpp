#include "Deck.h"
#include "Draw.h"
#include <iostream>
#include <ctime>

int main() {
	srand(time(nullptr));
	Deck deck;
	deck.shuffle();
	deck.print();
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		TrumpCard* card = deck.DrawCard();
		card->print();
		deck.PopCard();
	}
	std::cout << std::endl;
	deck.print();
	std::cout << std::endl;

	system("pause");
	return 0;
}