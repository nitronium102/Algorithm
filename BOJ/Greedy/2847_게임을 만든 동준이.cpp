// 실버4
// Created by KangMinji on 2023-10-09.
// https://www.acmicpc.net/problem/2847

#include <iostream>

using namespace std;

int n;
int score[101];

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}

	// 연산
	int answer = 0;
	int before = score[n-1]; // 2e4 * 1e2 = 2e6
	for (int i = n - 2; i >= 0; i--) {
		if (score[i] >= before){
			int diff = score[i] - before + 1;
			answer += diff;
			score[i] -= diff;
		}
		before = score[i];
	}

	// 출력
	cout << answer << '\n';
}