# Cpp_5_insertNumberInFile

Function: 
	 void insertNumber(); // 

How to use it:
Void insertNumber(); create for insert 7777 to 7781 between the 6000th and 6001st number in file1.txt.
The default filename is “file1.txt”, since it the file we need to work with.
Just have the program and the file1.txt in the same folder and compile, and then it will add 7777 to 7781 between the 6000th and 6001st number in the file.

What the program do: 
1.	It locates 6001st number with seekg(), and store the 6001st and the numbers after it into vector.
2.	It open the file and add 7777 to 7781 start at 6001st number and input number from vector. 
3.	I use string type to store numbers, so the numbers like 0592 can remain no change. 
Before: 
The 6000th and 6001st are 0592 and 5616
After:
The 7777 to 7781 is now between 0592 and 5616

From 1-9999 change to 1 to 10004, 5 numbers increased.
