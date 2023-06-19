// 골드4
// Created by KangMinji on 2023-06-17.
// https://www.acmicpc.net/problem/17298

#include <iostream>
#include <stack>
using namespace std;

int arr[1000001]; // 숫자
int ans[1000001]; // 정답

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	stack<int> st;

	// 입력
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];

	for (int i=n-1; i>=0; i--){
		while(!st.empty() && st.top() <= arr[i])
			st.pop();

		if (st.empty())
			ans[i] = -1;
		else
			ans[i] = st.top();
		st.push(arr[i]);
	}

	for (int i=0; i<n; i++){
		cout << ans[i] << ' ';
	}
}