// 실버1 / BFS
// Created by KangMinji on 2023-02-13.
// https://www.acmicpc.net/problem/1325

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 10001;
typedef pair<int, int> ci;

vector<int> adj[MAX];
bool visited[MAX];
vector<ci> ans;
int max_cnt = 0;

int bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;

	int cnt = 1;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for (int next : adj[cur]){
			if (!visited[next]){
				q.push(next);
				visited[next] = true;
				cnt++;
			}
		}
	}
	ans.push_back({start, cnt});
	return cnt;
}

int main() {
	int n, m, a, b;

	// 입력
	cin >> n >> m;
	while(m--){
		cin >> a >> b;
		// a가 b를 신뢰하면 b 해킹 -> a 해킹 가능
		adj[b].push_back(a);
	}

	// 연산
	for (int i=1; i<=n; i++){
		fill(visited, visited + MAX, 0);
		max_cnt = max(max_cnt, bfs(i));
	}

	// 출력
	for (ci result : ans){
		if (result.second == max_cnt) {
			cout << result.first << ' ';
		}
	}
}