#include <iostream>
using namespace std;

int main(){
    int T, K, N;
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> K;
        cin >> N;
        int arr[15][14]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
        // k층의 n호에 몇 명이 살고 있는가
        int resident;
        for (int floor=1; floor<=K; floor++){
            for (int room=0; room<N; room++){
                resident += arr[floor-1][room];
                arr[floor][room] = resident;
            }
            resident=0;
        }
        cout << arr[K][N-1] << endl;
    }
}