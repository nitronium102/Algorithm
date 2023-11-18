// 골드5
// Created by KangMinji on 2023-09-08.
// https://www.acmicpc.net/problem/2170

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

int n;
vector<ci> coords;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n;
	coords.assign(n, {0, 0});
	for (int i = 0; i < n; i++) {
		cin >> coords[i].first >> coords[i].second;
	}

	// 연산
	// 1) x 좌표 오름차순으로 sort
	sort(coords.begin(), coords.end());

	// 2) 탐색 시작
	int start = coords[0].first;
	int end = coords[0].second;

	long long answer = 0;
	for (int i = 1; i < n; i++) {
		int s = coords[i].first;
		int e = coords[i].second;
		// 2-1) 선분의 범위가 겹치는 경우
		if (end >= s) {
			// 2-1-1) 갱신이 필요한 경우
			if (end < e) {
				end = e;
			}
		}
			// 2-2) 선분의 범위가 겹치지 않는 경우 : 그냥 더하면 됨
		else {
			answer += end - start;
			start = s;
			end = e;
		}
	}

	answer += (end - start);

	// 출력
	cout << answer << '\n';

}