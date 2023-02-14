// 실버2 / 그래프
// Created by KangMinji on 2023-02-13.
// https://www.acmicpc.net/problem/1260

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1001;

int n, m, v;
vector<int> adj[MAX];
bool visited[MAX];

void dfs(int cur){
	visited[cur] = true;
	cout << cur << ' ';

	for (int next : adj[cur]){
		if (!visited[next]) {
			dfs(next);
		}
	}
}

void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		cout << cur << ' ';

		for (int next : adj[cur]){
			if (!visited[next]){
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main() {
	// 입력
	cin >> n >> m >> v;
	int a, b;
	while(m--){
		cin >> a >> b;
		// 양방향
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i=1; i<=n; i++){
		sort(adj[i].begin(), adj[i].end());
	}

	// 연산
	dfs(v);
	cout << "\n";
	fill_n(visited, MAX, false);
	bfs(v);

}