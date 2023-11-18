//
// Created by KangMinji on 2023-01-12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

/*
 * 버블 정렬이 몇 번째 단계에 완성되었는가?
 * 왼쪽으로 이동한 인덱스를 파악하기!
 */
int main() {
    int N;

    // 입력
    cin >> N;
    vector<ci> A(N+1, {0, 0}); // {value, idx}

    for (int i=1; i<=N; i++){
        cin >> A[i].first;
        A[i].second = i;
    }

    // 연산 https://etyoungsu.tistory.com/62
    sort(A.begin(), A.end());
    int ans = 0;
    for (int i=1; i<=N; i++){
        if (ans < A[i].second - i){
            ans = A[i].second - i;
        }
    }

    // 출력
    cout << ans + 1 << "\n";
}