//Josue Santos
#include<iostream>
#include<vector>
#include"Card.hpp"
using namespace std;



bool readSuit(std::istream& in, Suit& suit) {
	bool success = false;
	char c;
	while (in >> c) {
		if (c == 's' || c =='S') {
			suit = Suit::Spades;
			success = true;
		}
		if (c == 'd' || c =='D') {
			suit = Suit::Diamonds;
			success = true;
		}
		if (c == 'c' || c == 'C') {
			suit = Suit::Clubs;
			success = true;
		}
		if (c == 'h' || c == 'H') {
			suit = Suit::Heart;
			success = true;
		}
		if (success == true) {
			return true;
		}
		if(success ==false){
			in.putback(c);
			in.setstate(std::ios_base::failbit);
			return false;
		}
	
	}
	

}
bool readRank(std::istream& in, Rank& rank) {
	bool success = false;
	char c;
	while (in >> c) {

		if (c == '2') {
			rank = Rank::two;
			success = true;
		}
		if (c == '3') {
			rank = Rank::three;
			success = true;
		}
		if (c == '4') {
			rank = Rank::four;
			success = true;
		}
		if (c == '5') {
			rank = Rank::five;
			success = true;
		}
		if (c == '6') {
			rank = Rank::six;
			success = true;
		}
		if (c == '7') {
			rank = Rank::seven;
			success = true;
		}
		if (c == '8') {
			rank = Rank::eight;
			success = true;
		}
		if (c == '9') {
			rank = Rank::nine;
			success = true;
		}
		if (c == 'A' || c =='a') {
			rank = Rank::Ace;
			success = true;
		}
		if (c == 'T' || c=='t') {
			rank = Rank::T;
			success = true;
		}
		if (c == 'J'|| c=='j') {
			rank = Rank::Jack;
			success = true;
		}
		if (c == 'Q' || c =='q') {
			rank = Rank::Queen;
			success = true;
		}
		if (c == 'K' || c=='k') {
			rank = Rank::King;
			success = true;
		}

		if (success==true){
			return true;
			}
		else {
			in.putback(c);
			in.setstate(std::ios_base::failbit);
			return false;
		}

	}
	

}
bool readCard(std::istream& in, Card& card) {
	Suit suit;
	Rank rank;
	bool success = false;
	if (readRank(cin, rank)) {
		card.rank = rank;
		success = true;
	}
	if (readSuit(cin, suit)) {
		card.suit = suit;
		success = true;
		
	}
	if (success == true) {
		return success;
	}
	if (success == false) {
		return false;
	}
	
}
int blackjack_score(vector<Card> hand) {
	
	int a=0;
	int b=0;
	int numAces = 0;
	bool success = false;
	int counter = 0;
	for (int i = 0; i < hand.size(); i++) {

		if (hand[i].suit == Suit::Spades || char(hand[i].suit) == 's' ||
			hand[i].suit == Suit::Diamonds || char(hand[i].suit) == 'd' ||
			hand[i].suit == Suit::Clubs || char(hand[i].suit) == 'c' ||
			hand[i].suit == Suit::Heart || char(hand[i].suit) == 'h') {
			
			if (hand[i].rank == Rank::Ace && int(hand[i].rank) + counter < 21) {
				counter += int(hand[i].rank);
				numAces++;
			}
			else if (hand[i].rank == Rank::Ace && int(hand[i].rank) + counter > 21) {
				counter += 1;
			}
			else if (hand[i].rank != Rank::Ace) {
				counter += int(hand[i].rank);
			}
			if (counter > 21 && numAces > 0) {
				counter -= 10;
				numAces--;
			}
			success = true;
		}
		
	}
	cout << counter << endl;
	return success;
}