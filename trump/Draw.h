#pragma once
#include "Card.h"
#include <deque>


class Draw
{
public:
	Draw();
	~Draw();

	void print();
	void print_winform(System::Windows::Forms::TextBox^ textBox1);
	void drawcard(TrumpCard* card);
	void deletesamecard();
	int getsize();
	TrumpCard* popcard();
	TrumpCard* checkcard();
	int BJsum();

	void print_dealer(System::Windows::Forms::TextBox^ textBox1);

private:
	std::deque<TrumpCard*> draw;
};