// 동전 0
#include <iostream>
#include <vector>
#include <algorithm> // reverse
using namespace std;

int main(){
  int N, K, num, cnt=0;
  cin >> N >> K;
  vector<int> v;

  for (int i=0; i<N; i++){
    cin >> num;
    v.push_back(num);
  }

  reverse(v.begin(), v.end());

  for (int i=0; i<N; i++){
    if (K >= v[i]){
      cnt += K/v[i];
      K %= v[i];
    }
  }

  cout << cnt;
}