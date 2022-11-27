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

	if (TrumpCard::Suits s = TrumpCard::joker) { // ��Ŀ�� Ư�� ī���̹Ƿ� ���� �M, ���� ����(�������, ����, ��ī��)�� ���� �߰�/���� ������ ������� ������ ����
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

void Deck::shuffle() // ī�嵦�� ����
{
	std::random_shuffle(deck.begin(), deck.end());
}

TrumpCard* Deck::TopCard() // �� ���� ī�带 ������
{
	return deck.front();
}

void Deck::PopCard()// ���� �� �� ī�带 ���� �ڷ� ����. �̰����� ��ο�, �ƴϸ� ������ ������ Ȱ�� ����
{
	deck.push_back(deck.front());
	deck.erase(deck.begin()); // ���� �� ó�� ī�带 �ڷ� ���� ��, �ش� ī�带 �����ϴ� ���
}

TrumpCard* Deck::DrawCard() // �� ���� ī�带 ��ο��� �� ������ ����
{
	TrumpCard* card = deck.front();
	deck.erase(deck.begin());
	return card;
}

void Deck::BacktoDeck(TrumpCard* card)
{
	deck.push_back(card);
}

