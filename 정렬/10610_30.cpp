//
// Created by KangMinji on 2023-01-12.
//

#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 1) 각 자리 수를 모두 더하면 3으로 나누어 떨어져야 한다
 * 2) 마지막 숫자가 0이어야 함
 */
int main() {
    string N;
    int sum = 0;

    // 입력
    cin >> N;

    // 연산
    sort(N.begin(), N.end(), greater<>());

    for (int i=0; i<N.length(); i++){
        sum += N[i] - '0';
    }

    if (sum % 3 == 0 && N[N.length()-1] == '0'){
        cout << N;
    } else {
        cout << "-1";
    }
}