// 실버4
// Created by KangMinji on 2023-06-17.
// https://www.acmicpc.net/problem/18258

#include <iostream>
#include <queue>
using namespace std;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	string op;
	queue<int> q;

	// 입력
	cin >> n;
	while (n--) {
		cin >> op;
		if (op == "push") {
			cin >> x;
			q.push(x);
		} else if (op == "pop") {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		} else if (op == "size")
			cout << q.size() << '\n';
		else if (op == "empty")
			cout << q.empty() << '\n';
		else if (op == "front") {
			if (q.empty())cout << "-1\n";
			else cout << q.front() << '\n';
		} else if (op == "back") {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << '\n';
		}
	}
}