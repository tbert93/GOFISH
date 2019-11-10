//
// Created by tonyb on 11/10/2019.
//

#ifndef GOFISH_DECK_H
#define GOFISH_DECK_H
#include "card.h"



class Deck {
    static const int SIZE = 52;

public:


    Deck();           // pristine, sorted deck

    void shuffle();   // shuffle the deck, all 52 cards present
    Card dealCard();   // get a card, after 52 are dealt, fail

    int  size() const; // # cards left in the deck

private:

    Card myCards[SIZE];
    int myIndex;  // current card to deal

};


#endif //GOFISH_DECK_H
