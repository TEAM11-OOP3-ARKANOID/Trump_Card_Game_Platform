#include "OldMaidGame.h"
#include <iostream>

int OldMaidGame::playernum = 2;

OldMaidGame::OldMaidGame(int num) {
	printf("%d", num);
	playernum = num;
}
OldMaidGame::OldMaidGame() {
	srand(time(nullptr));
	Deck deck;
	deck.shuffle();
	


	for (int i = 0; i < playernum; i++) {
		//플레이어 53장 카드 나눠갖기
		Draw *d = new Draw;
		playercard.push_back(d);

	}
	int maxcard = 53;
	int share = maxcard / playernum;
	int remainder = maxcard - (share * (playernum - 1));
	//printf("%d, %d",share,remainder);
	for (int i = 0; i < playernum; i++) {

		//플레이어 53장 카드 나눠갖기	
		if (i < (playernum - 1)) {
			for (int j = 0; j < share; j++) {
				TrumpCard* card = deck.DrawCard();
				playercard[i]->drawcard(card);
				
			}
		}
		else {
			for (int j = 0; j < remainder; j++) {
				TrumpCard* card = deck.DrawCard();
				playercard[i]->drawcard(card);
				
			}
		}
	}
	
}
OldMaidGame::~OldMaidGame() {
};