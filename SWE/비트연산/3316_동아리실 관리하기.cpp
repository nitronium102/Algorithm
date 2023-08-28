//
// Created by KangMinji on 2023-08-28.
//

#include <iostream>
#include <cstring>

using namespace std;
const int MOD = 1000000007;
const int MAX = 10005;

int T;
string input;
int dp[MAX][16]; // dp[i][mask] = i번째 날의 부원 참여 여부 ex) dp[3][1001] = 3일차에 AD만 참여

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> input;

		int n = input.length();
		memset(dp, 0, sizeof(dp));

		for (int day = 0; day < n; day++) {
			int admin = 1 << (input[day] - 'A'); // 관리자가 참여한 상태
			for (int prevmask = 1; prevmask < 16; prevmask++) {
				if (day == 0) { // 첫날에는 A가 열쇠를 가지고 있다
					// 관리자가 포함되고
					// A도 포함된다면
					if ((prevmask & admin) && (prevmask & 1)) {
						dp[day][prevmask] = 1;
					}
				} else {
					if (dp[day-1][prevmask]) {
						for (int mask = 1; mask < 16; mask++) { // 오늘의 상태
							// 전날과 오늘의 상태 중 일치하는 것이 있고
							// 오늘에 관리자가 포함된다면
							if ((prevmask & mask) && (mask & admin)) {
								dp[day][mask] += dp[day - 1][prevmask];
								dp[day][mask] %= MOD;
							}
						}
					}
				}
			}
		}

		int answer = 0;
		for (int i = 1; i < 16; i++) {
			answer += dp[n - 1][i];
			answer %= MOD;
		}

		cout << "#" << t << ' ' << answer << "\n";
	}
}