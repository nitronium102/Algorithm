// 분해합
#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int N, sum, num;
  cin >> N;
  /*int tmp=N, digit=0;
  while(tmp>0){
    tmp /= 10;
    digit++;
  }

  int i = pow(10, digit-1)-9*digit;
*/
  int i=1;
  while(1){
    sum = i;
    num = i;
    while(num>0){
      sum += num%10;
      num /= 10;
    }
    if (sum == N){
      cout << i;
      break;
    }
    if (i==N){
      cout << "0";
      break;
    }
    i++;
  }
}