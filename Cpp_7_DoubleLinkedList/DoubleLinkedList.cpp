#include "DoubleLinkedList.h"
#include <iostream>

using namespace std;

struct DoubleLinkedList::node
{
  int data;
  node* next;
  node* prev;
};

DoubleLinkedList::DoubleLinkedList()
{
  cout << endl << "default constructor!!";
  head = NULL;
  tail = NULL;
  num = 0;

}
DoubleLinkedList::DoubleLinkedList(int val)
{
  cout << endl << "value constructor!!";
  n = new node;
  n->data = val;
  n->next = NULL;
  n->prev = NULL;
  head = n;
  tail = n;
  num = 1;
}

DoubleLinkedList::~DoubleLinkedList()
{
  cout <<endl << "destructor!!";
  if(head == NULL)
    return;


  while(head!=NULL)
  {
    n=head;
    head=head->next;


    delete n;
  }
    tail=NULL;
    num=0;




}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& rhs)
{
    cout << endl << "copy constructor!!";
    num = rhs.num;

    curr = rhs.head;
    temp = new node;
    temp->data = curr->data;
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
    tail = temp;
    curr= curr->next;


    while(curr!=NULL)
    {
      n=new node;
      n->data = curr->data;
      n->prev = tail;
      n->next = NULL;
      temp->next = n;
      tail = n;
      temp = temp->next;
      curr = curr->next;

    }


}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& rhs)
{
  cout << endl << "assignment constructor";
  if (this == &rhs)
    return *this; // handle self assignment
  else
  {


    num = rhs.num;

    curr = rhs.head;
    temp = new node;
    temp->data = curr->data;
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
    tail = temp;
    curr= curr->next;


    while(curr!=NULL)
    {
      n=new node;
      n->data = curr->data;
      n->prev = tail;
      n->next = NULL;
      temp->next = n;
      tail = n;
      temp = temp->next;
      curr = curr->next;

    }

  }


  return *this;
}

void DoubleLinkedList::pushFront(int data)
{

  n = new node;
  n->data= data;
  n->next = head;
  n->prev = NULL;
  if(tail == NULL)
  {
    tail=n;
    head=n;
  }
  else
  {
    head->prev = n;
    head=n;
  }

  num++;
}
void DoubleLinkedList::pushBack(int data)
{
  n = new node;
  n->data = data;
  n->prev = tail;
  n->next = NULL;
  if(head == NULL)
  {
    head = n;
    tail = n;
  }
  else
  {
    tail->next = n;
    tail=n;
  }

  num++;

}
int DoubleLinkedList::popFront()
{
  n= head;

  head = head->next;
  num--;
  return n->data;
}
int DoubleLinkedList::popBack()
{
  n=tail;

  tail=tail->prev;
  tail->next = NULL;
  num--;
  return n->data;


}
void DoubleLinkedList::insertNode(int index, int val)
{
  n = new node;
  n->data = val;
  n->next = NULL;

  if(index == 0)
    pushFront(val);
  else if(index == num)
    pushBack(val);
  else
  {
    curr=head;
    for(int i = 0; i<index-1;i++)
    {
      curr=curr->next;
    }

    n->next = curr->next;
    curr->next = n;
    n->prev = curr;

  }
  num++;
}
void DoubleLinkedList::deleteDuplicates(int val)
{


  if(head->data == val)
  {
    while(head->data == val)
    {
      n=head;
      head=head->next;
      head->prev=NULL;
      delete n;
      num--;
    }

  }
  else if(tail->data == val)
  {
    while(tail->data == val)
    {
      n=tail;
      tail=tail->prev;
      delete n;
      tail->next =NULL;
      num--;
    }

  }
  else
  {
    curr=head;
    for(int i=0; i<num-1; i++)
    {
      curr=curr->next;
      if(curr->data == val)
      {
        n=curr;
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        delete n;
        num--;
        curr=head;//reset curr
        i=0;//reset i
      }
    }

  }
}
int DoubleLinkedList::mtoLastElement(int M)
{
  if(M==0)
    return tail->data;
  else
  {
    curr=tail;
    for(int i=0; i<M; i++)
    {
      curr=curr->prev;
    }
    return curr->data;
  }
}
int DoubleLinkedList::getSize()
{
  return num;
}


ostream& operator<<(ostream& os, DoubleLinkedList& dll)
{

  dll.curr = dll.head;
  cout << dll.curr->data;
  while(dll.curr->next!=NULL)
  {
    dll.curr= dll.curr->next;
    cout << " -> " <<dll.curr->data;
  }




}


void DoubleLinkedList::reverseList()
{
  curr = head;

  temp = curr->next;
  curr->next = curr->prev;
  curr->prev = temp;
  curr=curr->prev;

  while(curr!=NULL){
    temp = curr->next;
    curr->next = curr->prev;
    curr->prev = temp;
    curr=curr->prev;
  }

  temp = head;
  head = tail;
  tail = temp;




}
