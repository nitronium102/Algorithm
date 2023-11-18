// 실버2
// Created by KangMinji on 2023-06-17.
// https://www.acmicpc.net/problem/1874

#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, num;
	stack<int> st;

	// 입력
	cin >> n;

	int cnt = 1;
	string answer = "";
	while(n--){
		cin >> num;
		while(cnt <= num){
			st.push(cnt++);
			answer += "+\n";
		}
		if (!st.empty() && st.top() != num){
			cout << "NO";
			return 0;
		}
		st.pop();
		answer += "-\n";
	}

	// 출력
	cout << answer;
}