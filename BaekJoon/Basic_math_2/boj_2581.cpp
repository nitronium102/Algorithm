#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int M, N, sum=0, min=10000;
    bool isPrime = true;
    cin >> M >> N;

    for (int i=M; i<=N; i++){
      if (i==1){
        isPrime = false;
      }
      else{
        for (int j=2; j<=sqrt(i); j++){
          if (i%j==0){
            isPrime = false;
            break;
          }
        }
      }
      if (isPrime == true){
        if (min > i){
          min = i;
        }
        sum += i;
      }
      isPrime = true;
    }
  
    if (sum == 0)
      cout << -1 << endl;
    else{
      cout << sum << endl;
      cout << min << endl;
    }
}