/* File: SortedLinkedList.cpp
 * Course: CS216-00x
 * Project: Project 2
 * Purpose: the implementation of member functions for the Node class and SortedLinkedList class.
 * Author: Matthew Wirasakti
 * Section: 002
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#include <cstdlib>
#include <iostream>
#include "SortedLinkedList.h"

using namespace std;

// Implementation for the member functions of the Node class

Node::Node()
{
    next = NULL;
}

Node::Node(Card value)
{
    data = value;
    next = NULL;
}


// Implementation for the member functions of the SortedLinkedList class

//default constructor
SortedLinkedList::SortedLinkedList()
{
    head = NULL;
}

// insert a new node, which is a Card object to the list
// so that the nodes are in non-decreasing order of card values defined by poker game
// To maintain this order, the list needs to use insert() ONLY to add new node
void SortedLinkedList::insert(Card newcard)
{
    Node* newnode = new Node(newcard);
    Node* pre = NULL;
    Node* current = head;

    while (current!= NULL && newcard.compareTo(current->data) < 0) 
    {
        pre = current; 
        current = current->next;
    }
    if (current == head)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        pre->next = newnode;
        newnode->next = current;
    }
}

// remove the front node from the list
void SortedLinkedList::pop_front()
{
    if (size() == 0)
        cout << "Cannot remove from an empty list." << endl;
    else
    {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// return how many nodes in the list
int SortedLinkedList::size() const
{
    int count = 0;
    Node* current = head;
    while (current != NULL)
    {
        current = current->next;
        count++;
    }
    return count;
}

// return true if the list is empty
// otherwise return false
bool SortedLinkedList::isEmpty() const
{
    return (size()==0);
}
// return a vector of nodes 
// which stores the nodes from the sorted list.
// provide flexible way to access the nodes in the list
vector<Card> SortedLinkedList::access() const
{
    vector<Card> nodes_in_list;
    Node* current = head;
    while (current != NULL)
    {
        nodes_in_list.push_back(current->data);
        current = current->next;
    }
    return nodes_in_list;
}


// display the nodes in the list from the front to the tail
void SortedLinkedList::print() const
{
    vector<Card> nodes = access();
    for (int i = 0; i < nodes.size(); i++)
    {
        nodes[i].print();
        cout << "\t";
    }
    cout << endl;
}

//destructor
SortedLinkedList::~SortedLinkedList()
{
    while (!isEmpty())
        pop_front();
}
