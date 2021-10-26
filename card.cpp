/* File: card.cpp
 * Course: CS216-00x
 * Project: Lab 8 (as part of Project 2)
 * Purpose: the implementation of member functions for the Card class.
 * Author: Matthew Wirasakti
 * Section: 002
 */
#include "card.h"

// Default constructor marks card as invalid
Card::Card() {
    suit = cSuits::Invalid;
    point = 0;
}

// Alternate constructor
Card::Card(cSuits s, cPoints p) 
{
    suit = s;
    point = p;
}

// access the card point value
Card::cPoints Card::getPoint() const
{
    return point;
}

// access the card suit value
Card::cSuits Card::getSuit() const
{
    return suit;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has higher point than other, return 1;
// if the object your are working on has lower point than other, return -1;
// otherwise, return 0
int Card::compareTo(Card other) const
{
    int value = 0;

    if (this->point < other.point) {
        value = -1;
    }
    else if (this->point > other.point) {
        value = 1;
    }
    else {
        value = 0;
    }
    return value;
}

// Display a description of the Card object to standard output
// The output should look like:
//   the sign of suit, followed by the point, then followed by the sign of suit again   
void Card::print() const
{
    char pnt = '0';

    switch (point)
    {
        case 14:
            pnt = 'A';
        break;

        case 13:
            pnt = 'K';
        break;

        case 12:
            pnt = 'Q';
        break;

        case 11:
            pnt = 'J';
        break;

        default:
            pnt = '0';
        break;
    }

    switch (suit)
    {
        case cSuits::Spade:
            if (point > 10) {
                cout << SPADE << setw(2) << right << pnt << SPADE;
            }
            else {
                cout << SPADE << setw(2) << right << point << SPADE;
            }
        break;

        case cSuits::Club:
            if (point > 10) {
                cout << CLUB << setw(2) << right << pnt << CLUB;
            }
            else {
                cout << CLUB << setw(2) << right << point << CLUB;
            }
        break;

        case cSuits::Heart:
            if (point > 10) {
                cout << HEART << setw(2) << right << pnt << HEART;
            }
            else {
                cout << HEART << setw(2) << right << point << HEART;
            }
        break;

        case cSuits::Diamond:
            if (point > 10) {
                cout << DIAMOND << setw(2) << right << pnt << DIAMOND;
            }
            else {
                cout << DIAMOND << setw(2) << right << point << DIAMOND;
            }
        break;

        default:
            cout << "Invalid";
        break;
    }
}
