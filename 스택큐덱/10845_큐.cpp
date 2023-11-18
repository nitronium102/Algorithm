// 실버4
// Created by KangMinji on 2023-03-03.
// https://www.acmicpc.net/problem/10845

#include <iostream>
#include <queue>
using namespace std;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	string order;

	// 입력
	cin >> n;
	queue<int> q;
	while(n--){
		cin >> order;

		if (order == "push"){
			cin >> x;
			q.push(x);
		} else if (order == "pop"){
			if (!q.empty()){
				cout << q.front() << "\n";
				q.pop();
			} else {
				cout << "-1\n";
			}
		} else if (order == "size"){
			cout << q.size() << '\n';
		} else if (order == "empty"){
			cout << q.empty() << '\n';
		} else if (order == "front"){
			if (!q.empty()){
				cout << q.front() << "\n";
			} else {
				cout << "-1\n";
			}
		} else if (order == "back"){
			if (!q.empty()){
				cout << q.back() << "\n";
			} else {
				cout << "-1\n";
			}
		}
	}
}