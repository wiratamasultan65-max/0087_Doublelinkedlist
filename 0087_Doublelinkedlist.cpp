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

        //Step 3: menghubungkan node baru dengan linked list
        if (START == NULL || nim <= START->noMhs) 
        {
            if (START != NULL && nim == START->noMhs) 
            {
                cout << "Duplicate roll number not allowed." << endl;
                return;
            }
        