// 실버1
// Created by KangMinji on 2023-02-01.
// https://www.acmicpc.net/problem/1931

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

/*
 * 1) 회의 종료 시간이 빠를수록
 * 2) 회의 종료 시간이 같아면 회의 시작 시간이 빠를수록
 */
bool cmp(const ci &a, const ci &b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main() {
	int n;

	// 입력
	cin >> n;
	vector<ci> time(n, {0, 0});

	for (int i = 0; i < n; i++) {
		cin >> time[i].first >> time[i].second;
	}

	// 연산
	sort(time.begin(), time.end(), cmp);

	int cnt = 1;
	int end = time[0].second;
	for (int i = 1; i < n; i++) {
		if (time[i].first >= end) {
			end = time[i].second;
			cnt++;
		}
	}

	// 출력
	cout << cnt << "\n";
}