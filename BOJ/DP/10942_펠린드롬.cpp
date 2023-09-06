// 골드4
// Created by KangMinji on 2023-09-06.
// https://www.acmicpc.net/problem/10942

#include <iostream>
using namespace std;
const int MAX = 2001;

int n, m, s, e;
int num[MAX];
bool dp[MAX][MAX];

bool checkIsPelinDrome(int x, int y) {

}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> num[i];

		// 1) 1자리 수는 무조건 펠린드롬
		dp[i][i] = true;

		// 2) 2자리 수인데 같은 경우 : 11, 22 ...
		if (i != 1 && num[i-1] == num[i]){
			dp[i-1][i] = true;
		}
	}

	// 3) 기타
	for (int len=2; len<=n; len++){ // 길이
		for (int j=1; len+j<=n; j++){ // 구간 시작점
			// 처음과 끝이 같고, [처음+1, 마지막-1]이 팰린드롬이라면
			if (num[j] == num[len+j] && dp[j+1][len+j-1] == 1){
				dp[j][len+j] = true;
			}
		}
	}


	cin >> m;
	while(m--){
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}
}