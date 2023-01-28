// 실버2
// Created by KangMinji on 2023-01-28.
// https://www.acmicpc.net/problem/1182

#include <iostream>

using namespace std;

int main() {
	int N, S;
	int arr[21];

	// 입력
	cin >> N >> S;
	for (int i=0; i<N; i++){
		cin >> arr[i];
	}

	// 연산
	int ans = 0;
	int last = (1 << N); // N=4 라면 last = 10000

	for (int num = 1; num < last; num++) { // 0000부터 1111까지 순회
		int sum = 0;
		for (int idx = 0; idx <= N; idx++) {
			// 각 자리 수가 선택되었는지 확인
			if (num & (1 << idx)) {
				sum += arr[idx]; // 해당 숫자 선택
			}
		}
		if (sum == S) {
			ans++;
		}
	}
	cout << ans;
}