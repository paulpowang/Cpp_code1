#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;


//declare function
string MaxTime(int a, int b, int c, int d);
/*
the idea: since the biggest time is 23:59
there is a max of minute in one day, which is 1439
let it run through all the combination and find the biggest possible value with for loop
*/

int main() {

    string s, result;
    result = "NOT POSSIBLE";

    while (result== "NOT POSSIBLE"){

      cout << "Please enter four integers: " ;
      getline(cin, s);

      vector<int> vec;

      cout << "input: "<< s << endl;

      for(int i = 0; i < s.length(); i++){
        if(s.at(i)!=' ') {
         vec.push_back(s.at(i)-48);
        }
      }

      // if input more than 4 digit, return not possible
      if (vec.size()==4){
        result = MaxTime(vec[0], vec[1], vec[2], vec[3]);
      }

      cout << s <<" => " <<result<<endl; //result

    }//end of while loop

    return 0;
}

string MaxTime(int a, int b, int c, int d){

    int inputArr[4]={a, b, c, d};

    int maxMin=0;
    string result;

    //23:59 = 2*600+3*60+5*10+9 = 1439 min
    for (int i = 0; i < 4; i++){

        for(int i2 = 0; i2 < 4; i2++){
            if(i2==i){
              continue;
            }
            else {
              for(int i3 =0; i3 <4; i3++){
                if(i3==i||i3==i2){
                  continue;
                }
                else{
                  for(int i4 =0; i4 <4; i4++){
                    if (i4==i||i4==i2||i4==i3)
                        {continue;}

                    int sum = inputArr[i]*600+inputArr[i2]*60+inputArr[i3]*10+inputArr[i4];

                    if (sum <= 1439 && sum >= maxMin){
                        result.clear();
                        maxMin = sum;
                        result.push_back(inputArr[i]+48);
                        result.push_back(inputArr[i2]+48);
                        result.push_back(':');
                        result.push_back(inputArr[i3]+48);
                        result.push_back(inputArr[i4]+48);
                    }
                  }
                }
              }
            }
        }
    }
    if (result.empty()){
      return "NOT POSSIBLE";
    }
    return result;
}


