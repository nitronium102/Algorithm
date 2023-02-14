// 실버2 / DFS
// Created by KangMinji on 2023-02-13.
// https://www.acmicpc.net/problem/24480

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;

vector<int> adj[MAX];
bool visited[MAX];
int cnt = 1;
int order[MAX];

void dfs(int cur){
	visited[cur] = true;
	order[cur] = cnt;

	for (int next : adj[cur]){
		if (!visited[next]){
			cnt++;
			dfs(next);
		}
	}
}

int main() {
	int n, m, r, u, v;

	// 입력
	cin >> n >> m >> r;
	for (int i=0; i<m; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i=1; i<=n; i++){
		sort(adj[i].begin(), adj[i].end(), greater<>());
	}

	// 연산
	dfs(r);

	// 출력
	for (int i=1; i<=n; i++){
		cout << order[i] << "\n";
	}
}
