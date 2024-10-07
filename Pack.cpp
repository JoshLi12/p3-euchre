#include <cassert>
#include <iostream>
#include "Pack.hpp"
#include "Card.hpp"


using namespace std;

Pack::Pack() {
    int index = 0;
    next = 0;
    for (int i=SPADES; i<= DIAMONDS; i++) {
        for (int j=NINE; j <= ACE; j++) {
            cards[index] = Card(static_cast<Rank>(j), static_cast<Suit>(i));
            index++;
        }
    }
}

Pack::Pack(std::istream& pack_input) {
    Card c;
    next = 0;
    for (int i=0; i<24; i++) {
        pack_input >> c;
        cards[i] = c;
    }
}

Card Pack::deal_one() {
    int n = next;
    if (next < 24) {
        next += 1; 
    }
    return cards[n];
}

void Pack::reset() {
    next = 0;
}

void Pack::shuffle() {
    for (int n=0; n<7; n++) {
        std::array<Card, PACK_SIZE> cards_copy;
        for (int i=0; i<PACK_SIZE/2; i++) {
            cards_copy[2*i+1] = cards[i];
            cards_copy[2*i] = cards[PACK_SIZE/2 + i];
        }
        cards = cards_copy;
    }
    
    next = 0;
}

bool Pack::empty() const {
    if (next == 24) {
        return true;
    }
    return false;
}

