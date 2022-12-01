#pragma once

class TrumpCard {
public:
	enum Suits { // �� ī���� ����, �ƽ�Ű �ڵ忡 ���� ��Ʈ = 3....
		heart = 3,
		diamond,
		club,
		spade,
		joker
	};


	enum Ranks { // �� ī���� ����, Ace�� ��쿡�� Ư�� ���� ���� ��찡 ����
		two = 2,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten,
		jack,
		queen,
		king,
		ace
	};


	TrumpCard(Ranks Rank, Suits Suit);
	virtual ~TrumpCard();

	Ranks GetRank();
	Suits GetSuit();

	virtual int GetFaceValue();

	void print();

private:
	Ranks Rank;
	Suits Suit;
};