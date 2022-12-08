#pragma once
#include "Deck.h"
#include "Draw.h"
#include "Card.h"
#include <iostream>
#include <ctime>
#include <vector>
class OldMaidGame
{

private:
	static int playernum;
	std::vector<Draw*> playercard;
	int finish = 0;


public:


	OldMaidGame();
	OldMaidGame(int num);
	//void card_throwaway(Draw* draw);

	std::vector<Draw*> getplayercard() {
		return playercard;
	}

	int getplayernum() {
		return playernum;
	}

	void Myturn() {
		if (finish == 0) {
			printf("\n");
			//카드 뽑기
			//다음플레이어 카드 하나 제거
			//를 가져옴
			TrumpCard* tempcard = playercard[1]->popcard();
			printf("\n[Drawcard]: ");
			tempcard->print();
			playercard[0]->drawcard(tempcard);
			printf("\n");
			//를 보여줌

			//중복 제거
			playercard[0]->deletesamecard();

			playercard[0]->print();
			if (win()) {
				finish = 1;
			}
		}
		

	}

	void AIturn() {
		//내 차례가 지나고 AI차례 돌려준다 ( 플레이어 수 만큼 )
		
		for (int i = 0; i < playernum-1; i++) {

			if (finish == 0) {
				int temp = i + 1;
				int temp2 = i + 2;
				if (temp2 >= playernum)temp2 = 0;
				playercard[temp]->drawcard(playercard[temp2]->popcard());
				playercard[temp]->deletesamecard();
				printf("\nplayer %d's left card : %d ", temp, playercard[temp]->getsize());
				
				if (win()) {
					finish = 1;
				}
			}			
		}
	}

	bool win() {
		//마지막에 조커를 가지고 있으면 진다.계속 체크
		
		for (int i = 0; i < playernum ; i++) {
			if (playercard[0]->getsize() == 0) {
				printf("\nYou win!!!!!!!");
				return true;
			}
			if (playercard[i]->getsize() == 1) {
				int check = 0;
				for (int j = 0; j < playernum; j++) {
					if (playercard[j]->getsize()!=0&&j!=i) {
						check = 1;
					}
				}
				if (check == 0) {

					printf("\nplayer %d lose",i);
					return true;
				}
			}
		}
		return false;
	}

	~OldMaidGame();
};

