#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int T, max=0;
  cin >> T;

  // 한꺼번에 받아서 배열에 저장
  int *num = new int[T]; 
  for (int i = 0; i<T; i++){
    cin >> num[i];
    if (max < num[i])
      max = num[i];
  }

  // 테스트 케이스의 최고 길이까지 bool 배열 생성
  bool isPrime[max+1];
  fill_n(isPrime, max+1, true);
  isPrime[0] = false;
  isPrime[1] = false;

  // 소수 판정
  for (int i=2; i<=sqrt(max); i++){
    if (isPrime[i]){
      for (int j=i*2; j<=max; j+=i)
        isPrime[j] = false;
    }
  }

  // 골드바흐 파티션 출력 -> N/2 + i와 N/2 - i가 모두 소수가 되도록
  for (int i=0; i<T; i++){
    for (int j=num[i]/2; j>0; j--){
      if (isPrime[j] && isPrime[num[i]-j]){
        cout << j << " " << num[i]-j << "\n";
        break;
      }
    }
  }

}