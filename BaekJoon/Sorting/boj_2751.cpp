// 수 정렬하기 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n; 
  vector<int> arr;
  cin >> n;
  arr.assign(n, 0);
  for (int i=0; i<n; i++){
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  for (int i=0; i<n; i++){
    cout << arr[i] << "\n";
  }
}