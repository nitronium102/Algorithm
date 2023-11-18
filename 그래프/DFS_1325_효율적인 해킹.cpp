// 실버1 / DFS
// Created by KangMinji on 2023-02-13.
// https://www.acmicpc.net/problem/1325

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;
const int MAX = 10001;

vector<int> adj[MAX];
bool visited[MAX];
vector<ci> ans;
int max_cnt = 0;
int cnt;

void dfs(int start) {
	visited[start] = true;
	cnt++;

	for (int next: adj[start]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	int n, m, a, b;

	// 입력
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		// a가 b를 신뢰하면 b 해킹 -> a 해킹 가능
		adj[b].push_back(a);
	}

	// 연산
	for (int i = 1; i <= n; i++) {
		fill(visited, visited + MAX, 0);
		cnt = 0;
		dfs(i);
		max_cnt = max(max_cnt, cnt);
		ans.push_back({cnt, i});
	}

	// 출력
	for (ci result: ans) {
		if (result.first == max_cnt) {
			cout << result.second << ' ';
		}
	}
}