// 골드4
// Created by KangMinji on 2023-03-02.
// https://www.acmicpc.net/problem/10282

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
const int INF = 1e7; // 간선의 개수 * 간선 가중치 최댓값 (n-1) * (1e4 * 1e7)

ci virus(int n, int start, vector<vector<ci>> &graph){
	vector<int> dist(n+1, INF);
	priority_queue<ci, vector<ci>, greater<>> pq;

	// 시작 정점 초기화
	dist[start] = 0;
	pq.push({0, start}); // {가중치, 정점}

	// 리턴값
	int cnt = 0, time = 0;

	while(!pq.empty()){
		int node = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		if (dist[node] < weight){
			continue;
		}
		cnt++;
		time = weight; // 마지막으로 감염되는 컴퓨터까지의 최단 거리(시간)

		for (ci next : graph[node]){
			int n_node = next.first;
			int n_weight = next.second + weight;
			if (dist[n_node] > n_weight){
				dist[n_node] = n_weight;
				pq.push({n_weight, n_node});
			}
		}
	}
	return {cnt, time};
}

int main() {
	int t, n, d, c, a, b, s;

	// 입력
	cin >> t;
	while(t--){
		cin >> n >> d >> c;
		vector<vector<ci>> graph(n+1, vector<ci>());
		while(d--){
			cin >> a >> b >> s;
			graph[b].push_back({a, s});
		}

		// 연산
		ci answer = virus(n, c, graph);

		// 출력
		cout << answer.first << ' ' << answer.second << '\n';

	}
}