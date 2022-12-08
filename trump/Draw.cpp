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

void Draw::print_winform(System::Windows::Forms::TextBox^ textBox1)
{
	textBox1->AppendText("In my Hand: ");
	for (TrumpCard* card : draw) {
		card->print_winform(textBox1);
		textBox1->AppendText(" ");
	}
	textBox1->AppendText("\r\n");
}

int Draw::getsize()
{
	return draw.size();
}




//중간것도 뽑을수잇게해야함
void Draw::drawcard(TrumpCard* card)
{
	draw.push_front(card);
}
void Draw::deletesamecard()
{
	
	
	
	int check = 0;
	while (check ==0) {
		if (draw.size() == 0) {
			return;
		}
		check = 1;
		for (int i = 0; i < draw.size()-1; i++) {
			
			for (int j = i + 1; j < draw.size(); j++) {

				if ((draw[i]->GetRank()) == (draw[j]->GetRank())) {
					//printf("\n[drawsamecard1]\n");
					//draw[j]->print();
					
					draw.erase(draw.begin()+j);
					//printf("\n[drawsamecard2]\n");
					//draw[i]->print();
					//printf("\n");
					draw.erase(draw.begin() + i);
					check = 2;
					break;
				}
			
			}
			if (check == 2) {
				check = 0;
				break;
			}
		}


	}
	
}

TrumpCard* Draw::popcard()
{
	
	srand((unsigned int)time(NULL));
	int drawlen = draw.size();
	int drawran = rand() % drawlen;
	TrumpCard* card = draw[drawran];
	//printf("\n[drawcard]\n");
	//card->print();
	draw.erase(draw.begin() + drawran);
	return card;
}
TrumpCard* Draw::checkcard()
{
	
	TrumpCard* card = draw.front();
	//printf("\n[drawcard]\n");
	//card->print();
	return card;
}