//
// Created by KangMinji on 2022-03-17.
//

/*
 * E-QUEEN
 */


#include <iostream>
#define SIZE 15
using namespace std;

int n, ans = 0;
bool check[SIZE]; // 열

bool promising(int num){
    int idx = 0;
    while (idx < num){ // 이미 놓여있는 모든 퀸에 대해 같은 행, 같은 대각선(행과 열의 차이 동일) 체크
        if (check[num] == check[idx] || abs(check[num] - check[idx]) == (num - idx))
            return false;
        idx++;
    }
    return true;
}

void backtracking(int cnt){
    // 기저조건 : n개의 퀸이 모두 놓임
    if (cnt == n){
        ans++;
        return;
    }
    // 1) 배치할 열 선택
    for (int i=0; i<n; i++){
        check[cnt] = i;
        if (promising(cnt))
            backtracking(cnt+1);
    }
}

int main(){

    // 입력
    cin >> n;

    // 연산
    backtracking(0);

    // 출력
    cout << ans;
}