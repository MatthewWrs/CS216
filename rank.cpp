/* File: rank.cpp
 * Course: CS216-00x
 * Project: Lab 9 (as part of Project 2)
 * Purpose: the implementation of member functions for the Rank class.
 * Author: Matthew Wirasakti
 * Section: 002
 */
#include <iostream>
#include "rank.h"

using namespace std;

// Default constructor.
Rank::Rank()
{
    kind = hRanks::NoRank;
    point = 0;
}

// Alternate constructor.
// Create a Rank object with specified ranking name and points.
Rank::Rank(hRanks r, rPoints p)
{
    kind = r;
    point = p;
}

// access the hand ranking kind
Rank::hRanks Rank::getKind() const
{
    return kind;
}

// access the card point value of the corresponding ranking kind
Rank::rPoints Rank::getPoint() const
{
    return point;
}

// Display a description of the hand-ranking category to standard output.
// The output should look like:
//   FourOfAKind( 4)
//   FullHouse(10)
//   Flush( A)
//   ...
void Rank::print() const
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
    
    switch (kind)
    {
        case hRanks::StraightFlush:
            if (point > 10) {
                cout << "StraightFlush (" << setw(2) << right << pnt << ")" << endl;
            }
            else {
                cout << "StraightFlush (" << setw(2) << right << point << ")" << endl;
            }
        break;

        case hRanks::FourOfAKind:
            if (point > 10) {
                cout << "FourOfAKind (" << setw(2) << right << pnt << ")" << endl;
            }
            else {
                cout << "FourOfAKind (" << setw(2) << right << point << ")" << endl;
            }
        break;

        case hRanks::FullHouse:
            if (point > 10) {
                cout << "FullHouse (" << setw(2) << right << pnt << ")" << endl;
            }
            else {
                cout << "FullHouse (" << setw(2) << right << point << ")" << endl;
            }
        break;

        case hRanks::Flush:
            if (point > 10) {
                cout << "Flush (" << setw(2) << right << pnt << ")" << endl;
            }
            else {
                cout << "Flush (" << setw(2) << right << point << ")" << endl;
            }
        break;

        case hRanks::Straight:
            if (point > 10) {
                cout << "Straight (" << setw(2) << right << pnt << ")" << endl;
            }
            else {
                cout << "Straight (" << setw(2) << right << point << ")" << endl;
            }
        break;

        case hRanks::ThreeOfAKind:
            if (point > 10) {
                cout << "ThreeOfAKind (" << setw(2) << right << pnt << ")" << endl;
            }
            else {
                cout << "ThreeOfAKind (" << setw(2) << right << point << ")" << endl;
            }
        break;

        case hRanks::Pair:
            if (point > 10) {
                cout << "Pair (" << setw(2) << right << pnt << ")" << endl;
            }
            else {
                cout << "Pair (" << setw(2) << right << point << ")" << endl;
            }
        break;

        case hRanks::HighCard:
            if (point > 10) {
                cout << "HighCard (" << setw(2) << right << pnt << ")" << endl;
            }
            else {
                cout << "HighCard (" << setw(2) << right << point << ")" << endl;
            }
        break;

        default: 
            cout << "NoRank" << endl;
        break;
    }
}

