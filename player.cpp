//
// Created by tonyb on 11/10/2019.
//

#include "player.h"
#include "card.h"
#include "deck.h"
#include <ctime>

using namespace std;

void Player::addCard(Card c) {

    myHand.push_back(c);

}

void Player::bookCards(Card c1, Card c2) {

    myBook.push_back(c1);
    myBook.push_back(c2);

}

Card Player::chooseCardFromHand() const {

    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);

    int randomNum = rand() % myHand.size();

    return myHand[randomNum];

}

bool Player::cardInHand(Card c) const {

    for(Card temp : myHand){

        if(temp == c)
            return true;

    }

    return false;

}

Card Player::removeCardFromHand(Card c) {

    for(vector<Card>::iterator i = myHand.end(); i != myHand.begin(); i--){

        if(*i == c) {
            i = myHand.erase(i);
        }

    }
    return c;

}

string Player::showHand() const {

    string hand = " ";

    for(Card temp : myHand){

        hand += temp.toString();
        hand += ", ";

    }

    return hand;

}

string Player::showBooks() const {

    string books = " ";

    for(Card temp : myBook){

        books += temp.toString();
        books += ", ";

    }

    return books;

}

int Player::getBookSize() const {

    return myBook.size();

}

int Player::getHandSize() const {

    return myHand.size();

}

bool Player::sameRankInHand(Card c) const {

    for(Card temp : myHand){

        if(temp.getRank() == c.getRank())
            return true;
    }

    return false;

}

bool Player::checkHandForPair(Card &c1, Card &c2) {

    for(vector<Card>::iterator i = myHand.end(); i != myHand.begin(); i-- ){

        for(vector<Card>::iterator j = i - 1 ; j != myHand.begin(); j--){

            if(*i == *j){

                c1 = *i;
                c2 = *j;
                return true;

            }
        }
    }

    return false;
}

