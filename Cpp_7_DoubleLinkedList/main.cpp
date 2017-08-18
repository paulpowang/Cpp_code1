#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

int main()
{
    DoubleLinkedList list1;
    list1.pushBack(1);
    list1.pushBack(2);
    list1.pushBack(3);
    list1.pushBack(4);
    list1.pushBack(5);


    cout<< "default Double Linked List: "<< list1;
    cout<<endl;
    int x=0;
    while(x!=-1){


    cout<< endl<< "please enter number 1 ~ 8 or -1 to exit: "<<endl
        << "1. pushFront(data)"<<endl
        << "2. pushBack(data)"<<endl
        << "3. popFront()"<<endl
        << "4. popBack()"<<endl
        << "5. insertNode(index, val)"<<endl
        << "6. deleteDuplicates(val)"<<endl
        << "7. mtoLastElement(M)"<<endl
        << "8. getSize()"<<endl
        << "9. reverseList()"<<endl;

    cin >> x;
    if(x == 1)
    {
      cout << "1. pushFront(data)"<<endl;
      int input1=1;
      cout <<"Current list: "<<list1;
      cout << endl;
      cout << "Enter int number for pushFront or -1 to exit: ";
      while(input1!=-1)
      {
        cin >> input1;
        if(input1!=-1)
        {
          list1.pushFront(input1);
          cout << "pushFront: " << input1<<endl;
        }

      }
      cout <<"Current list: "<<list1;
      cout << endl;
    }
    else if (x ==2)
    {
      cout << "2. pushBack(data)"<<endl;
      int input2=1;
      cout <<"Current list: "<<list1;
      cout << endl;
      cout << "Enter int number for pushBack or -1 to exit: ";
      while(input2!=-1)
      {
        cin >> input2;
        if(input2!=-1)
        {
          list1.pushBack(input2);
          cout << "pushBack: " << input2<<endl;
        }

      }
      cout <<"Current list: "<<list1;
      cout << endl;
    }

    else if (x ==3)
    {
      int temp = list1.popFront();
      cout << endl<< "popFront: " << temp<<endl;
      cout << "Current list: "<< list1;
      cout << endl;
    }
    else if (x ==4)
    {
      int temp = list1.popBack();
      cout << endl<< "popBack: " << temp<<endl;
      cout << "Current list: "<< list1;
      cout << endl;
    }
    else if (x ==5)
    {
      cout <<endl<< "5. insertNode(index, val)"<< endl;
      cout << "Current List Size: " << list1.getSize()<<endl;
      cout << "Enter int for index: ";
      int index5;
      cin >> index5;
      cout << "Enter int for val: ";
      int val5;
      cin >> val5;
      list1.insertNode(index5, val5);
      cout << "Current list: "<< list1;
      cout << endl;

    }
    else if (x ==6)
    {
      cout << endl << "6. deleteDuplicates(val)"<<endl;
      cout <<"Current list: "<<list1;
      cout << endl << "Enter 1 int number for deleteDuplicates: ";
      int input6;
      cin >> input6;
      list1.deleteDuplicates(input6);
      cout <<"Current list: "<<list1;
      cout << endl;
    }
     else if (x ==7)
    {
      cout<<endl<< "7. mtoLastElement(M)"<<endl;
      cout <<"Current list: "<<list1;
      cout << endl << "Enter 1 int number for mtoLastElement(M): ";
      int input7;
      cin >> input7;

      cout << "mtoLastElement at " << input7 << " is " << list1.mtoLastElement(input7) << endl;
    }
    else if (x ==8)
    {
      cout << endl<<"Current List Size: " << list1.getSize()<<endl;
    }
    else if (x == 9)
    {
      list1.reverseList();
      cout <<"Current list: "<<list1;
    }
    else
    {
      cout<<endl<< "invalid input!!"<<endl;
    }
  }//end of while loop
    return 0;
}
