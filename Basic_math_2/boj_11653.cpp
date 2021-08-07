#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    if (N != 1){
    	// i*i <= N을 사용해도 무방
        for (int i=2; i<=sqrt(N); i++){
            while (N%i==0){
                cout << i << endl;
                N = N/i;
            }
        }
    }
    if (N > 1)
      cout << N << endl;
}