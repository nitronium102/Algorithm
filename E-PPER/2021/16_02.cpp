// [02] 1604 - 완전수면 YES, 아니면 NO
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;


int main() {
  int k=3;
  int numbers[]={3, 6, 8128};
  int sum=0;
  string result[k];
  vector<int> com;

  for (int i = 0; i<k; i++){
    // 약수 구하기
    vector<int> com;
    for (int j=1; j<=numbers[i]; j++){
      if (numbers[i] % j == 0 && numbers[i] != j){
        com.push_back(j);
      }
    }
    // 완전수인지 판별
    for (int q=0; q<com.size(); q++){
      sum += com[q];
    }
    
    // 후처리
    if (sum == numbers[i]){
      result[i] = "YES";
    }
    else{
      result[i] = "NO";
    }
    sum = 0;
    com.clear();
  }
  for (int i=0; i<k; i++)
    cout << result[i];
}