#include <iostream>
#include <cmath>
using namespace std;
int MAX = 123456*2;

int main() {
  int N=-1, cnt = 0, limit;
  bool isPrime[MAX+1];
  while (true){
    cin >> N;
    if (N == 0)
      break;
    fill_n(isPrime, MAX+1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i=2; i<=sqrt(2*N); i++){
      if (isPrime[i]){
        for (int j=2*i; j<=2*N; j+=i){
          if (2*N > MAX + 1)
            break;
          isPrime[j] = false;
        } 
      }
    }

    for (int i = N+1; i<=2*N; i++){
      if (isPrime[i])
        cnt += 1;
    }

    cout << cnt << "\n";
    cnt = 0;
  }
}