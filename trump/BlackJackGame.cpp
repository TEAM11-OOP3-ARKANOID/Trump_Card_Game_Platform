#include "BlackJackGame.h"

BlackJackGame::BlackJackGame()
{
	srand(time(nullptr));
	Deck deck;
	deck.shuffle();
	


	for (int i = 0; i < 2; i++) { // ������ ������ ���� ���� ������
		TrumpCard* card = deck.DrawCard();
		if (card->GetSuit() == 7) { // ��Ŀ�� �ʿ� ����
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
		if (card->GetSuit() == 7) { // ��Ŀ�� �ʿ� ����
			deck.PopCard();
			i--;
		}
		else {
			player->drawcard(card);
			deck.PopCard();
		}
	}
}

