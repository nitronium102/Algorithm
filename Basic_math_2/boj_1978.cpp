#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N, num, cnt=0;
    cin >> N;
    bool isPrime = true;
    for (int i = 0; i<N; i++){
        cin >> num;
        if (num == 1){
          isPrime = false;
        }
        else {
          for (int j=2; j<=sqrt(num); j++){
            if (num%j==0){
                isPrime = false;
                break;
            }
          }
        }
        if (isPrime == true)
            cnt += 1;
        isPrime = true;
    }
    cout << cnt << endl;
}