//
// Created by tonyb on 11/10/2019.
//

#include "player.h"
#include "card.h"
#include "deck.h"
#include <ctime>
#include <iterator>
#include <cstdlib>

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

    vector<Card>::const_iterator i;
    for(i = myHand.begin(); i < myHand.end(); i++){

        if(*i == c)
            return true;

    }

    return false;
}

Card Player::removeCardFromHand(Card c) {

    vector<Card>::iterator i;
    for(i = myHand.begin(); i < myHand.end(); i++){

        if(*i == c) {
            i = myHand.erase(i);
        }

    }
    return c;

}

string Player::showHand() const {

    string hand = " ";

    vector<Card>::const_iterator i;
    for(i = myHand.begin(); i < myHand.end(); i++){

        hand += (*i).toString();
        hand += " ";

    }

    return hand;

}

string Player::showBooks() const {

    string books = " ";

    vector<Card>::const_iterator i;
    for(i = myBook.begin(); i < myBook.end(); i++){

        books += (*i).toString();
        books += " ";

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

    vector<Card>::const_iterator i;
    for(i = myHand.begin(); i < myHand.end(); i++){

        if((*i).getRank() == c.getRank())
            return true;
    }

    return false;

}

bool Player::checkHandForPair(Card &c1, Card &c2) {

    for(vector<Card>::iterator i = myHand.begin(); i < myHand.end(); i++ ){

        for(vector<Card>::iterator j = (i + 1); j < myHand.end(); j++){

            if((*i).getRank() == (*j).getRank()){

                c1 = *i;
                c2 = *j;
                return true;

            }
        }
    }

    return false;
}

Card Player::findCard(Card c) const {

    vector<Card>::const_iterator i;
    for(i = myHand.begin(); i < myHand.end(); i++){

        if ((*i).getRank() == c.getRank())
            return *i;

    }

    return c;

}



//string Player::lastCard() {

    //return (*myHand.end()).toString();
//}

//string Player::lastBook() {

    //return(*myBook.end()).rankString((*myBook.end()).getRank());
//}

