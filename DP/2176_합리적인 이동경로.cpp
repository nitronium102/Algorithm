// 골드2
// Created by KangMinji on 2023-07-03.
// https://www.acmicpc.net/problem/2176

#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
const int SIZE = 1001;
const int MAX = 10001;

int answer = 0;
int dp[SIZE];
int dist[SIZE];
vector<ci> graph[SIZE];

void dijkstra() {
	priority_queue<ci, vector<ci>, greater<>> pq;

	pq.push({0, 2});
	dist[2] = 0;
	dp[2] = 1;

	while(!pq.empty()){
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (int i=0; i<graph[cur].size(); i++){
			int nc = cost + graph[cur][i].first;

			if (nc < dist[graph[cur][i].second]){
				dist[graph[cur][i].second] = nc;
				pq.push({nc, graph[cur][i].second});
			}

			if (cost > dist[graph[cur][i].second])
				dp[cur] += dp[graph[cur][i].second];
		}
	}
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, u, v, w;
	fill(dist, dist + SIZE, MAX);

	// 입력
	cin >> n >> m;
	while (m--) {
		cin >> u >> v >> w;
		graph[u].push_back({w, v});
		graph[v].push_back({w, u});
	}

	// 연산
	dijkstra();

	// 출력
	cout << dp[1];
}