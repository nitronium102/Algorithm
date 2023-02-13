// 실버2
// Created by KangMinji on 2023-02-13.
// https://www.acmicpc.net/problem/16953

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<long long, int> ci;

void bfs(int a, int b) {
	queue<ci> q;
	q.push({a, 1});

	while (!q.empty()) {
		long long cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		long long v1 = cur * 2;
		long long v2 = cur * 10 + 1;

		if (v1 == b || v2 == b) {
			cout << cnt + 1;
			exit(0);
		}

		if (v1 < b) {
			q.push({v1, cnt + 1});
		}
		if (v2 < b) {
			q.push({v2, cnt + 1});
		}
	}
	cout << -1;
}

int main() {
	int a, b;

	// 입력
	cin >> a >> b;

	// 연산
	bfs(a, b);
}