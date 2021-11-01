#include<iostream>
#include<vector>
#include"Card.hpp"
using namespace std;



int main() {

	Card card;
	vector<Card> hand;
	int counter = 0;
	while (cin && readCard) {
		if (readCard(cin, card)) {
			hand.push_back(card);

		}
	}
	blackjack_score(hand);

}

	
	