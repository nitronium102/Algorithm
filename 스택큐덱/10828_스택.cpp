// 실버4
// Created by KangMinji on 2023-03-03.
// https://www.acmicpc.net/problem/10828

#include <iostream>
#include <stack>
using namespace std;

int main() {
	// ㅅ간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	string order;

	// 입력
	cin >> n;

	stack<int> s;
	while(n--){
		cin >> order;
		if (order == "push"){
			cin >> x;
			s.push(x);
		} else if (order == "pop"){
			if (!s.empty()){
				cout << s.top() << '\n';
				s.pop();
			} else {
				cout << "-1\n";
			}
		} else if (order == "size"){
			cout << s.size() << '\n';
		} else if (order == "empty"){
			cout << s.empty() << '\n';
		} else if (order == "top"){
			if (!s.empty()){
				cout << s.top() << '\n';
			} else {
				cout << "-1\n";
			}
		}
	}
}