// 실버2
// Created by KangMinji on 2023-08-09.
// https://www.acmicpc.net/problem/1927

#include <bits/stdc++.h>

using namespace std;

int main() {
	// 시간초과
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	int x;
	priority_queue<int, vector<int>, greater<>> pq;

	cin >> n;
	while (n--) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << "0\n";
			} else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		} else {
			pq.push(x);
		}
	}
}