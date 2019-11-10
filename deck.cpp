//
// Created by tonyb on 11/10/2019.
//

#include "deck.h"
#include "card.h"
#include <ctime>

using namespace std;

Deck::Deck() {

    myIndex = 0;

    for (int i = 0; i < 13 ; ++i) {

        myCards[i] = *new Card(i + 1, Card::spades);
        myCards[i + 13] = *new Card(i+1, Card::hearts);
        myCards[i + 26] = *new Card(i+1, Card::diamonds);
        myCards[i + 39] = *new Card(i+1, Card::clubs);


    }

}

void Deck::shuffle() {

    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);

    for (int i = 0; i < 10 * SIZE; ++i) {

        int randomCard1 = rand() % (SIZE - 1);
        int randomCard2 = rand() % (SIZE - 1);

        Card temp = myCards[randomCard1];
        myCards[randomCard1] = myCards[randomCard2];
        myCards[randomCard2] = temp;

    }
}

Card Deck::dealCard() {

    return (myCards[myIndex]);
}

int Deck::size() const {

    return (SIZE - myIndex);
}

