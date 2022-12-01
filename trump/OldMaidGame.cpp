#include "OldMaidGame.h"
#include <iostream>

OldMaidGame::OldMaidGame() {
	srand(time(nullptr));
	Deck deck;
	deck.shuffle();


	for (int i = 0; i < playernum; i++) {
		//플레이어 53장 카드 나눠갖기
		Draw d;
		playercard.push_back(d);

	}
	int maxcard = 53;
	int share = 53 / playernum;
	int remainder = 53 % playernum;
	for (int i = 0; i < playernum; i++) {
		//플레이어 53장 카드 나눠갖기	
		if (i < (playernum - 1)) {
			for (int j = 0; j < share; j++) {
				TrumpCard* card = deck.DrawCard();
				playercard[i].drawcard(card);
				deck.PopCard();
			}
		}
		else {
			for (int j = 0; j < remainder; j++) {
				TrumpCard* card = deck.DrawCard();
				playercard[i].drawcard(card);
				deck.PopCard();
			}
		}
	}
}
OldMaidGame::~OldMaidGame() {
};