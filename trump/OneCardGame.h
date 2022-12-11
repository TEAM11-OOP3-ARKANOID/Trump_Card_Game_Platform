#pragma once
#include "Deck.h"
#include "Draw.h"
#include "Card.h"
#include <iostream>
#include <ctime>
#include <time.h>
#include <vector>
#include <Windows.h>

class Player {
private:
	bool isUser;
public:
	std::vector<TrumpCard> currentHand;

	Player(bool isUserParam)
	{
		isUser = isUserParam;
	}
	//void PrintPlayerInfo(System::Windows::Forms::TextBox^ textBox1) {
	void PrintPlayerInfo() {
		std::cout << (isUser ? "user" : "not user");
		for (int j = 0; j < currentHand.size(); j++) {
			currentHand[j].print();
		}
	}
	//TrumpCard PlayCard(int targetIndex, System::Windows::Forms::TextBox^ textBox1) { // 한 장의 카드를 드로우한 뒤 덱에서 삭제
	TrumpCard PlayCard(int targetIndex) { // 한 장의 카드를 드로우한 뒤 덱에서 삭제
		TrumpCard card = currentHand[targetIndex];
		currentHand.erase(currentHand.begin() + targetIndex);

		return card;
	}
};

class OneCardGame {
private:
	int attackOverlap;
	int currentTurn;
public:
	Deck currentDeck;
	std::vector<TrumpCard> currentTrash;
	std::vector<Player> currentPlayer;
	bool gameEnd;

	OneCardGame() {
		Deck currentDeck;
		currentPlayer.reserve(4);
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				currentPlayer.push_back(Player(true));
			}
			else {
				currentPlayer.push_back(Player(false));
			}
		}
		currentTrash = {};
		attackOverlap = 0;
		currentTurn = 0;
		gameEnd = false;
	}

	~OneCardGame() { 
	}

	bool hasSameRankSuit(TrumpCard card1, TrumpCard card2) {
		if (card1.GetRank() == card2.GetRank()) {
			return true;
		}
		else if (card1.GetSuit() == card2.GetSuit()) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isAvailable(TrumpCard targetCard) {
		TrumpCard trashTop = currentTrash.back();
		trashTop.print();

		if (trashTop.GetSuit() == 7) {
			return true;
		}
		return hasSameRankSuit(trashTop, targetCard);

		//	return hasSameRankSuit(trashTop, targetCard);

		//if (trashTop.GetRank() == 2 || trashTop.GetRank() == 14 || trashTop.GetSuit() == 7) {
		//	if (targetCard.GetRank() == 2 || targetCard.GetRank() == 14 || targetCard.GetSuit() == 7) {
		//		return hasSameRankSuit(trashTop, targetCard);
		//	}
		//	else {
		//		return false;
		//	}
		//}
		//else {
		//	return hasSameRankSuit(trashTop, targetCard);
		//}
	}

	void playCardCpu(System::Windows::Forms::TextBox^ textBox1) { //카드를 냄
		for (int i = 1; i < 4; i++) { //컴퓨터의 턴 구현
			std::vector<TrumpCard> availableCard;
			std::vector<int> availableCardIndex;
			int repeat = 0;
			while (repeat == 0 || availableCardIndex.size() > 0) {
				Sleep(100);
				availableCard.clear();
				availableCardIndex.clear();
				for (int j = 0; j < currentPlayer[i].currentHand.size(); j++) {
					if (isAvailable(currentPlayer[i].currentHand[j])) {
						availableCard.push_back(currentPlayer[i].currentHand[j]);
						availableCardIndex.push_back(j);
					}
				}
				if (availableCardIndex.size() > 0) {
					srand(time(NULL));
					int randnum = rand() % availableCard.size();

					textBox1->AppendText("computer " + i + "'s play : ");

					availableCard[randnum].print_winform(textBox1); 
					textBox1->AppendText("\r\n");

					currentTrash.push_back(currentPlayer[i].PlayCard(availableCardIndex[randnum]));

					for (int j = 1; j < 4; j++) {
						textBox1->AppendText("computer " + j + ": " + currentPlayer[j].currentHand.size() + " ");
					}
					textBox1->AppendText("\r\n");
				}
				if (availableCardIndex.size() == 0 && repeat == 0) {   //만약 1개도 못냈는 데 낼 게 없다면 1장 가져가기
					currentPlayer[i].currentHand.push_back(*currentDeck.DrawCard());
				}
				repeat++;
			}
			if (currentPlayer[i].currentHand.size() == 0) {
				gameEnd = true;
				textBox1->AppendText("You lose");
				break;
			}
		}
	}

	void setGame(System::Windows::Forms::TextBox^ textBox1) {
		currentDeck.shuffle();

		currentTrash.push_back( *currentDeck.DrawCard());

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 4; j++) {
				currentPlayer[j].currentHand.push_back(*currentDeck.DrawCard());
				//currentPlayer[j].currentHand[i].print();
				//std::cout << (isAvailable(currentPlayer[j].currentHand[i]) ? "is Available" : "is not Available" ) << std::endl;
			}
		}

	};


	void printStatus() {
		currentDeck.print();
	};

};
