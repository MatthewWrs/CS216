/*
    Course: CS216
    Assignment: Project 2
    Purpose: See readme.txt
    Author: Matthew Wirasakti
    Section: 002
*/

#include <iostream>
#include <vector>
#include "pokerhand.h"
#include "deck.h"

using namespace std;

const int TOTALCARDS = 7;  // each player has a total of 7 cards
const int SHAREDHAND = 5; // there is a shared set of 5 cards
const int PERSONALHAND = 2; // each player gets 2 cards
const int HANDS = 5; // the number of cards in the best hand of the player and the computer

// decide the best five cards out of seven cards
// best means the highest ranking of five-card poker hand defined in the poker game
// pass in a vector of seven cards 
// (const call by reference: safe for the arugment and no copy is made for efficiency)
// return the best PokerHand object which represents the best five-card poker hand
PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards);

int main()
{
    // variable to store user input
    string choice = "a";

    // program continues to run unless user enters a "q" or a "Q"
    while(choice != "q" && choice != "Q") {
        // a deck of 52 cards is created and shuffled
        Deck playDeck;
        playDeck.createDeck();
        playDeck.shuffleDeck();

        // card arrays to store each players' cards
        Card playerhand[PERSONALHAND];
        Card comphand[PERSONALHAND];
        Card shared[SHAREDHAND];

        // stores the 7 cards that each player creates a best 5 out of 7
        vector<Card> P1, P2;

        // stores the best pokerhand for each player
        PokerHand player, comp;
        
        // deals 2 cards to the player and the computer
        // then deals 5 shared cards
        for (int i = 0; i < PERSONALHAND; i++) {    
            playerhand[i] = playDeck.deal_a_card();
            P1.push_back(playerhand[i]);
            comphand[i] = playDeck.deal_a_card();
            P2.push_back(comphand[i]);
        }
        for (int i = 0; i < SHAREDHAND; i++) {
            shared[i] = playDeck.deal_a_card();
            P1.push_back(shared[i]);
            P2.push_back(shared[i]);
        }

        // displays the two cards in each players' hand and the shared cards
        cout << "The cards in your hand are:\n\t";
        for (int i = 0; i < PERSONALHAND; i++) {
            playerhand[i].print();
            cout << "\n\t\t";
        }
        cout << endl;
        cout << "The FIVE cards on the deck to share are:\n";
        cout <<"    *************************\n";
        for (int i = 0; i < SHAREDHAND; i++) {
            cout << "    *\t";
            shared[i].print();
            cout << "\t*\n";
        }
        cout <<"    *************************\n";
        cout << endl;
        cout << "The cards in the computer's hand are:\n\t";
        for (int i = 0; i < PERSONALHAND; i++) {
            comphand[i].print();
            cout << "\n\t\t";
        }
        cout << endl;

        // finds the best 5 out of 7 hand for each player
        cout << "Player 1: You\n";
        player = best_FIVE_out_of_SEVEN(P1);

        cout << "Player 2: Computer\n";
        comp = best_FIVE_out_of_SEVEN(P2);

        // compares each players' hands to see who has the winning (best) hand
        if (player.compareHand(comp) < 0) {
            cout << "Sorry, the computer wins the game!\n";
        }
        else if (player.compareHand(comp) > 0) {
            cout << "Congratulations, you win the game!\n";
        }
        else {
            cout << "It is a tie game!\n";
        }
        
        // requests user input to know if the program should continue
        cout << "Do you want to play a poker game again? (Press ""q"" or ""Q"" to quit the program)" << endl;
        getline(cin, choice);
        //cin.ignore(256, '\n');
    }
    
    // if user inputs a "q" or a "Q" the program prints out a thank you then exits
    cout << "Thank you for using this program!" << endl;

    return 0;
}

PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards)
{    

    PokerHand bestH;
    PokerHand cardsH;

    // check if the parameter is valid
    if (cards.size() != TOTALCARDS)
    {
        cout << "Invalid Cards, we need SEVEN cards!" << endl;
        return cardsH; // return a PokerHand object by default constructor
    }

    // Consider all possible ways of dropping two cards
    // from all seven cards 
    // i is the index of the first card dropped
    // and j is the index of the second card dropped.
    // There are 21 different ways to pick 5 cards out of 7
    for (int i = 0; i < TOTALCARDS; i++) 
    {
        for (int j = i + 1; j < TOTALCARDS; j++) 
        {
            Card pick[HANDS];
            int index = 0;

            // Iterate over all seven cards and assign them to the pick[] array
            // exclude cards with index numbers of #i and #j.
            for (int k = 0 ; k < TOTALCARDS ; k++) 
            {
                if (k == i || k == j) 
                    continue;
                pick[index] = cards[k];
                index++;
            }
            
            // create a PokerHand with pick[]
            cardsH.setPokerHand(pick, HANDS);

            // Check to see if current pick is better than
            // the best you have seen so far
            if (bestH.compareHand(cardsH) < 0)
            {
                bestH = cardsH ;
            }
        }
    }

    // Now bestH holds the best poker hand among all 21 poker hands
    cout << "*** Best five-card hand ***" << endl;
    bestH.print();
    cout << endl << endl;
    return bestH;
}