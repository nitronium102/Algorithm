// 실버2 / 그래프
// Created by KangMinji on 2023-02-12.
// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[101];
bool visited[101];
int ans = 0;

void bfs(int start){
	queue<int> q;

	q.push(start);
	visited[start] = true;

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for (int next : adj[cur]){
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				ans++;
			}
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
	bfs(1);

	// 출력
	cout << ans << "\n"; // bfs
}