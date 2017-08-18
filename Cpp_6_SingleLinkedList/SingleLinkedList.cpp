#include<iostream>
#include <cstdlib>
#include "SingleLinkedList.h"

using namespace std;

struct SingleLinkedList::node{
  double data;
  node* next;
};

SingleLinkedList::SingleLinkedList()
{
  cout<<"default constructor!!"<<endl;
  head = NULL;
  curr = NULL;
  num=0;
}
SingleLinkedList::SingleLinkedList(double val){
  cout<<"value constructor!!"<<endl;
  node* n = new node;
  n->data = val;
  n->next = NULL;
  head = n;
  head->next = NULL;

  num = 1;
}
SingleLinkedList::~SingleLinkedList(){
  cout << endl <<"destructor!!" << endl;
  if(head == NULL)
    return;

  node* temp;
  while(head!=NULL){
    temp = head->next;
    delete head;
    head = temp;
  }
  num = 0;
}
//copy
SingleLinkedList:: SingleLinkedList(const SingleLinkedList& rhs)
{
  cout << endl << "copy constructor!!";
  num = rhs.num;
  node* n=new node;
  n->data = rhs.head->data;
  n->next = NULL;
  head = n;
  curr = rhs.head;
  curr = curr->next;
  node* temp = head;

  while(curr!=NULL)
  {
    n=new node;
    n->next = NULL;
    n->data = curr->data;
    temp->next = n;
    temp = temp->next;
    curr = curr->next;
  }
}
//assignment
SingleLinkedList& SingleLinkedList::operator=(const SingleLinkedList& rhs)
{
  cout<< endl << "assignment constructor!!";
  if (this == &rhs)
    return *this; // handle self assignment
  else
  {
    num = rhs.num;
    node* copycurr = rhs.head;
    node* temp = new node;
    temp->data = copycurr->data;
    head = temp;
    copycurr = copycurr->next;

    while(copycurr !=NULL)
    {
      node* temp2 = new node;
      temp2->data = copycurr->data;
      temp->next = temp2;
      temp = temp->next;
      copycurr=copycurr->next;
    }
  }
  return *this;
}

void SingleLinkedList::pushFront(double addData){
  
  node* n = new node;
  n->next = NULL;
  n->data = addData;
  node* temp = new node;

  if (head==NULL){
    head = n;
    num ++;
  }
  else{
    temp = head;
    head = n;
    n->next = temp;
    num++;
  }
}

void SingleLinkedList::pushBack(double addData){

  node* n = new node;
  n->next = NULL;
  n->data = addData;

  if(head == NULL){

    head = n;
    num ++;
  }
  else{
    curr = head;
    while(curr->next != NULL){
      curr=curr->next;
    }
    curr->next = n;
    num++;
  }
}

  double SingleLinkedList::popFront(){
    double d;

    if(head->next == NULL){
      d = head->data;
      head = NULL;
      num--;
      return d;
    }
    else{
      d= head->data;
      head = head->next;
      num--;
      return d;
    }
  }

  double SingleLinkedList::popBack(){
    double d;

    if(head->next == NULL){
      d = head->data;
      head = NULL;
      num--;
      return d;
    }
    else{
      curr = head;
      while(curr->next->next !=NULL){
        curr = curr->next;
      }
      d= curr->next-> data;
      curr->next = NULL;
      num--;
      return d;
    }
  }

  void SingleLinkedList::insertNode(int index, double val){
    node* n = new node;
    n->data = val;

    if(index == 0){
      pushFront(val);
    }else if (index == num-1){
      pushBack(val);

    }else{
      curr = head;
      for(int i = 0; i < index-1; i++){
        curr = curr->next;
      }
      n->next = curr->next;
      curr->next = n;
      num++;
    }
  }

void SingleLinkedList::deleteDuplicates(double val){
  curr = head;
  while (curr->next != NULL){

    if(curr->next->data == val){
      curr->next = curr->next->next;
      num--;
    }else{
    curr = curr->next;}
  }
}

    double SingleLinkedList::mtoLastElement(int M){
      curr = head;
      for(int i = 0; i< num-M-1; i++){
        curr=curr->next;
      }
      return curr->data;
    }

    int SingleLinkedList::getSize(){
      return num;
    }


    ostream& operator << (ostream& os, SingleLinkedList& sll){

      sll.curr = sll.head;
      while(sll.curr->next != NULL){
        cout<< sll.curr->data << " -> ";
        sll.curr=sll.curr->next;
      }
        cout << sll.curr->data;
    }


    void SingleLinkedList::reverseList(){

      node* prev;
      node* aft;
      curr = head;
      prev = NULL;

      while(curr!=NULL)
      {
        aft = curr->next;
        curr->next = prev;
        prev = curr;
        curr = aft;
      }
        head = prev;
    }


