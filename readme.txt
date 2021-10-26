Readme File
---------------
Course: CS216
Instructor: Dr. Pike
Assignment: Project 2
Author: Matthew Wirasakti
Section : 002

Purpose of Project:
    Write a program that plays a simplified poker game, named Texas Hold’em, against the computer:
    Two cards, known as the hole cards, are dealt face down to the user 
    and the computer respectively, and then five community cards 
    (also called “shared cards” or “window cards”) are dealt face up in the 
    center of the table and shared by both players. Each player then combines 
    the hole cards with the community cards (2 cards + 5 cards) to seek the
    best five-card poker hand from any combination of the SEVEN cards. The program
    then compares the highest ranking of the five-card poker hands between the user
    and the computer, then report the one, who has higher ranking of the five-card poker
    hand, wins the game, or otherwise report a tie game.
    
    The program continually asks the user if the user wants to play 
    another the game until the user enters a "q" or a "Q". If th user
    enters any other input, the program displays another poker game
    and then determines the winner of that game.

Purpose of card.cpp & card.h
    These two files generate the report for when the user chooses the
    quit option from the menu.

Purpose of deck.cpp & deck.h
    These two files generate a deck of cards and provide functions to
    create and shuffle a deck and to deal a card from the deck.

Purpose of rank.cpp & rank.h
    These two files create the definitions and a print function for the
    hand-ranking categories of poker.

Purpose of pokerhand.cpp & pokerhand.h
    These two files create the definition of a pokerhand, allowing the
    program to set and compare a poker hand and allows for the program
    to determine what is the hand-ranking and point values of the hand.

Purpose of SortedLinkedList.cpp & SortedLinkedList.h
    These two files create a linked list that can easily be sorted and
    allows for cards to be in decreasing order and picked out easily.

How to Compile the Program:
    make

How to Run the Program:
    ./Project2