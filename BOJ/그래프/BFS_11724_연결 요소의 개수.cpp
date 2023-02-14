// 실버2 / BFS
// Created by KangMinji on 2023-02-13.
// https://www.acmicpc.net/problem/11724

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[1001];
bool visited[1001];

void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for (int next : adj[cur]){
			if (!visited[next]){
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main() {
	int n, m, u, v;

	// 입력
	cin >> n >> m;
	while(m--){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i=1; i<=n; i++){
		sort(adj[i].begin(), adj[i].end());
	}

	// 연산
	int ans = 0;
	for (int i=1; i<=n; i++){
		if (!visited[i]){
			bfs(i);
			ans++;
		}
	}

	// 출력
	cout << ans << "\n";
}