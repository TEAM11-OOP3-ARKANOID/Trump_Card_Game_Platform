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
	//	//ī�带 1��̴´�.
	//}

	//void AIturn() {
	//	//�� ���ʰ� ������ AI���� �����ش� ( �÷��̾� �� ��ŭ ) 
	//}

	//void lose() {
	//	//�������� ��Ŀ�� ������ ������ ����.��� üũ
	//}

	~OldMaidGame();
};

