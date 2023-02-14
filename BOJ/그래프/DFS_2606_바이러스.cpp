// 실버2 / 그래프
// Created by KangMinji on 2023-02-12.
// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[101];
bool visited[101];
int ans = 0;

void dfs(int cur) {
	visited[cur] = true;
	ans++;
	for (int next : adj[cur]){
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	int n, cnt, a, b;

	// 입력
	cin >> n >> cnt;
	while(cnt--){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// 연산
	dfs(1);

	// 출력 (1번을 통해 걸리는 수 -> 1번은 제외)
	cout << ans - 1 << "\n"; // dfs
}