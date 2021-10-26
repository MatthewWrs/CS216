/* File: deck.cpp
 * Course: CS216-00x
 * Project: Lab 8 (as part of Project 2)
 * Purpose: the implementation of member functions for the Deck class.
 * Author: Matthew Wirasakti
 * Section: 002
 */
#include "deck.h"

// creates a 52 card deck
void Deck::createDeck() {
    deck.clear();
    for (int s= (int)Card::cSuits::Spade; s < (int)Card::cSuits::Spade+SUITS; s++)
    {    
        for (Card::cPoints val = CARD_START; val < CARD_START+POINTS; val++)
        {
            Card::cSuits suit = static_cast<Card::cSuits>(s);
            Card newcard(suit, val);
            deck.push_back(newcard);
        }
    }
}

// shuffles a deck of cards
void Deck::shuffleDeck() {
    srand(time(0));
    Card temp;
    for (int i = deck.size()-1; i>= 1; i--)
    {
        int j = rand() % (i+1);
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

// deals a card from the deck
Card Deck::deal_a_card() {
    Card c;
    if (deck.size() == 0) {
        cout << "The deck is empty" << endl;
        return Card(Card::cSuits::Invalid,0);
    }
    else {
        c = deck.back();
        deck.pop_back();
        return c;
    }

    
}