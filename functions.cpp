#include <iostream>

using namespace std;


string name = "ali";
string name;
int sum(int a, int b){
    return a + b;
};

void average(int summ, int qnty){
    int fakeAverage = sum(summ , qnty);
    cout << fakeAverage;
    cout << summ / qnty;
}

int behnaz(string  fruit){
    if(fruit == "Cherry"){
      return 1;
    }else{
      return -1;
    }
};


int main(){
int behnazMood = behnaz("Banana");
if(behnazMood == 1){
 cout << "she is happy\n";
}else{
  cout << "she is Angry\n";
};

//  int subj1 = 10;
//  int subj2 = 20;

//  average (sum(subj1 , subj2) , 2);



    return 1;
};
