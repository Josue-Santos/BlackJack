#pragma once
enum class Suit : char {
	Spades = 'S',
	Diamonds = 'D',
	Clubs = 'C',
	Heart = 'H'
};
enum class Rank {
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8,
	nine = 9,
	T = 10,
	Jack = 10,
	Queen = 10,
	King = 10,
	Ace = 11
};
struct Card {
	Suit suit;
	Rank rank;
};
bool readSuit(std::istream& in, Suit& suit);
bool readRank(std::istream& in, Rank& rank);
bool readCard(std::istream& in, Card& card);
int blackjack_score(std::vector<Card>);
