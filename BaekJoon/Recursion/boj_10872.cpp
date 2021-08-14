// 재귀를 이용한 팩토리얼 구현
#include <iostream>
using namespace std;

int factorial(int n){
  if (n==1 || n==0)
    return 1;
  else
    return factorial(n-1)*n;
}

int main(){
  int N;
  cin >> N;
  cout << factorial(N);
}