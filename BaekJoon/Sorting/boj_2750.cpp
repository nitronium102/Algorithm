// 수 정렬하기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int N, num;
  cin >> N;
  vector<int> v;
  for (int i=0; i<N; i++){
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end());
  for (int i=0; i<N; i++){
    cout << v[i] << "\n";
  }
}