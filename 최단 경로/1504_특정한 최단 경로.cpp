// 골드4
// Created by KangMinji on 2023-03-02.
// https://www.acmicpc.net/problem/1504

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
const int INF = 8e5 * 3; // (n-1) * e3 * 3

vector<int> dijkstra(int n, int start, vector<vector<ci>> &graph){
	vector<int> dist(n+1, INF);
	priority_queue<ci, vector<ci>, greater<>> pq;

	// 초기화
	dist[start] = 0;
	pq.push({0, start});

	while (!pq.empty()){
		int node = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		if (dist[node] < weight){
			continue;
		}

		for (ci next : graph[node]){
			int n_node = next.first;
			int n_weight = next.second + weight;
			if (dist[n_node] > n_weight){
				dist[n_node] = n_weight;
				pq.push({dist[n_node], n_node});
			}
		}
	}
	return dist;
}

int solution(int n, int v1, int v2, vector<vector<ci>> &graph){
	vector<int> start = {1, v1, v2};
	vector<vector<int>> dist(3, vector<int>());

	for (int i=0; i<3; i++) {
		dist[i] = dijkstra(n, start[i], graph);
	}

	int answer = min(dist[0][v1] + dist[1][v2] + dist[2][n],
							dist[0][v2] + dist[2][v1] + dist[1][n]);
	if (answer >= INF) {
		return -1;
	}
	return answer;
}
int main() {
	int n, e, a, b, c, v1, v2;

	// 입력
	cin >> n >> e;
	vector<vector<ci>> graph(n+1, vector<ci>());
	while(e--){
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	cin >> v1 >> v2;

	// 연산
	int answer = solution(n, v1, v2, graph);

	cout << answer << '\n';
}