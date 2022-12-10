#include "BlackJackGame.h"

BlackJackGame::BlackJackGame()
{
	srand(time(nullptr));
	Deck deck;
	deck.shuffle();
	


	for (int i = 0; i < 2; i++) { // 무조건 딜러가 먼저 턴을 가져감
		TrumpCard* card = deck.DrawCard();
		if (card->GetSuit() == 7) { // 조커는 필요 없음
			deck.PopCard();
			i--;
		}
		else {
			dealer->drawcard(card);
			deck.PopCard();
		}
	}
	for (int i = 0; i < 1; i++) {
		TrumpCard* card = deck.DrawCard();
		if (card->GetSuit() == 7) { // 조커는 필요 없음
			deck.PopCard();
			i--;
		}
		else {
			player->drawcard(card);
			deck.PopCard();
		}
	}
}

