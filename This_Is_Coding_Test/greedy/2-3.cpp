//
// Created by KangMinji on 2022-01-28.
//

#include <iostream>
using namespace std;

int main(){
    int n, k;
    int cnt = 0;

    // 입력
    cin >> n >> k;

    // 연산
    while (true){ // n이 k보다 클 때
        // 탈출조건
        if (n<k) break;

        // (1번) n이 k로 나누어질 때까지 1을 뺀다
        if (n%k){
            int remainder = n%k;
            n -= remainder;
            cnt+=remainder;
        }
        // (2번) n을 k로 나눈다
        n /= k;
        cnt++;
    }

//    while(true){
//        // 탈출조건
//        if (n < k) break;
//        // n이 k로 나누어 떨어지는 수가 될 때까지 1씩 빼기
//        int target = (n/k)*k;
//        cnt += (n-target);
//        n = target;
//        // k로 나누기
//        cnt++;
//        n/= k;
//    }

    // 출력
    cout << cnt << "\n";
}