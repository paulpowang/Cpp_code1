#include <iostream>
#include <fstream>

using namespace std;

//declare function
void fileMerge (string, string);


//main function
int main()
{
    string fileName1, fileName2;
    //prompt user to input 2 filenames
    cout << "Enter 2 Filename with file extension to merge: ";
    cin >> fileName1;
    cin >> fileName2;



      //open input filenames
      ifstream file1(fileName1.c_str());
      ifstream file2(fileName2.c_str());
      //if file1 and file2 are the same one
      if (fileName1==fileName2)
        file2.close();

      //if input is invalid
      while(!(file1.is_open()&&file2.is_open())){
        string wrongInput;

        if(file1.is_open())//file1 open and file2 not
        {
          wrongInput = fileName2;
          cout << "The second file: "<< wrongInput << " doesn't exist!!" << endl;
        }
        else if(file2.is_open())//file2 open and file1 not
        {
          wrongInput = fileName1;
          cout << "The first file: "<< wrongInput << " doesn't exist!!" << endl;
        }
        else if(fileName1==fileName2)
        {
          cout << "Two filenames cannot be the same!!" << endl;
        }
        else //both don't open
          cout << "Files don't exist!!" << endl;

        file1.close();
        file2.close();
        //prompt user to enter again
        cout << "Please enter 2 filenames with file extension: ";
        cin >> fileName1;
        cin >> fileName2;
        file1.open(fileName1.c_str());
        file2.open(fileName2.c_str());



      }

      //to merge two files
      fileMerge(fileName1, fileName2);


    return 0;
}//end of main


//fileMerge function
void fileMerge(string fileName1, string fileName2){

    int file1Num, file2Num;
    string mergedFileName;
    //MergedFileName
    mergedFileName = fileName1+ "_" + fileName2 + "_Merged.txt";

    ofstream file3(mergedFileName.c_str());
    ifstream file1(fileName1.c_str());
    ifstream file2(fileName2.c_str());

    if(!(file1.is_open()&&file2.is_open())){
      cout << "Files not open!!" << endl;
    }
    else{

      file1 >> file1Num;
      file2 >> file2Num;

      while(!file1.eof()||!file2.eof()){

        if(file1Num < file2Num){
          file3 << file1Num << endl;
          file1 >> file1Num;
        }
        else{
          file3 << file2Num << endl;
          file2 >> file2Num;
        }

      }
      //out while loop after reach the end of file
      //input the last number
        if(file1Num < file2Num){
          file3 << file1Num << endl;
          file3 << file2Num << endl;
        }
        else{
          file3 << file2Num << endl;
          file3 << file1Num << endl;
        }


    }



    file1.close();
    file2.close();
    file3.close();

    cout << "Merged Filename is: "<< mergedFileName << endl;


}

