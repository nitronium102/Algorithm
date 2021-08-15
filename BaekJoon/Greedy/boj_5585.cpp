// 거스름돈
#include <iostream>
using namespace std;

int main(){
  int money, cnt=0;
  cin >> money;

  money = 1000-money;
  int change[] = {500, 100, 50, 10, 5, 1};
  for (int i=0; i<6; i++){
    if (money < change[i])
      continue;
    cnt += money/change[i];
    money %= change[i];
  }

  cout << cnt;
}