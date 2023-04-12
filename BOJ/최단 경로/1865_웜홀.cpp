// 골드3
// Created by KangMinji on 2023-03-02.
// https://www.acmicpc.net/problem/1865

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef pair<int, int> ci;
typedef tuple<int, int, int> tp;

bool bellmanFord(int n, vector<tp> &graph){
	vector<int> dist(n+1, 0);

	for (int i=1; i<=n; i++){ // 갱신 횟수
		bool flag = true;
		for (int j=0; j<graph.size(); j++){
			int s = get<0>(graph[j]);
			int d = get<1>(graph[j]);
			int w = get<2>(graph[j]);

			int next_weight = dist[s] + w;

			if (next_weight < dist[d]){
				if (i == n){ // 음의 사이클 발생
					return false;
				}
				dist[d] = next_weight;
				flag = false;
			}
		}
		if (flag){
			break;
		}
	}
	return true;
}

/*
 * 1) 벨만 포드는 출발점 하나만 파악 -> 특정 정점 하나만 파악하면 단절된 음의 사이클 파악 X
 * 2) 초깃값을 INF로 설정하는 이유는 단절된 경로는 배제시키기 위해
 * 하지만 단순 그래프에서 사이클 유무만 파악할 때는 dist 초기화를 어떤 값으로 해도 상관 X
 * 거리를 구하는 것이 목적이 아니라 음의 사이클 유무만 판별해도 되기 때문!
 */
int main() {
	int tc, n, m, w, s, e, t;

	// 입력
	cin >> tc;
	while(tc--){
		cin >> n >> m >> w;
		vector<tp> graph;

		// 무방향 도로 입력
		while(m--){
			cin >> s >> e >> t;
			graph.push_back({s, e, t});
			graph.push_back({e, s, t});
		}

		// 단방향 간선 입력
		while(w--){
			cin >> s >> e >> t;
			graph.push_back({s, e, -t});
		}

		if (bellmanFord(n, graph)){
			cout << "NO\n";
		} else { // 음의 사이클 발생
			cout << "YES\n";
		}
	}
}