#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int noMhs;
    Node *Next;
    Node *Prev;
};

class DoubleLinkedList
{
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
        cout << "\nEnter the roll number of the student: ";
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
            
            //Step 4 newnode->Next = START;
            newnode->Next = START;

            //Step 5: START->Prev = newnode (if START exists)
            if (START != NULL) 
            {
                START->Prev = newnode;
            }

            //Step 6: newNode.prev = NULL;
            newnode->Prev = NULL;

            //Step 7: START = newnode;
            START = newnode;
            return;
        }

        //Step 8: mencari posisi yang tepat untuk menyisipkan node baru
        Node *current = START;
        while (current->Next != NULL && current->Next->noMhs < nim) 
        {
            current = current->Next;
        }

        if (current->Next != NULL && nim == current->Next->noMhs) 
        {
            cout << "\nDuplicate roll number not allowed." << endl;
            return;
        }

        //step 9: menyisipkan node baru setelah current
        newnode->Next = current->Next; //step 9a: newNode.next = current.next
        newnode->Prev = current;    //step 9b: newnode.prev = current

        //insert last node
        if (current->Next != NULL) 
            current->Next->Prev = newnode; //step 9c: if current.next != NULL then current.next.prev = newnode
            current->Next = newnode; //step 9d: current.next = newnode
        
        current->Next = newnode; //step 9d: current.next = newnode
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty." << endl;
            return;
        }

        cout << "\nEnter the roll number of the student to delete: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        //step 1: mencari node yang akan dihapus
        while (current != NULL && current->noMhs != rollNo) 
            current = current->Next;

        if (current == NULL)
        {
            cout << "\nRecord not found." << endl;
            return;
        }

        // step 2 : jika node yang akan dihapus adalah node pertama
        if (current == START)
        {
            START = current->Next; // step 2a: START = current.next
            if (START != NULL) 
                START->Prev = NULL; // step 2b: if START != NULL then START.prev = NULL
        }
        else
        {
            current->Prev->Next = current->Next; // step 3a: current.prev.next = current.next

            if (current->Next != NULL) 
                current->Next->Prev = current->Prev; // step 3b: if current.next != NULL then current.next.prev = current.prev
        }

        // step 4: menghapus node
        delete current;
        cout << "\nRecord deleted successfully." << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty." << endl;
            return;
        }

        