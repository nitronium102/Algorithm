// 실버4
// Created by KangMinji on 2023-06-16.
// https://www.acmicpc.net/problem/10866

#include <iostream>
#include <deque>
using namespace std;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	string input;
	deque<int> dq;

	// 입력
	cin >> n;
	while (n--) {
		cin >> input;
		if (input == "push_front"){
			cin >> x;
			dq.push_front(x);
		} else if (input == "push_back"){
			cin >> x;
			dq.push_back(x);
		} else if (input == "pop_front"){
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		} else if (input == "pop_back") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (input == "size")
			cout << dq.size() << '\n';
		else if (input == "empty")
			cout << dq.empty() << '\n';
		else if (input == "front"){
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.front() << '\n';
		} else if (input == "back"){
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.back() << '\n';
		}
	}
}