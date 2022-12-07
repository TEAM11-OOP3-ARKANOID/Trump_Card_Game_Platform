#include "Draw.h"
#include <iostream>
Draw::Draw() : draw() {

}


Draw::~Draw()
{
	/*for (TrumpCard* card : draw) {
		delete card;
	}
	draw.clear();*/
}

void Draw::print()
{
	std::cout << "In my Hand: ";
	for (TrumpCard* card : draw) {
		card->print();
		std::cout << " ";
	}
}

std::deque<TrumpCard*> Draw::gethand()
{
	return draw;
}

void Draw::pulloutcard(Draw* nextplayerhand)
{
	nextplayerhand->gethand().pop_back();
	for (TrumpCard* card : nextplayerhand->gethand()) {
		card->print();
		std::cout << " ";
	}
}


//중간것도 뽑을수잇게해야함
void Draw::drawcard(TrumpCard* card)
{
	draw.push_front(card);
}
void Draw::deletesamecard()
{
	std::deque<TrumpCard*>::iterator iter;
	std::deque<TrumpCard*>::iterator iter2;
	
	
	int check = 0;
	while (check ==0) {
		check = 1;
		for (int i = 0; i < draw.size()-1; i++) {
			
			for (int j = i + 1; j < draw.size(); j++) {

				if ((draw[i]->GetRank()) == (draw[j]->GetRank())) {
					

					draw.erase(draw.begin()+j);

					check = 2;
					break;
				}
				if (check == 2) {
					draw.erase(draw.begin() + i);
					check = 0;
					break;
				}
			}
		}



		
		/*
		check = 1;
		for (iter = draw.begin(); iter != draw.end(); iter++) {
			for (iter2 = (iter+1); iter2 != draw.end(); iter2++) {
				printf("gd");
				if (*iter == *iter2) {
					//둘이 숫자 같으면 둘다 지워줌
					printf("same!!!!!!!!!!");
					
					//draw.erase(iter2);
					
					check = 2;
					break;

				}
			}
			if (check == 2) {
				//draw.erase(iter);
				check = 0;
				break;
			}

		}*/
		
	}
	
}

TrumpCard* Draw::popcard()
{
	TrumpCard* card = draw.front();
	draw.pop_front();
	return card;
}
