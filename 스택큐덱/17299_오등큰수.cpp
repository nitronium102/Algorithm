// 골드3
// Created by KangMinji on 2023-03-03.
// https://www.acmicpc.net/problem/17299

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int SIZE = 1e6 + 1;

vector<int> findNum(int n, vector<int> &cnt, vector<int> &arr){
	stack<int> st; // 오등큰수 저장
	vector<int> result(n, -1);

	for (int i=n-1; i>=0; i--){
		while(!st.empty() && cnt[arr[i]] >= cnt[st.top()]){
			st.pop();
		}

		// 오등큰수 발견
		if (!st.empty()){
			result[i] = st.top();
		}

		st.push(arr[i]);
	}
	return result;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	// 입력
	cin >> n;

	vector<int> cnt(SIZE, 0); // map은 입출력 속도가 느림
	vector<int> arr(n, 0);

	for (int i=0; i<n; i++){
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	// 연산
	vector<int> result = findNum(n, cnt, arr);

	// 출력
	for (int num : result){
		cout << num << ' ';
	}
}