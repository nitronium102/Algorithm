// 골드5
// Created by KangMinji on 2023-06-17.
// https://www.acmicpc.net/problem/6198

#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n, h;
	stack<int> st;

	// 입력
	cin >> n;
	long long answer = 0; // n(n+!)/2 = 8e4 * 8e4 / 2 = 3,2 * e9
	while (n--) {
		cin >> h;
		while (!st.empty() && st.top() <= h) {
			st.pop();
		}
		answer += st.size();
		st.push(h);
	}

	// 출력
	cout << answer;
}