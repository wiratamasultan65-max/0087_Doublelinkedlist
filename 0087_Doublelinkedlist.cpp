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
    }
};