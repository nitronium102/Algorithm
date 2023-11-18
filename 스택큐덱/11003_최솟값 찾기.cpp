// 플레5
// Created by KangMinji on 2023-06-18.
// https://www.acmicpc.net/problem/11003

#include <iostream>
#include <deque>
using namespace std;
typedef pair<int, int> ci;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, num;
	deque<ci> dq;

	// 입력
	cin >> n >> m;

	// 연산
	for (int i=0; i<n; i++){
		cin >> num;

		// 새로운 숫자가 deque 내에서 가장 큰 값이 되도록 하기
		// 앞에 있는 큰 놈들 제거
		while(!dq.empty() && dq.back().second >= num)
			dq.pop_back();

		// 새로운 숫자는 항상 삽입
		dq.push_back({i, num});

		// outdated된 숫자 제거
		if (dq.front().first <= i-m)
			dq.pop_front();

		cout << dq.front().second << ' ';
	}
}
