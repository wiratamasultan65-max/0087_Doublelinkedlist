#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int noMhs;
    Node *Next;
    Node *Prev;
};

class DoubleLinkedList {
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addnode()
    {
        int nim;
        cout << "/nEnter the roll number of the student: ";
        cin >> nim;

        //Step 1: mengalokasikan memory untuk node baru
        Node *newnode = new Node;

        //Step 2: mengisi data pada node baru
        newnode->noMhs = nim;

    }
};