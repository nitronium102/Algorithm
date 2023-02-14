// 실버2 / BFS
// Created by KangMinji on 2023-02-13.
// https://www.acmicpc.net/problem/24444

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100001;
typedef pair<int, int> ci;

vector<int> adj[MAX];
bool visited[MAX];
int order[MAX];

void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;

	int cnt = 1;
	order[start] = 1;

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for (int next : adj[cur]){
			if (!visited[next]){
				q.push(next);
				visited[next] = true;

				order[next] = ++cnt;
			}
		}
	}
}

int main() {
	int n, m, r, u, v;

	// 입력
	cin >> n >> m >> r;
	for (int i=0; i<m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i=1; i<=n; i++){
		sort(adj[i].begin(), adj[i].end());
	}

	// 연산
	bfs(r);

	// 출력
	for (int i=1; i<=n; i++){
		cout << order[i] << "\n";
	}
}