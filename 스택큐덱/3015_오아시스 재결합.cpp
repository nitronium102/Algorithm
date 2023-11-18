// 플레5
// Created by KangMinji on 2023-06-17.
// https://www.acmicpc.net/problem/3015

#include <iostream>
#include <stack>
using namespace std;

int num[500001];

int main() {
	int n;

	// 입력
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> num[i];
	}

	// 연산
	stack<int> st;
	long long answer = 0; // n*(n-1)/2 = 25e10/2
	for (int i=n-1; i>=0; i--){
		while(!st.empty() && st.top() < num[i]){
			st.pop();
		}

		answer+=st.size();

		st.push(num[i]);
	}

	// 출력
	cout << answer << '\n';
}