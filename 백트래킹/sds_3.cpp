//
// Created by KangMinji on 2023-07-08.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int idx=1; idx<=t; idx++){
		// 입력
		cin >> n >> m;

		// 초기화
		vector<int> coins(n, 0);
		vector<int> products(m, 0);

		int num;
		for (int i=0; i<n; i++) {
			cin >> num;
			coins[i] = num;
		}

		int max_product = 0;
		for (int i=0; i<m; i++) {
			cin >> products[i];
			max_product = max(max_product, products[i]);
		}

		vector<vector<bool>> dp(3, vector<bool>(max_product, false));
		for (int coin : coins) {
			for (int j=0; j<3; j++){
				if (coin*(j+1) <= max_product) {
					dp[j][coin*(j+1)] = true;
				}
			}
		}

		// 1) DP로 가능한 가치 모두 판별
		for (int i=coins[0]; i<=max_product; i++){
			for (int coin : coins) {
				if (i - coin < 0) continue;
				//dp[1][i] = dp[1][i] || dp[0][i-coin];
				dp[2][i] = dp[2][i] || dp[1][i-coin];
			}
		}

		// 2) 자판기 VALUE WHILE문을 돌면서 LOW와 HIGH 가치 추출
		int low = 1e9, high = -1;
		bool flag = false;
		for (int product : products) {
			if (dp[2][product]) {
				low = min(low, product);
				high = max(high, product);
				flag = true;
			}
		}

		// 출력
		cout << "#" << idx << ' ';
		if (!flag)
			cout << -1 << "\n";
		else
			cout << low << ' ' << high << "\n";
	}
}
