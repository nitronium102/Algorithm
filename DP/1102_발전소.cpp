// 플레5
// Created by KangMinji on 2023-08-09.
// https://www.acmicpc.net/problem/1102

#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e9;

int n, p;
string state;
int cost[16][16];
int dp[16][1 << 16]; // n개 발전소가 켜져 있고, n개 중에 on/off된 발전소의 상태가 되기 위한 최소 비용

int dfs(int cnt, int bit) {
	// 발전소 수리가 더 이상 필요 없는 경우
	if (cnt >= p) {
		return 0;
	}
	// 최소 비요잉 한 번이라도 업데이트 된 경우
	if (dp[cnt][bit] != MAX) {
		return dp[cnt][bit];
	}
	for (int i = 0; i < n; i++) {
		// 발전소가 꺼져 있는 부분 패스
		if ((bit & (1 << i)) != 0) {

			for (int j = 0; j < n; j++) {
				// 같은 번호의 발전소거나 이미 켜져있는 발전소인 경우 패스
				if (i == j || (bit & (1 << j)) != 0) {
					continue;
				}
				// 해당 발전소를 고치는 경우 + 고치는 비용
				dp[cnt][bit] = min(dp[cnt][bit], dfs(cnt + 1, (bit | (1 << j))) + cost[i][j]);
			}
		}
	}
	return dp[cnt][bit];
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n; // 16보다 작거나 같은 자연수 -> 비트마스킹 사용 가능!!

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}

		for (int j=0; j<(1<<n); j++){
			dp[i][j] = MAX; // 최소 비용 비교를 위한 DP 배열
		}
	}

	cin >> state >> p;

	// 발전기의 상태를 비트마스킹 활용해서 저장
	// ex) YNN : 발전기 상태 -> 001 -> 1 (1번 발전소만 on)
	// 작동하는 발전기 개수 : 1
	// OR 연산을 통해 i번째 해당하는 발전소를 ON
	int cnt = 0; // on인 발전기 개수
	int bit = 0;
	for (int i = 0; i < n; i++) {
		if (state[i] == 'Y') {
			bit = bit | (1 << i);
			cnt++;
		}
	}

	// 연산
	// 작동하는 발전기 개수 >= P일 때까지 재귀호출 탐색을 반복
	// 첫 번째 루프에서 동작중인 발전소를 먼저 탐색 -> 동작 안 하면 스킵
	// 고장난 발전소가 아니면 스킵 (on할 필요가 없다)
	int answer = dfs(cnt, bit);
	cout << (answer == MAX ? -1 : answer);
}