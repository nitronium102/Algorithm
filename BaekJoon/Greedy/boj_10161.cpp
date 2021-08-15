// 전자레인지
#include <iostream>
using namespace std;

int main(){
  int T, a, b, c, remainder;
  cin >> T;

  a = T/300;
  b = (T%300)/60;
  c = (T%60)/10;
  remainder = T%10;

  if (remainder == 0)
    cout << a << " " << b << " " << c;
  else
    cout << -1;
}