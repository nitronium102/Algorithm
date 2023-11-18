// 골드4
// Created by KangMinji on 2023-02-27.
// https://www.acmicpc.net/problem/1967

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ci;

int answer = 0;
int end_idx = 0;

void traverse(int root, int sum, vector<vector<ci>> &graph, vector<bool> &visited){
	visited[root] = true;

	if (graph[root].size() == 1){
		if (answer < sum){
			answer = sum;
			end_idx = root;
		}
	}

	for (int i=0; i<graph[root].size(); i++){
		if (!visited[graph[root][i].first]){
			traverse(graph[root][i].first, sum + graph[root][i].second, graph, visited);
		}
	}
}

int main() {
	int n, p, d, w;

	// 입력
	cin >> n;
	vector<vector<ci>> graph(n+1, vector<ci>());
	vector<bool> visited(n+1, false);
	for (int i=0; i<n-1; i++){
		cin >> p >> d >> w;
		graph[p].push_back({d, w});
		graph[d].push_back({p, w});
	}

	// 연산
	traverse(1, 0, graph, visited);
	answer = 0;
	fill(visited.begin(), visited.end(), false);
	traverse(end_idx, 0, graph, visited);

	// 출력
	cout << answer << '\n';
}