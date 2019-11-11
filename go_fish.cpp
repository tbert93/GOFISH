#include <iostream>
#include <cstdlib>
#include <fstream>
#include "card.h"
#include "deck.h"
#include "player.h"



int main() {

    ofstream log;
    log.open("gofish_results.txt");

    log<<"Two-player Go Fish"<<endl<<endl;

    const int numCards = 7;
    Card c1,c2,temp,current;
    int player = 2;
    bool playerOneTurn = true;  //PlayerOne goes first
    bool playerTwoTurn = false;

    Player p1("Tony");
    Player p2("Tatiana");

    Deck d;
    d.shuffle();

    for (int i = 0; i < numCards ; ++i) {       //dealing Cards,7 each

        p1.addCard(d.dealCard());
        p2.addCard(d.dealCard());
    }

    log<<"7 cards are dealt to each player."<<endl<<endl;

    log<<"player 1, "<<p1.getName()<<"'s initial hand:"<<endl;
    log<<p1.showHand()<<endl;
    log<<"Player 2, "<<p2.getName()<<"'s initial hand:"<<endl;
    log<<p2.showHand()<<endl<<endl;

    while(p1.checkHandForPair(c1,c2)){      //books the pair and removes from hand

        p1.bookCards(c1, c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
        log << p1.getName() << " books the " << c1.rankString(c1.getRank()) << "." << endl;

    }

    log<<endl;

    while(p2.checkHandForPair(c1, c2)){

        p2.bookCards(c1, c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
        log << p2.getName() << " books the " << c1.rankString(c1.getRank()) << "." << endl;

    }

    log<<endl;

    cout<<"Player 1 Books:"<<endl;
    log<<p1.getName()<<"'s Books:"<<endl;
    cout<<p1.showBooks()<<endl;
    log<<p1.showBooks()<<endl;
    cout<<"Player 1 Hand:"<<endl;
    cout<<p1.showHand()<<endl;

    cout<<"Player 2 Books:"<<endl;
    log<<p2.getName()<<"'s Books:"<<endl;
    cout<<p2.showBooks()<<endl;
    log<<p2.showBooks()<<endl<<endl;
    cout<<"Player 2 Hand:"<<endl;
    cout<<p2.showHand()<<endl;

    while((p1.getBookSize() + p2.getBookSize()) != 52){     //continues until sum of booked cards is equal to 52
                                                            //player turn switches when there is a Go Fish
        if(playerOneTurn) {

            log << p1.getName() << "'s turn." << endl;
            log << "Hand at start of turn: " << p1.showHand() << endl;

            if (p1.getHandSize() == 0 && d.size() > 0) {

                log << p1.getName() << " has no cards left." << endl;
                p1.addCard(current = d.dealCard());
                log << p1.getName() << " draws " << current.toString() << "." << endl;
            }

            temp = p1.chooseCardFromHand();
            log << p1.getName() << " asks- Do you have a " << temp.rankString(temp.getRank()) << "?" << endl;

            if (p2.sameRankInHand(temp)) {      //checks if opposing player has the same rank that was chosen

                playerOneTurn = true;
                log << p2.getName() << " says- Yes I have a " << temp.rankString(temp.getRank()) << "." << endl;
                p1.addCard(p2.findCard(temp));
                p2.removeCardFromHand(p2.findCard(temp));
                if(p2.getHandSize() == 0 && d.size() > 0){      //checks instance that opposing player has run out of cards

                    log << p2.getName() << " has no cards left." <<endl;
                    p2.addCard(current = d.dealCard());
                    log << p2.getName() << " draws " << current.toString() << "." << endl;
                }

            } else {        //card is dealt when there is a Go Fish

                playerOneTurn = false;
                log << p2.getName() << " says- Go Fish!" << endl;
                p1.addCard(current = d.dealCard());
                log << p1.getName() << " draws " << current.toString() << "." << endl;
            }

            while (p1.checkHandForPair(c1, c2)) {   //checks if the card received during turn is a pair

                p1.bookCards(c1, c2);
                p1.removeCardFromHand(c1);
                p1.removeCardFromHand(c2);
                log << p1.getName() << " books the " << c1.rankString(c1.getRank()) << "." << endl;
            }

            if (p1.getHandSize() == 0 && d.size() > 0) {
                log << p1.getName() << " has no cards left." << endl;
                p1.addCard(current = d.dealCard());
                log << p1.getName() << " draws " << current.toString() << "." << endl;
            }

            log << "Hand at end of Turn: " << p1.showHand() << endl << endl;

        }else{  //p2's turn

            log << p2.getName() << "'s turn." << endl;
            log<<"Hand at start of turn: "<<p2.showHand()<<endl;

            if(p2.getHandSize() == 0 && d.size() > 0) {

                log << p2.getName() << " has no cards left." << endl;
                p2.addCard(current = d.dealCard());
                log << p2.getName() << " draws " << current.toString() <<"."<< endl;
            }

            temp = p2.chooseCardFromHand();
            log<< p2.getName() << " asks- Do you have a "<<temp.rankString(temp.getRank())<<"?"<<endl;

            if(p1.sameRankInHand(temp)){

                playerOneTurn = false;
                log << p1.getName() << " says- Yes I have a " << temp.rankString(temp.getRank()) << "." << endl;
                p2.addCard(p1.findCard(temp));
                p1.removeCardFromHand(p1.findCard(temp));
                if (p1.getHandSize() == 0 && d.size() > 0) {

                    log << p1.getName() << " has no cards left." << endl;
                    p1.addCard(current = d.dealCard());
                    log << p1.getName() << " draws " << current.toString() << "." << endl;
                }

            }else{

                playerOneTurn = true;
                log << p1.getName() << " says- Go Fish!" << endl;
                p2.addCard(current = d.dealCard());
                log << p2.getName() << " draws " << current.toString() << "." << endl;

            }

            while(p2.checkHandForPair(c1, c2)){

                p2.bookCards(c1, c2);
                p2.removeCardFromHand(c1);
                p2.removeCardFromHand(c2);
                log << p2.getName() << " books the " << c1.rankString(c1.getRank()) << "." << endl;

            }

            if(p2.getHandSize() == 0 && d.size() > 0) {

                log << p2.getName() << " has no cards left." << endl;
                p2.addCard(current = d.dealCard());
                log << p2.getName() << " draws " << current.toString() <<"."<< endl;
            }

            log<<"Hand at end of turn: "<<p2.showHand()<<endl<<endl;
        }
    }

    cout<<"Player 1 Books:"<<endl;
    log<<p1.getName()<<"'s Books:"<<endl;
    cout<<p1.showBooks()<<endl;
    log<<p1.showBooks()<<endl;
    cout<<"Player 1 Hand:"<<endl;
    cout<<p1.showHand()<<endl;

    cout<<"Player 2 Books:"<<endl;
    log<<p2.getName()<<"'s Books:"<<endl;
    cout<<p2.showBooks()<<endl;
    log<<p2.showBooks()<<endl<<endl;
    cout<<"Player 2 Hand:"<<endl;
    cout<<p2.showHand()<<endl;

    if(p1.getBookSize() > p2.getBookSize()) {
        cout << "Player One wins with " << p1.getBookSize() / 2 << " books!!!" << endl;
        log << p1.getName() << " wins with " << p1.getBookSize() / 2 << " books!!!" << endl;
    }

    if(p2.getBookSize() > p1.getBookSize()) {
        cout << "Player Two wins with " << p2.getBookSize() / 2 << " books!!!" << endl;
        log << p2.getName() << " wins with " << p2.getBookSize() / 2 << " books!!!" << endl;
    }

    if(p1.getBookSize() == p2.getBookSize()) {
        cout << "TIE!!!" << endl;
        log << "TIE!!!" << endl;
    }

    log.close();

  }