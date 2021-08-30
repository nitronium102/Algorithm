// 백준 팰린드롬수
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void pelindrom(string num){

  string revNum = num;
  reverse(revNum.begin(), revNum.end());
  if (num == revNum)
    cout << "yes" << "\n";
  else
    cout << "no" << "\n";
}

int main(){
  int num;
  cin >> num;
  while(num != 0){
    pelindrom(to_string(num));
    cin >> num;
  }
}