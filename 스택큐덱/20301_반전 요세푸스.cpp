// 실버3
// Created by KangMinji on 2023-01-18.
// https://www.acmicpc.net/problem/20301

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> playGame(deque<int> &dq, int K, int M) {
    bool change_left = false;
    vector<int> result;
    int cnt = 0;

    while (!dq.empty()) {
        if (cnt == M) {
            change_left = !change_left;
            cnt = 0;
        }

        if (change_left) {
            for (int i = 0; i < K - 1; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            result.push_back(dq.back());
            dq.pop_back();
        } else {
            for (int i = 0; i < K - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            result.push_back(dq.front());
            dq.pop_front();
        }
        cnt++;
    }
    return result;
}

int main() {
    int N, K, M;
    deque<int> dq;

    // 입력
    cin >> N >> K >> M;
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    // 연산
    vector<int> result = playGame(dq, K, M);

    // 출력
    for (int num: result) {
        cout << num << "\n";
    }
}