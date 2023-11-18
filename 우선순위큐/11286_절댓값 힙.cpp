// 실버1
// Created by KangMinji on 2023-04-06.
// https://www.acmicpc.net/problem/11286

#include <iostream>
#include <queue>
using namespace std;

// 우선순위큐 비교식 -> 일반 비교식과는 반대로
struct cmp {
	bool operator()(const int &a, const int &b) {
		if (abs(a) != abs(b)) {
			return abs(a) > abs(b);
		}
		return a > b;
	}
};

int main() {
	// 시간초과
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	priority_queue<int, vector<int>, cmp> pq;

	// 입력
	cin >> n;
	while (n--) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << "0\n";
			} else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		} else {
			pq.push(x);
		}
	}
}