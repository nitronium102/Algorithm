// 골드5
// Created by KangMinji on 2023-01-29.
// https://www.acmicpc.net/problem/20500

#include <iostream>
using namespace std;
typedef long long ll;
const int NUM = 1000000007;

ll dp[3][1516]; // 3으로 나눈 나머지, 자릿수

/*
 * 15의 배수
 * 1) 끝이 5로 끝나고
 * 2) 자릿수의 합이 3의 배수
 *
 * <마지막 자리가 5인 것 중> 전체 자릿수를 3으로 나눈 수를 저장
 */
void solve(int n){
	// 초기화
	dp[0][1] = 0;

	dp[0][2] = 1;
	dp[1][2] = 1;
	dp[2][2] = 0;

	// 연산
	for (int i=3; i<=n; i++){
		/*
		 * dp[0][2] = 1
		 * dp[(0+1)%3][3] = dp[1][3] = 1
		 * dp[(0+5]%3][3] = dp[2][3] = 0;
		 */
		dp[0][i] = (dp[2][i-1] + dp[1][i-1]) % NUM;
		dp[1][i] = (dp[0][i-1] + dp[2][i-1]) % NUM;
		dp[2][i] = (dp[0][i-1] + dp[1][i-1]) % NUM;
	}
}

int main() {
	int n;

	// 입력
	cin >> n;

	// 연산
	solve(n);

	// 출력
	cout << dp[0][n];
}