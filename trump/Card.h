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
		ace,
		jokerrank
	};

	bool operator == (const TrumpCard& cd) {
		
		return (cd.Rank == Rank);

	}

	TrumpCard(Ranks Rank, Suits Suit);
	virtual ~TrumpCard();

	Ranks GetRank();
	Suits GetSuit();

	virtual int GetFaceValue();

	void print();
	void TrumpCard::print_winform(System::Windows::Forms::TextBox^ textBox1);

private:
	Ranks Rank;
	Suits Suit;
};