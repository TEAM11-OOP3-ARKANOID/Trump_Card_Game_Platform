#include "Deck.h"
#include <algorithm>
#include <iostream>

Deck::Deck()
	: deck()
{
	for (TrumpCard::Ranks r = TrumpCard::two; r <= TrumpCard::ace; r = static_cast<TrumpCard::Ranks>(static_cast<int>(r) + 1)) {
		for (TrumpCard::Suits s = TrumpCard::heart; s <= TrumpCard::spade; s = static_cast<TrumpCard::Suits>(static_cast<int>(s) + 1)) {
			deck.push_front(new TrumpCard(r, s));
		}
	}

	if (TrumpCard::Suits s = TrumpCard::joker) { // 조커는 특수 카드이므로 따로 뻄, 추후 게임(도둑잡기, 블랙잭, 원카드)에 따라 추가/제거 가능한 방식으로 수정할 예정
		TrumpCard::Ranks r = TrumpCard::two;
		deck.push_front(new TrumpCard(r, s));
		
	}
}

Deck::~Deck()
{
	for (TrumpCard* card : deck) {
		delete card;
	}
	deck.clear();
}

void Deck::print()
{
	for (TrumpCard* card : deck) {
		card->print();
		std::cout << " ";
	}
}

void Deck::shuffle() // 카드덱을 섞기
{
	std::random_shuffle(deck.begin(), deck.end());
}

TrumpCard* Deck::TopCard() // 맨 윗장 카드를 리턴함
{
	return deck.front();
}

void Deck::PopCard()// 덱의 맨 윗 카드를 덱의 뒤로 보냄. 이것으로 드로우, 아니면 버리기 등으로 활용 가능
{
	deck.push_back(deck.front());
	deck.erase(deck.begin()); // 덱의 맨 처음 카드를 뒤로 보낸 뒤, 해당 카드를 삭제하는 방식
}

TrumpCard* Deck::DrawCard() // 한 장의 카드를 드로우한 뒤 덱에서 삭제
{
	TrumpCard* card = deck.front();
	deck.erase(deck.begin());
	return card;
}

void Deck::BacktoDeck(TrumpCard* card)
{
	deck.push_back(card);
}

