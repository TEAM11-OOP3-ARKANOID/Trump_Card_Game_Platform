#include "Card.h"
#include <iostream>
#include <string>

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

std::string TrumpCard::printString() {
    std::string cardString;
    if (Suit == joker) {
        return "joker";
    } 
    if (Rank <= ten) {
        cardString = std::to_string(Rank);
    }
    else if (Rank == jack) {
        cardString = "J";
    }
    else if (Rank == queen) {
        cardString = "Q";
    }
    else if (Rank == king) {
        cardString = "K";
    }
    if (Suit == heart) {
        cardString = cardString + "\u2661";
    }
    else if (Suit == club) {
        cardString = cardString + "\u2667";
    }
    else if (Suit == spade) {
        cardString = cardString + "\u2664";
    }
    else if (Suit == diamond) {
        cardString = cardString + "\u25C7";
    }
    return cardString;
}
void TrumpCard::print_winform(System::Windows::Forms::TextBox^ textBox1)
{
    if (Rank <= ten && Suit != joker)
        textBox1->AppendText(System::Convert::ToString(Rank));
    else if (Rank == jack && Suit != joker)
        textBox1->AppendText("J");
    else if (Rank == queen && Suit != joker)
        textBox1->AppendText("Q");
    else if (Rank == king && Suit != joker)
        textBox1->AppendText("K");
    else if (Rank == ace && Suit != joker)
        textBox1->AppendText("A");

    switch (Suit)
    {
    case heart:
        textBox1->AppendText("\u2661");
        break;
    case diamond:
        textBox1->AppendText("\u25C7");
        break;
    case club:
        textBox1->AppendText("\u2667");
        break;
    case spade:
        textBox1->AppendText("\u2664");
        break;
    case joker:
        textBox1->AppendText("Joker");
        break;
    }
}
