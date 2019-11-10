//
// Created by tonyb on 11/10/2019.
//

#include "card.h"
#include <string>


using namespace std;

Card::Card() {

    myRank = 1;
    mySuit = spades;

}

Card::Card(int rank, Card::Suit s) {

    myRank = rank;
    mySuit = s;

}

string Card::rankString(int r) const {

    string rankArr[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

    return rankArr[r-1];

}

string Card::suitString(Card::Suit s) const {

    if(s == spades)
        return "s";
    if(s == hearts)
        return "h";
    if(s == diamonds)
        return "d";
    if(s == clubs)
        return "c";

    return " ";     //will never occur since card will be valid always


}

int Card::getRank() const {

    return myRank;

}

bool Card::sameSuitAs(const Card &c) const {

    return c.mySuit == mySuit;
}

string Card::toString() const {

    return(rankString(myRank) + suitString(mySuit));

}

bool Card::operator==(const Card &rhs) const {

    return(myRank == rhs.myRank && this->sameSuitAs(rhs));

}

bool Card::operator!=(const Card &rhs) const {

    return(*this != rhs);

}

ostream& operator << (ostream& out, const Card& c){

    out << c.toString();
    return out;


}
