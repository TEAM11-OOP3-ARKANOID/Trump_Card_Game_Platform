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
	int playernum = 2;
	std::vector<Draw*> playercard;


public:


	OldMaidGame();

	//void card_throwaway(Draw* draw);

	std::vector<Draw*> getplayercard() {
		return playercard;
	}

	int getplayernum() {
		return playernum;
	}

	void Myturn() {
		
		printf("\n");
		//카드 뽑기
		//다음플레이어 카드 하나 제거
		//를 가져옴
		playercard[0]->drawcard(playercard[1]->popcard());
		printf("\n");
		//를 보여줌
		
		//중복 제거
		playercard[0]->deletesamecard();

		playercard[0]->print();
		

	}

	void AIturn() {
		//내 차례가 지나고 AI차례 돌려준다 ( 플레이어 수 만큼 ) 
	}

	//void lose() {
	//	//마지막에 조커를 가지고 있으면 진다.계속 체크
	//}

	~OldMaidGame();
};

