// 프로그래밍4: [E-PPER]1109,1606-올바른괄호배열 
#include <iostream>
using namespace std;

// 카탈란 수
// DP[i] = DP[0]*DP[i-1] + DP[1]*DP[i-2] + DP[2]*DP[i-3] + ... + DP[i-1]*DP[0];

int main(){
  int n;
  cin >> n;
  int *catalan = new int[n+1];
  fill_n(catalan, n+1, 0);
  catalan[0] = 1;
  catalan[1] = 1;

  for (int i=2; i<=n; i++){
    for (int j=0; j<=i-1; j++){
      // 합이 i-1이 되어야 함
      catalan[i] += catalan[j]*catalan[i-j-1];
    }
  }
  cout << catalan[n];
}