// 골드5
// Created by KangMinji on 2023-04-06.
// https://www.acmicpc.net/problem/9084

#include <iostream>
#include <vector>

using namespace std;

int makeMoney(int n, vector<int> &coin, int target) {
	vector<int> dp(target + 1, 0);

	// 초기화
	dp[0] = 1;
	for (int i = 0; i < n; i++) { // 각 동전을 사용하는 경우
		for (int j = coin[i]; j <= target; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	return dp[target];
}

int main() {
	int t, n, target;

	cin >> t;
	while (t--) {
		// 입력
		cin >> n;
		vector<int> coin(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> coin[i];
		}
		cin >> target;

		// 연산
		cout << makeMoney(n, coin, target) << "\n";
	}
}