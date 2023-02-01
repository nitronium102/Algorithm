// 실버2
// Created by KangMinji on 2023-02-01.
// https://www.acmicpc.net/problem/11501

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n;

	// 입력
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> cost(n, 0);

		for (int i=0; i<n; i++){
			cin >> cost[i];
		}

		// 뒤에서부터 돌면서 작은 경우에는 산다
		// 마지막 날에 사는 경우는 없음
		int max_cost = -1;
		long long ans = 0;
		for (int i=n-1; i>=0; i--) {
			if (max_cost < cost[i]) {
				max_cost = cost[i];
			} else {
				ans += (max_cost - cost[i]);
			}
		}

		// 출력
		cout << ans << "\n";
	}
}