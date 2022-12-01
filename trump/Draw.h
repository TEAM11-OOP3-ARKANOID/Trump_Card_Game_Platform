#pragma once
#include "Card.h"
#include <deque>


class Draw
{
public:
	Draw();
	~Draw();

	void print();
	void drawcard(TrumpCard* card);


private:
	std::deque<TrumpCard*> draw;
};