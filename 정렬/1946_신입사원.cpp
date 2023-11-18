// 실버1
// Created by KangMinji on 2023-02-27.
// https://www.acmicpc.net/problem/1946

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

int cntEmployee(int n, vector<ci> &v){
	int answer = 0;
	int first_rank = v[0].second;

	for (int i=1; i<n; i++){
		if (first_rank > v[i].second){
			first_rank = v[i].second;
			answer++;
		}
	}
	return answer;
}

int main() {
	int t, n, s1, s2;

	// 입력
	cin >> t;
	while(t--){
		cin >> n;
		vector<ci> v(n);
		for (int i=0; i<n; i++){
			cin >> v[i].first >> v[i].second;
		}

		// 연산
		sort(v.begin(), v.end());

		int answer = cntEmployee(n, v);

		// 출력
		cout << answer << '\n';
	}
}