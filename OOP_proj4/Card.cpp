#include "Card.h"
#include <iostream>

TrumpCard::TrumpCard(Ranks Rank, Suits Suit)
    : Rank(Rank),
      Suit(Suit)
{
}

TrumpCard::~TrumpCard()
{
}

TrumpCard::Ranks TrumpCard::GetRank()
{
    return Rank;
}

TrumpCard::Suits TrumpCard::GetSuit()
{
    return Suit;
}

int TrumpCard::GetFaceValue() // 해당 카드의 값
{
    if (Rank <= ten)
        return static_cast<int>(Rank);
    if (Rank <= king)
        return 10;
    return 11;
}

void TrumpCard::print() // 해당 카드를 출력
{
    if (Rank <= ten && Suit != joker)
        std::cout << Rank;
    else if (Rank == jack && Suit != joker)
        std::cout << "J";
    else if (Rank == queen && Suit != joker)
        std::cout << "Q";
    else if (Rank == king && Suit != joker)
        std::cout << "K";
    else if (Rank == ace && Suit != joker)
        std::cout << "A";

    switch (Suit)
    {
        case heart:
            std::cout << "\u2661";
            break;
        case diamond:
            std::cout << "\u25C7";
            break;
        case club:
            std::cout << "\u2667";
            break;
        case spade:
            std::cout << "\u2664";
            break;
        case joker:
            std::cout << "Joker";
            break;
    }
}
