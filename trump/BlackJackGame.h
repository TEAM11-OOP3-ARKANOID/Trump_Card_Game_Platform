#pragma once
#include "Deck.h"
#include "Draw.h"
#include "Card.h"
#include <iostream>
#include <ctime>


class BlackJackGame {
	
private:
	int finish = 0;
	int dealersum = 0;
	int playersum = 0;
	Draw* player = new Draw;
	Draw* dealer = new Draw;
	Deck deck;

public:
	BlackJackGame();

	int getPlayerSum() {return playersum;}
	Draw* getPlayer() { return player;}
	void PlayerHand(System::Windows::Forms::TextBox^ textBox1) { player->print_winform(textBox1); }

	void PickNewCard(System::Windows::Forms::TextBox^ textBox1) {
			//printf("\n");
			//카드 뽑기
		srand(time(nullptr));
		deck.shuffle();
		if (finish == 0) {
			TrumpCard* card = deck.DrawCard();
			if (card->GetSuit() == 7) {
				deck.PopCard();
				card = deck.DrawCard();
			}
			player->drawcard(card);
			deck.PopCard();
			playersum = 0;
			playersum = player->BJsum();


			//printf("\n[Drawcard]: ");
			textBox1->AppendText("\r\n[Player's hand]: ");
			player->print_winform(textBox1);
			textBox1->AppendText("\n");
			printf("\n");
			//현재 자신의 패를 보여줌

		}

			
	}

	void DealerAction(System::Windows::Forms::TextBox^ textBox1){
		if (finish == 0){
		textBox1->AppendText("\r\nIf below 16, dealer must draw, [Dealer's hand]: ");
		dealer->print_dealer(textBox1);
		textBox1->AppendText("\n");
		dealersum = dealer->BJsum();
		srand(time(nullptr));
		deck.shuffle();
		while (dealersum < 16 && playersum < 21) { // 딜러는 기계적으로 15 이하일 때만 드로우함. 단, 플레이어의 패배가 확정적인 경우에는 드로우를 하지않음.
			TrumpCard* card = deck.DrawCard();
			if (card->GetSuit() == 7) { // 조커는 필요 없음
				deck.PopCard();
				card = deck.DrawCard();
			}
			dealer->drawcard(card);
			deck.PopCard();
			dealersum = 0;
			dealersum = dealer->BJsum();
			textBox1->AppendText("\r\n[(Drawed) Dealer's hand]: ");
			dealer->print_dealer(textBox1);
			textBox1->AppendText("\n");
			printf("\n");
		}

		finish = 1;

		textBox1->AppendText("\r\nResult: \n");
		textBox1->AppendText("Your cards' sum : ");
		textBox1->AppendText(System::Convert::ToString(playersum));
		textBox1->AppendText("\r\nDealer cards' sum : ");
		textBox1->AppendText(System::Convert::ToString(dealersum));
		textBox1->AppendText("\n");

		switch (win(textBox1)) {
		case 0:
			textBox1->AppendText("\r\nDraw.... That was close!");
			break;
		case 1:
			textBox1->AppendText("\r\nYou Lose.... Try next time");
			break;
		case 2:
			textBox1->AppendText("\r\nCongratulation! You Won!");
			break;
		}
		}
	}

	int win(System::Windows::Forms::TextBox^ textBox1) { // 0 = draw, 1 = lost, 2 = win
		// 이하 승리/패배 조건, 순서는 우선도에 따른 것
		if (playersum == dealersum) { // 딜러와 플레이어 둘 다 패의 값이 같음
			return 0;
		}

		else if (playersum > 21) { // 플레이어의 패의 합이 21을 초과
			return 1;
		}

		else if (dealersum > 21) { // 딜러의 패의 합이 21을 초과
			return 2;
		}

		else if ((playersum == 21 && dealersum != 21) || dealersum > 21) { // 플레이어가 블랙잭
			textBox1->AppendText("\r\nBlack Jack");
			return 2;
		}

		else if (playersum != 21 && dealersum == 21) {  // 딜러가 블랙잭
			return 1;
		}



		int a = playersum - dealersum;
		if (a > 0) 
			return 2;
		else 
			return 1;
		return false;
	}
};