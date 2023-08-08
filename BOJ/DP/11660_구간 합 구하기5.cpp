// 실버1
// Created by KangMinji on 2023-08-08.
// https://www.acmicpc.net/problem/11660

#include <iostream>
using namespace std;

int n, m, num;

int main() {
	 // 시간
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);

	 // 입력
	 cin >> n >> m;

	 int dp[n+1][n+1];

	 // dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + arr[i][j];
	 for (int i=1; i<=n; i++) {
		 for (int j=1; j<=n; j++) {
			 cin >> num;
			 dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + num;
		 }
	 }


	 // dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
	 int x1, x2, y1, y2;
	 for (int i=0; i<m; i++){
		 cin >> x1 >> y1 >> x2 >> y2;
		 cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] << "\n";
	 }
}