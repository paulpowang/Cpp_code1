# Cpp_7_DoubleLinkedList

Function:

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

What it does:
	
	Run this program, it will prompt user to enter 1 to 9 to test function or -1 for exit;
	1. pushFront(data)
	2. pushBack(data)
	3. popFront()
	4. popBack()
	5. insertNode(index, val)
	6. deleteDuplicates(val)
	7. mtoLastElement(M)
	8. getSize()
	9. reverseList()

	A default linked list is create: 1 -> 2 -> 3 -> 4 -> 5
	- will return the current linked list after every action


	1. pushFront(data)"<<endl and 2. pushBack(data)"<<endl
	-allow user to enter int data and push into Linklist
	-"-1" for exit and return to funtion option;

	3. popFront()"<<endl and 4. popBack()"<<endl
	-will pop and return back to function option

	5.insertNode(index, val)
	-will display current linked list
	-will prompt user to enter index
	-then prompt user to enter val
	-display current list after action
	-return back to function option

	6. deleteDuplicates(val)
	-will display current linked list
	-will prompt user to enter one int number
	-display current list after action
	-return back to function option

	7. mtoLastElement(M)
	-will display current linked list
	-will prompt user to enter int number
	-return result
	-return back to function option

	8. getSize()
	-will display current linked list size
	-return back to function option

	9.reverseList()
	-will reverse current linked list
	-display reversed current linked list after action
	-return back to function


