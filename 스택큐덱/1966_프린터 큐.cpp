// 실버3
// Created by KangMinji on 2023-01-18.
// https://www.acmicpc.net/problem/1966

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> ci; // {들어온 순서, 중요도}

int playGame(queue<ci> &q, priority_queue<int> &pq, int M) {
    int cnt = 0;

    while (!q.empty()) {
        // 1) 가장 앞에 있는 문서의 중요도 확인
        int idx = q.front().first;
        int importance = q.front().second;

        // 2) 나머지 문서 중요도 확인
        // 2-1) 현재 문서보다 중요도 높은 경우 -> 가장 뒤에 재배치
        if (importance < pq.top()) {
            q.push(q.front());
            q.pop();
            continue;
        }

        // 2-2) 현재 문서가 가장 중요도 높은 경우 -> 인쇄
        q.pop();
        pq.pop();
        cnt++;

        // 3) 우리가 찾는 문서인 경우 -> cnt 반환
        if (idx == M) {
            return cnt;
        }
    }
}

int main() {
    int T, N, M, num;

    // 입력
    cin >> T;
    while (T--) {
        cin >> N >> M;
        queue<ci> q;
        priority_queue<int> pq; // 내림차순

        for (int i = 0; i < N; i++) {
            cin >> num;
            q.push({i, num});
            pq.push(num);
        }

        // 연산 & 출력
        cout << playGame(q, pq, M) << "\n";
    }
}

