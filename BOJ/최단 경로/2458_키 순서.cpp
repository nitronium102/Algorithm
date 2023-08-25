// 골드4
// Created by KangMinji on 2023-08-25.
// https://www.acmicpc.net/problem/2458

#include <iostream>
#include <string.h>
using namespace std;
const int MAX = 501;
const int INF = 1e9;

int n, m;
bool dist[MAX][MAX];

void floyd() {
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				if (dist[i][k] && dist[k][j]){
					dist[i][j] = true;
				}
			}
		}
	}
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m;

	int a, b;
	while(m--){
		cin >> a >> b;
		dist[a][b] = true;
	}

	// 연산
	floyd();

	// 출력
	int answer = 0;
	for (int i=1; i<=n; i++){
		int cnt = 0;
		for (int j=1; j<=n; j++){
			if (dist[i][j] || dist[j][i])
				cnt++;
		}
		if (cnt == n-1) {
			answer++;
		}
	}

	cout << answer << '\n';
}
