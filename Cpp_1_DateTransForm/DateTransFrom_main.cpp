#include <iostream>
#include <string>

using namespace std;

//function declare
void ReformatDate();

int main()
{
    ReformatDate();
    return 0;
}

//function definition
void ReformatDate()
{
  //01st Mar 1984 => 1984 - 03 - 01
  //0123456789012
  int exist = 0;//flag

  while( exist != -1){

  string inputDate;
  cout << "Please enter date: ie. 1st Mar 1984: ";
  //prompt to input
  getline(cin, inputDate);
  string oldDate = inputDate;
  //12 char => 13 char, so 1st => 01st, has the same length as 11st and after
  if (inputDate.length() == 12){
   inputDate = "0" + inputDate;
  }
  //check length
  if (inputDate.length() != 13){
   cout << "Invalid input!!" << endl;
   continue;
  }
  //check day
  string dayTh = "";

  dayTh.push_back(inputDate.at(1));
  dayTh.push_back(inputDate.at(2));
  dayTh.push_back(inputDate.at(3));

  if ((dayTh=="1th" || dayTh=="2th" || dayTh=="3th")||(dayTh != "1st" && dayTh != "2nd" && dayTh!= "3rd" &&  dayTh.erase(0,1)!= "th")){
   cout << "Invalid input!!" << endl;
   continue;
  }
  // "1" = 48;

  int dayNum = 0;
  dayNum = (inputDate.at(0)-48)*10+(inputDate.at(1)-48);
  if (dayNum > 31 || dayNum <1){
   cout << "invalid input. dayNum" << endl;
   continue;
  }
  string newDay = "";
  newDay.push_back(inputDate.at(0));
  newDay.push_back(inputDate.at(1));

  //check year
  int yearNum = (inputDate.at(9)-48)*1000+(inputDate.at(10)-48)*100+(inputDate.at(11)-48)*10+(inputDate.at(12)-48);
  if (yearNum < 1900 || yearNum > 2100){
   cout << "Invalid input!!" << endl;
   continue;
  }

  //check month
  string inputMonth = "";
  string newMonth = "";
  inputMonth.push_back(inputDate.at(5));
  inputMonth.push_back(inputDate.at(6));
  inputMonth.push_back(inputDate.at(7));

  if (inputMonth == "Jan"){
    newMonth = "01";}
  else if (inputMonth == "Feb"){
    newMonth = "02";}
  else if (inputMonth == "Mar"){
    newMonth = "03";}
  else if (inputMonth == "Apr"){
    newMonth = "04";}
  else if (inputMonth == "May"){
    newMonth = "05";}
  else if (inputMonth == "Jun"){
    newMonth = "06";}
  else if (inputMonth == "Jul"){
    newMonth = "07";}
  else if (inputMonth == "Aug"){
    newMonth = "08";}
  else if (inputMonth == "Sep"){
    newMonth = "09";}
  else if (inputMonth == "Oct"){
    newMonth = "10";}
  else if (inputMonth == "Nov"){
    newMonth = "11";}
  else if (inputMonth == "Dec"){
    newMonth = "12";}
  else{
   cout << "Invalid input!!" << endl;
   continue;
  }

  //Month has 30 days: Apr, Jun, Sep, Nov
   if (inputMonth == "Apr"||inputMonth =="Jun"||inputMonth == "Sep"||inputMonth =="Nov")
   {
     if (dayNum >30)
     {cout << "Invalid input!!" << endl;
      continue;
     }
   }
  //Feb has 28 or 29
    //leap year: year%4 ==0 && year %100 !=0 || year%400 == 0;
   if (inputMonth == "Feb"&&dayNum > 29)
    {
     cout << "Invalid input!!" << endl;
     continue;
    }
   else if (!(yearNum%4 == 0 && yearNum%100!=0|| yearNum%400 ==0)&&dayNum > 28&&inputMonth == "Feb"){
     cout << "Invalid input!!" << endl;
     continue;
    }


  //print
  cout << oldDate << " => " << yearNum << " - " << newMonth << " - " << newDay << endl;
  exist = -1;//flag exist
 }
};

