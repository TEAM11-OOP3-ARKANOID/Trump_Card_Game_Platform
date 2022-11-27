#pragma once
#include "Card.h"
#include <deque>


class Draw
{
public:
	Draw(TrumpCard* card);
	~Draw();

	void print();


private:
	std::deque<TrumpCard*> draw;
};