//
// Created by KangMinji on 2022-04-13.
//

/*
 * [1이 될 때까지]
 * 1) N이 K의 배수가 될 때까지- 1
 * 2) N / K (N%K == 0일 때만)
 */

#include <iostream>
using namespace std;

int main() {
    int n, k;
    int cnt = 0;

    cin >> n >> k;

    // N%K == 0이 될 때까지 1씩 빼기
    

    // N/K 수행
    cnt += n/k;

    cout << cnt;
}