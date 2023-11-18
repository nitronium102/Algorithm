// 골드4
// Created by KangMinji on 2023-02-27.
// https://www.acmicpc.net/problem/11404

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e7;

void floydWarshall(int n, vector<vector<int>> &graph) {
	for (int k = 1; k <= n; k++) { // 중간
		for (int i = 1; i <= n; i++) { // 출발
			for (int j = 1; j <= n; j++) { // 도착
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);;
			}
		}
	}
}

int main() {
	int n, m, a, b, c;

	// 입력
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

	// 자기 자신과의 거리 초기화
	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}

	while (m--) {
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}

	// 연산
	floydWarshall(n, graph);

	// 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (graph[i][j] == INF ? 0 : graph[i][j]) << ' ';
		}
		cout << "\n";
	}
}