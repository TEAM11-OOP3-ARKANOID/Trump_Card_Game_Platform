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
	std::vector<Draw> playercard;


public:


	OldMaidGame();

	//void card_throwaway(Draw* draw);

	std::vector<Draw> getplayercard() {
		return playercard;
	}

	int getplayernum() {
		return playernum;
	}

	//void Myturn() {
	//	//카드를 1장뽑는다.
	//}

	//void AIturn() {
	//	//내 차례가 지나고 AI차례 돌려준다 ( 플레이어 수 만큼 ) 
	//}

	//void lose() {
	//	//마지막에 조커를 가지고 있으면 진다.계속 체크
	//}

	~OldMaidGame();
};

