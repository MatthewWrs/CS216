/* File: pokerhand.cpp
 * Course: CS216-00x
 * Project: Lab 10 (as part of Project 2)
 * Purpose: the implementation of member functions for the Pokerhand class.
 * Author: Matthew Wirasakti
 * Section: 002
 */
#include<iostream>
#include "pokerhand.h"

using namespace std;

// sets initial hand_rank at NoRank and 0 points
PokerHand::PokerHand()
{
    hand_rank.kind = Rank::hRanks::NoRank;
    hand_rank.point = 0;
}

// checks if there are 5 cards then determines the rank and point value of the 5 card hand
void PokerHand::setPokerHand(Card in_hand[], int size)
{
    if (size != HANDS) {
        cout << "Invalid number of cards!" << endl;
        return;
    }
    for (int i = 0; i < HANDS; i++) {
        cards[i] = in_hand[i];
    }
    sort();
    if (isStraightFlush() == true) {
        
    }
    else if (isFourOfAKind() == true) {
        
    }
    else if (isFullHouse() == true) {
        
    }
    else if (isFlush() == true) {
        
    }
    else if (isStraight() == true) {
        
    }
    else if (isThreeOfAKind() == true) {
        
    }
    else if (isPair() == true) {

    }
    else if (isHighCard() == true) {

    }
}

// compares two pokerhands to see which is better
int PokerHand::compareHand(const PokerHand &otherHand) const
{
    int value = 0;
    if (this->hand_rank.kind == Rank::hRanks::NoRank || otherHand.hand_rank.kind == Rank::hRanks::NoRank) {
        if (this->hand_rank.kind == Rank::hRanks::NoRank && otherHand.hand_rank.kind == Rank::hRanks::NoRank) {
            value = 0;
        }
        else if (this->hand_rank.kind == Rank::hRanks::NoRank) {
            value = -1;
        }
        else {
            value = 1;
        }
    }
    else {
        if (this->hand_rank.kind > otherHand.hand_rank.kind) {
            value = 1;
        }
        else if (this->hand_rank.kind < otherHand.hand_rank.kind) {
            value = -1;
        }
        else {
            if (this->hand_rank.point > otherHand.hand_rank.point) {
                value = 1;
            }
            else if (this->hand_rank.point < otherHand.hand_rank.point) {
                value = -1;
            }
            else {
                value = 0;
            }
        }
    }
    return value;
}

// prints out the pokerhand and the rank and point
void PokerHand::print() const
{
    for (int i = 0; i < HANDS; i++) {
        cards[i].print();
        cout << "\t";
    }
    cout << endl;
    cout << "Its ranks is: ";
    hand_rank.print();
    cout << endl;
}

// gets the pokerhand rank
Rank PokerHand::getRank() const
{
    return hand_rank;
}

// checks for a straight flush
// 5 cards are of sequential card value (points), and all of the same suit
bool PokerHand::isStraightFlush()
{
    if (isAllOneSuit() == true && isSequence() == true) {
        hand_rank.kind = Rank::hRanks::StraightFlush;
        hand_rank.point = cards[0].getPoint();
        return true;
    }
    else {
        return false;
    }
}

// checks for a four of a kind
// 4 cards are of the same card value and 1 card of another card value, suit has no impact
bool PokerHand::isFourOfAKind()
{
    Card initial = cards[0];
    int count = 0;
    for (int i = 1; i < HANDS; i++) {
        if (initial.getPoint() == cards[i].getPoint()) {
            count++;
        }
    }
    Card initial2 = cards[1];
    int count2 = 0;
    for (int j = 2; j < HANDS; j++) {
        if (initial2.getPoint() == cards[j].getPoint()) {
            count2++;
        }
    }
    if (count == 3 || count2 == 3) {
        hand_rank.kind = Rank::hRanks::FourOfAKind;
        hand_rank.point = cards[1].getPoint();
        return true;
    }
    else {
        return false;
    }
}

// checks for a full house
// (3 cards are of the same card value, and 2 cards are of another card value, suit has no impact
bool PokerHand::isFullHouse()
{
    int count = 0;
    if (cards[0].getPoint() == cards[1].getPoint()) {
        if (cards[1].getPoint() == cards[2].getPoint()) {
            if (cards[3].getPoint() == cards[4].getPoint()) {
                count++;
            }
        }
        else if (cards[2].getPoint() == cards[3].getPoint() && cards[2].getPoint() == cards[4].getPoint()) {
            count++;
        }
    }
    if (count == 1) {
        hand_rank.kind = Rank::hRanks::FullHouse;
        hand_rank.point = cards[2].getPoint();
        return true;
    }
    else {
        return false;
    }
}

// checks for a flush
// 5 cards are of the same suit, not all of the sequential card value
bool PokerHand::isFlush()
{
    if (isAllOneSuit() == true && isSequence() == false) {
        hand_rank.kind = Rank::hRanks::Flush;
        hand_rank.point = cards[0].getPoint();
        return true;
    }
    else {
        return false;
    }
}

