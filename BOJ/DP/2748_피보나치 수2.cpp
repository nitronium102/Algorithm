// 브론즈1
// Created by KangMinji on 2023-01-28.
// https://www.acmicpc.net/problem/2748

#include <iostream>
using namespace std;
typedef long long ll;

ll dp[91];

ll fibo(int n) {
	if (n == 0 || n == 1) {
		return dp[n];
	}
	if (dp[n] == 0) {
		dp[n] = fibo(n - 1) + fibo(n - 2);
	}
	return dp[n];
}

int main() {
	int n;

	// 입력
	cin >> n;

	// 초기화
	dp[0] = 0;
	dp[1] = 1;

	// 연산&출력
	cout << fibo(n);

}