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
	void pulloutcard(Draw* nextplayerhand);
	void deletesamecard();
	std::deque<TrumpCard*> gethand();
	TrumpCard* popcard();

private:
	std::deque<TrumpCard*> draw;
};