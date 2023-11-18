// 골드4
// Created by KangMinji on 2023-02-27.
// https://www.acmicpc.net/problem/1753

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
const int INF = 2e5;

vector<int> dijkstra(int start, int v, vector<vector<ci>> &graph){

	vector<int> dist(v+1, INF);
	priority_queue<ci, vector<ci>, greater<>> pq;

	// 시작 정점 초기화
	dist[start] = 0;
	pq.push({0, start});

	while(!pq.empty()){
		int n = pq.top().second;
		int w = pq.top().first;
		pq.pop();

		if (dist[n] < w){
			continue;
		}

		for (int i=0; i<graph[n].size(); i++){
			int next_node = graph[n][i].first;
			int next_weight = w + graph[n][i].second;

			if (dist[next_node] > next_weight){
				dist[next_node] = next_weight;
				pq.push({next_weight, next_node});
			}
		}
	}
	return dist;
}

int main() {
	int v, e, start, a, b, w;

	// 입력
	cin >> v >> e >> start;
	vector<vector<ci>> graph(v+1, vector<ci>());
	while(e--){
		cin >> a >> b >> w;
		graph[a].push_back({b, w});
	}

	// 연산
	vector<int> dist = dijkstra(start, v, graph);

	// 출력
	for (int i=1; i<dist.size(); i++){
		if (dist[i] == INF){
			cout << "INF\n";
		} else {
			cout << dist[i] << "\n";
		}
	}
}