// checks for a straight
// 5 cards are of sequential card value, not all of the same suit
bool PokerHand::isStraight()
{
    if (isAllOneSuit() == false && isSequence() == true) {
        hand_rank.kind = Rank::hRanks::Straight;
        hand_rank.point = cards[0].getPoint();
        return true;
    }
    else {
        return false;
    }
}

// checks for a three of a kind
// 3 cards are of the same card value, and 2 cards are of two other card points, suit has no impact
bool PokerHand::isThreeOfAKind()
{
    Card initial = cards[0];
    int count = 0;
    for (int i = 1; i < HANDS; i++) {
        if (initial.getPoint() == cards[i].getPoint()) {
            count++;
        }
    }
    Card initial2 = cards[1];
    int count2 = 0;
    for (int j = 2; j < HANDS; j++) {
        if (initial2.getPoint() == cards[j].getPoint()) {
            count2++;
        }
    }
    Card initial3 = cards[2];
    int count3 = 0;
    for (int k = 3; k < HANDS; k++) {
        if (initial2.getPoint() == cards[k].getPoint()) {
            count3++;
        }
    }
    if (count == 2 || count2 == 2 || count3 == 2) {
        hand_rank.kind = Rank::hRanks::ThreeOfAKind;
        hand_rank.point = cards[2].getPoint();
        return true;
    }
    else {
        return false;
    }
}

// checks for a pair
// any 2 cards are of the same card value, suit has no impact
bool PokerHand::isPair()
{
    Card high;
    Card initial = cards[0];
    int count = 0;
    for (int i = 1; i < HANDS; i++) {
        if (initial.getPoint() == cards[i].getPoint()) {
            count++;
        }
    }
    if (count == 1) {
        if (initial.getPoint() > high.getPoint()) {
            high = initial;
        }
    }
    Card initial2 = cards[1];
    int count2 = 0;
    for (int j = 2; j < HANDS; j++) {
        if (initial2.getPoint() == cards[j].getPoint()) {
            count2++;
        }
    }
    if (count2 == 1) {
        if (initial2.getPoint() > high.getPoint()) {
            high = initial2;
        }
    }
    Card initial3 = cards[2];
    int count3 = 0;
    for (int k = 3; k < HANDS; k++) {
        if (initial2.getPoint() == cards[k].getPoint()) {
            count3++;
        }
    }
    if (count3 == 1) {
        if (initial3.getPoint() > high.getPoint()) {
            high = initial3;
        }
    }
    Card initial4 = cards[3];
    int count4 = 0;
    for (int m = 3; m < HANDS; m++) {
        if (initial3.getPoint() == cards[m].getPoint()) {
            count4++;
        }
    }
    if (count4 == 1) {
        if (initial4.getPoint() > high.getPoint()) {
            high = initial4;
        }
    }
    if (count == 1 || count2 == 1 || count3 == 1 || count4 == 1) {
        hand_rank.kind = Rank::hRanks::Pair;
        hand_rank.point = high.getPoint();
        return true;
    }
    else {
        return false;
    }
}

// checks for a high card
// if no other suit then the hand is a high card
bool PokerHand::isHighCard()
{
    if (isStraightFlush() == false && isFourOfAKind() == false && isFullHouse() == false && isFlush() == false && isStraight() == false && isThreeOfAKind() == false && isPair() == false) {
        hand_rank.kind = Rank::hRanks::HighCard;
        hand_rank.point = cards[0].getPoint();
        return true;
    }
    else {
        return false;
    }
}

// sorts the hand in decreasing point value order
void PokerHand::sort()
{
    Card temp;
    for (int i = 0; i < HANDS; i++) {
        for (int j = i + 1; j < HANDS; j++) {
            if (cards[i].getPoint() < cards[j].getPoint()) {
                temp = cards[i];
                cards[i] = cards[j];
                cards[j] = temp;
            }
        }
    }
}

// checks to see if all the cards in a hand are of the same suit
bool PokerHand::isAllOneSuit() const
{
    int count = 0;
    int i = 0;
    for (int j = i + 1; j < HANDS; j++) {
        if (cards[i].getSuit() == cards[j].getSuit()) {
            count++;
        }
    }
    if (count == 4) {
        return true;
    }
    else {
        return false;
    }
}

// checks to see if the cards in a hand decrease by 1 in decreasing order
bool PokerHand::isSequence() const
{
    int count = 0;
    int i = 0;
    if (cards[i].getPoint() - 1 == cards[i + 1].getPoint()) {
        i++;
        if (cards[i].getPoint() - 1 == cards[i + 1].getPoint()) {
            i++;
            if (cards[i].getPoint() - 1 == cards[i + 1].getPoint()) {
                i++;
                if (cards[i].getPoint() - 1 == cards[i + 1].getPoint()) {
                    count++;
                }
            }
        }
    }
    if (count == 1) {
        return true;
    }
    else {
        return false;
    }
}