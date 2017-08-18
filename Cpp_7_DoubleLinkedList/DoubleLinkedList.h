#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include<iostream>
using namespace std;


class DoubleLinkedList
{


  public:
    struct node;

    DoubleLinkedList();
    DoubleLinkedList(int val);
    virtual ~DoubleLinkedList();
    DoubleLinkedList(const DoubleLinkedList& other);
    DoubleLinkedList& operator=(const DoubleLinkedList& other);

    void pushFront(int data);
    void pushBack(int data);
    int popFront();
    int popBack();
    void insertNode(int index, int val);
    void deleteDuplicates(int val);
    int mtoLastElement(int M);
    int getSize();
    friend ostream& operator<<(ostream& os, DoubleLinkedList& dll);
    void reverseList();

  private:
    node* head;
    node* tail;
    node* n;
    node* curr;
    node* temp;
    int num;
};

#endif // DOUBLELINKEDLIST_H
