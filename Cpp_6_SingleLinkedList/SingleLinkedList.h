#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H


class SingleLinkedList
{

  public:
    struct node;

    SingleLinkedList();//default construct
    SingleLinkedList(double val);

    ~SingleLinkedList();
    SingleLinkedList(const SingleLinkedList& rhs);
    SingleLinkedList& operator=(const SingleLinkedList& rhs);

    void pushFront(double data);
    void pushBack(double data);
    double popFront();
    double popBack();
    void insertNode(int index, double val);
    void deleteDuplicates(double val);
    double mtoLastElement(int M);
    int getSize();

    friend std::ostream& operator << (std::ostream& os, SingleLinkedList& sll);
    void reverseList();

  private:

      node* head;
      node* curr;//current pointer
      int num;

};

#endif // SINGLELINKEDLIST_H










