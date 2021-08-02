#include <iostream>
using namespace std;

int main(){
    int T, K, N;
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> K;
        cin >> N;
        int arr[K+1][N+2] = {0,};
        // 먼저 1층 채우기
        for (int i=0; i<N+2; i++){
            arr[0][i+1]=i+1;
        }
        int resident=0;
        // k층의 n호에 몇 명이 살고 있는가
        for (int floor=1; floor<K+1; floor++){
            for (int room=1; room<N+2; room++){
                resident += arr[floor-1][room];
                arr[floor][room] = resident;
            }
            resident=0;
        }
        cout << arr[K][N] << endl;
    }
}