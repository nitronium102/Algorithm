// 골드4
// Created by KangMinji on 2023-04-03.
// https://www.acmicpc.net/problem/4803

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
bool is_tree;

void dfs(int curr, int prev){
	if (visited[curr]){ // 사이클 발생
		is_tree = false;
		return;
	}
	visited[curr] = true;
	for (int next : graph[curr]){
		if (next == prev){
			continue;
		}
		dfs(next, curr);
	}
}

int main() {
	int n, m, s, e, tc = 0;

	// 입력
	while(cin >> n >> m){
		if (!n && !m){
			break;
		}
		// 초기화
		tc++;
		graph.assign(n+1, vector<int>());
		visited.assign(n+1, false);

		while (m--){
			cin >> s >> e;
			graph[s].push_back(e);
			graph[e].push_back(s);
		}

		int tree_cnt = 0;
		for (int i=1; i<=n; i++){
			if (visited[i]){
				continue;
			}
			is_tree = true;
			dfs(i, 0);
			if (is_tree){
				tree_cnt++;
			}
		}

		// 출력
		cout << "Case " << tc << ": ";
		if (tree_cnt == 0){
			cout << "No trees.\n";
		} else if (tree_cnt == 1){
			cout << "There is one tree.\n";
		} else {
			cout << "A forest of " << tree_cnt << " trees.\n";
		}
	}
}