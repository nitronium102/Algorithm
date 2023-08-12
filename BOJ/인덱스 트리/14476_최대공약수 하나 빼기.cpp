// 골드2
// Created by KangMinji on 2023-08-11.
// https://www.acmicpc.net/problem/14476

#include <bits/stdc++.h>

using namespace std;

int num[1000001];
int LtoR[1000001];
int RtoL[1000001];

// gcd(a, b) = gcd(b, a%b). a % b=0이 될 때까지
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	// 최대공약수 배열의 초기값 채우기
	LtoR[0] = num[0];
	RtoL[n - 1] = num[n - 1];

	// LtoR
	for (int i = 1; i <= n - 1; i++) {
		LtoR[i] = gcd(LtoR[i-1], num[i]);
	}

	// RtoL
	for (int i = n - 2; i >= 0; i--) {
		RtoL[i] = gcd(RtoL[i+1], num[i]);
	}

	int result = -1; // 만들 수 있는 최대 공약수
	int maxIndex = 0;

	for (int i = 0; i < n; i++) {
		int curGCD = 0;
		if (i == 0) { // 첫 번째 수 빼면 나머지 gcd는 RtoL[1]에 있음
			curGCD = RtoL[1];
		} else if (i == n - 1) { // 마지막 수면 나머지 gcd는 LtoR[n-2]에 있음
			curGCD = LtoR[n-2];
		} else {
			curGCD = gcd(LtoR[i - 1], RtoL[i + 1]);
		}

		// 1) gcd가 빠진 수의 약수가 아니어야 함
		// 2) gcd가 최대여야 함
		if (num[i] % curGCD != 0 && curGCD > result) {
			result = curGCD;
			maxIndex = i;
		}
	}

	if (result == -1) {
		cout << result;
	} else {
		cout << result << ' ' << num[maxIndex];
	}

	return 0;
}