// 실버2
// Created by KangMinji on 2023-02-27.
// https://www.acmicpc.net/problem/11725

#include <iostream>
#include <vector>
using namespace std;

void findParent(int root, vector<vector<int>> &graph, vector<int> &parent){
	for (int i=0; i<graph[root].size(); i++){
		int node = graph[root][i];
		if (node == parent[root]){
			continue;
		}
		parent[node] = root;
		findParent(node, graph, parent);
	}
}

int main() {
	int n, a, b;

	// 입력
	cin >> n;
	vector<vector<int>> graph(n+1, vector<int>());
	for (int i=0; i<n-1; i++){
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// 연산
	vector<int> parent(n+1, 0);
	findParent(1, graph, parent);

	// 출력
	for (int i=2; i<=n; i++){
		cout << parent[i] << '\n';
	}
}