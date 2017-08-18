#include <iostream>
#include <string>
#include <vector>








using namespace std;

struct TokenFreq {
 string token;
 int freq;

};


//function declare
vector<TokenFreq> getTokenFreq( string& s);

void getLeastFreqLetter(string& );

vector<string> stringToVector (string&);

TokenFreq fillStruct(string);

TokenFreq defaultStruct();



void printVector(vector<string>);

void printVectorStruct(vector<TokenFreq>);

int main()
{

  cout << "Please Enter one sentence: ";

  string s;
  getline(cin,s);
  vector<TokenFreq> tok = getTokenFreq( s);



   printVectorStruct(tok);
   getLeastFreqLetter(s);


    return 0;
}


vector<TokenFreq> getTokenFreq( string& s){

   //create a vector to store struct
  vector<TokenFreq> vectorStruct;

  //create a vector to store userInput
  vector<string> inputString = stringToVector(s);
    //inputString to store userInput separated by space
    //string input = "";



      for (int i=0; i< inputString.size(); i++){

      //store in vector as struct
      if (vectorStruct.size()==0){//the first one
        vectorStruct.push_back(fillStruct(inputString[i]));
        vectorStruct.push_back(defaultStruct());
      }
      else
      {
          for(int j = 0; j < vectorStruct.size()-1; j++)
           {
             if (inputString[i] == vectorStruct[j].token)
             {
               vectorStruct[j].freq ++;
               break;
             }
             else if ( vectorStruct[j+1].freq==0)
             {
               if (vectorStruct.size()>501){//no more than 500 tokens;
                  break;
               }
               vectorStruct.pop_back();
               vectorStruct.push_back(fillStruct(inputString[i]));
               vectorStruct.push_back(defaultStruct());
               break;
             }
           }

      }

      }

  return vectorStruct;
}


vector<string> stringToVector (string& s){

 vector<string> vectorS;
 string tempS;
 for (int i = 0; i < s.size(); i ++){

  // words are separated by space
  if (s.at(i)==' '){
  vectorS.push_back(tempS);
  tempS.clear();
  continue;
  }
  tempS.push_back(s.at(i));


 }

 return vectorS;
}



TokenFreq defaultStruct(){
 TokenFreq newWord =
  {
    "", 0
  };
 return newWord;

}



TokenFreq fillStruct(string newinput){
 TokenFreq newWord =
  {
    newinput, 1
  };
 return newWord;

}

void getLeastFreqLetter(string& s){

 //ASCII table: A = 65, Z = 90, a = 97,z = 122, 1 = A-64 = a - 96;
 //create vector <26> to contain the freq a to z
 vector<int> letterFreq;
 for (int i = 0; i< 26;i++)
    {
        letterFreq.push_back(0);

    }
 // container number
 int conNum;
 // add freg count into container
 for (int i = 0; i < s.size(); i++){
   if (s.at(i)>96&&s.at(i)<123){
    conNum = s.at(i)-96;
   }
   else if (s.at(i)>64&&s.at(i)<91){
    conNum = s.at(i)-64;
   }
   else {
    continue;
   }
   letterFreq[conNum-1] ++;

 }
 // find the lease freq number from container, not include 0;
 int leastFrqNum = 500;
 char leastFrqLetterLower;
 char leastFrqLetterCap;

 for (int i = 25; i >= 0; i--){
  if (letterFreq[i]==0){
   continue;
  }
  if (letterFreq[i] <= leastFrqNum)
    {
      leastFrqNum = letterFreq[i];
      leastFrqLetterLower = i + 97;
      leastFrqLetterCap = i + 65;
    }

 }





 cout << endl << "Least Freq Letter is: " << "'" <<leastFrqLetterCap << "'" << " or "<< "'" <<leastFrqLetterLower << "'" << " : " << leastFrqNum;
}


void printVector(vector<string> vector){
 cout << endl;
 for (int i=0; i < vector.size(); i++ ){
  cout << vector[i] << " ";
 }

}

void printVectorStruct(vector<TokenFreq> vector){
 cout << endl << "{" << "'" << vector[0].token << "': " << vector[0].freq;
 for (int i=1; i < vector.size(); i++ ){
  if (vector[i].freq == 0){
    break;
  }
  else{
    cout << ", '" << vector[i].token << "': " << vector[i].freq;
  }

 }
 cout << "}";
}
