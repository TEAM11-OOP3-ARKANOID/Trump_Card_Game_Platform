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

	void Myturn(System::Windows::Forms::TextBox^ textBox1) {
		if (finish == 0) {
			//printf("\n");
			//카드 뽑기
			//다음플레이어 카드 하나 제거
			//를 가져옴
			int getnextplayerscard = 1;
			for (int i = 0; i < playernum-1; i++) {
				int temp = i + 1;
				getnextplayerscard = temp;
				if (playercard[temp]->getsize() != 0) {
					break;
				}
				
			}
			TrumpCard* tempcard = playercard[getnextplayerscard]->popcard();
			//printf("\n[Drawcard]: ");
			textBox1->AppendText("\r\n[Drawcard]: ");
			tempcard->print_winform(textBox1);
			textBox1->AppendText("\r\n");
			playercard[0]->drawcard(tempcard);
			printf("\n");
			//를 보여줌

			//중복 제거
			playercard[0]->deletesamecard();
			
			if (playercard[0]->getsize() != 0) {

				playercard[0]->print_winform(textBox1);
			}
			if (win(textBox1)) {
				finish = 1;
			}
		}
		

	}

	void AIturn(System::Windows::Forms::TextBox^ textBox1) {
		//내 차례가 지나고 AI차례 돌려준다 ( 플레이어 수 만큼 )
		
		for (int i = 0; i < playernum-1; i++) {
			int temp = i + 1; //현재 플레이어
			int temp2 = i + 2; // 그 다음 플레이어
			if (temp2 >= playernum)temp2 = 0; //마지막->>0

			if (finish == 0 && playercard[temp]->getsize()!=0) {
				

				int getnextplayerscard = temp2;
				for (int j = 0; j < playernum-1 ; j++) {

					
					if (playercard[temp2]->getsize() != 0) {
						break;
					}
					temp2++;
					if (temp2 >= playernum)temp2 =0;

					getnextplayerscard = temp2;
				}

				playercard[temp]->drawcard(playercard[getnextplayerscard]->popcard());
				playercard[temp]->deletesamecard();
				printf("\nplayer %d's left card : %d \n", temp, playercard[temp]->getsize());
				textBox1->AppendText("player"+ System::Convert::ToString(temp) + "'s left card : " + System::Convert::ToString(playercard[temp]->getsize()) +"\r\n");
				/*if (playercard[temp]->getsize() != 0) {
					playercard[temp]->print();
				}*/
				if (win(textBox1)) {
					finish = 1;
				}
			}
			else if (finish == 0){
				printf("\nplayer %d's left card : %d \n", temp, 0);
				textBox1->AppendText("player" + System::Convert::ToString(temp) + "'s left card : 0" + "\r\n");
			}
		}
		/*printf("\nthis moment \n");
		for (int i = 0; i < playernum ; i++) {
			printf("player %d : ", i);
			playercard[i]->print();
			printf("\n");
		}*/
	}

	bool win(System::Windows::Forms::TextBox^ textBox1) {
		//마지막에 조커를 가지고 있으면 진다.계속 체크
		
		for (int i = 0; i < playernum ; i++) {
			/*if (playercard[i]->getsize() == 0 && i != 0) {
				printf("\nplayer %d done", i);
			}*/
			if (playercard[0]->getsize() == 0) {
				printf("\nYou win!!!!!!!");
				textBox1->AppendText("\nYou win!!!!!!!");
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
					if (i == 0) {
						printf("\nYou lose :(");
						textBox1->AppendText("\nYou lose :(");
						return true;
					}
					printf("\nplayer %d lose",i);
					textBox1->AppendText("\nplayer %d lose" + System::Convert::ToString(i));
					return true;
				}
			}
		}
		return false;
	}

	~OldMaidGame();
};

