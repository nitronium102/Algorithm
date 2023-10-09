// 실버4
// Created by KangMinji on 2023-10-07.
// https://www.acmicpc.net/problem/2217

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> rope;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n;
	rope.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}

	// 연산(내림차순)
	sort(rope.begin(), rope.end());

	int answer = 0;
	for (int i = 0; i < n; i++) {
		// 가장 작은 애로 따져야 함
		// 각 rope = w/k
		// 가장 중량이 낮은 rope * k = w
		answer = max(answer, rope[i] * (n - i));
	}

	// 출력
	cout << answer << "\n";
}