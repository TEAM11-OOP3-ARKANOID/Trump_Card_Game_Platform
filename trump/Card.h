#include <string>;

#pragma once
class TrumpCard {
public:
	enum Suits { // 각 카드의 문양, 아스키 코드에 따라 하트 = 3....
		heart = 3,
		diamond,
		club,
		spade,
		joker
	};


	enum Ranks { // 각 카드의 내용, Ace의 경우에는 특수 값을 갖는 경우가 생김
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
		ace,
		jokerrank
	};

	bool operator == (const TrumpCard& cd) {
		
		return (cd.Rank == Rank);

	}

	TrumpCard(Ranks Rank, Suits Suit);
	virtual ~TrumpCard();

	std::string printString();

	Ranks GetRank();
	Suits GetSuit();

	virtual int GetFaceValue();

	void print();
	void TrumpCard::print_winform(System::Windows::Forms::TextBox^ textBox1);

private:
	Ranks Rank;
	Suits Suit;
};