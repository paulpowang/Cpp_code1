#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

    /*
    To insert 7777-7781 between the 6000th and 6001st number
    1. locate 6001st number and the numbers after, then store into array or vector
    2. input 7777-7781 after 6000th number
    3. input numbers stored in array continue after that
    */

    /*4 numbers + 1 space for 9999 sets, total = 49995,
    check with:
    file1.seekg(0,ios::end);
    cout <<endl<< file1.tellg() << endl;*/


    void insertNumber(){
    //open file1.txt
    ifstream file1("file1.txt");
    //vector to store 6001 and after
    vector<string> vecNum;

    if (!file1.is_open()){
      cout << "File doesn't exist."<< endl;
    }else{
      //to locate the 6001st number, which is right after 6000th, 5*6000=30000
      file1.seekg(30000);
      //to store 6001st and the numbers after into vector
      string num;
      file1 >> num;
      vecNum.push_back(num);
      while(file1>>num){
          vecNum.push_back(num);
      }
    //cout << vecNum.size(); 3999 numbers were stored, checked

    }

    fstream insertFile1("file1.txt",ios::in|ios::out);
    if(!insertFile1.is_open()){
      cout << "File doesn't exist.";
    }
    else{
      // to locate the insert point, right after 6000th number, is 30000
      insertFile1.seekp(30000);

      // insert 7777-7781
      for(int i = 7777; i <=7781; i++){

        insertFile1 << i << endl;
      }
      //input data in vector
      for (int i = 0; i < vecNum.size();i++){

        insertFile1 << vecNum[i]<<endl;
      }
      insertFile1.close();
    }



    }



int main()
{
    insertNumber();
    return 0;
}
