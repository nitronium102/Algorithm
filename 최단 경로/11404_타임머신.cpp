// 골드4
// Created by KangMinji on 2023-02-27.
// https://www.acmicpc.net/problem/11657

#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
typedef tuple<int, int, int> tp;
typedef long long ll;
const int INF = 5e6;

vector<ll> bellmanFord(int start, int n, int m, vector<tp> &edges){
	// 최솟값 갱신 과정에서 언더플로우 일어날 수 있음
	// 500 * 6000 * (-10000) = -3e10 => int 범위 넘어감!
	vector<ll> dist(n+1, INF);

	// 시작 정점 초기화
	dist[start] = 0;
	for (int i=1; i<=n; i++){
		bool flag = true; // 갱신 확인
		for (int j=0; j<m; j++){
			// s -> d인 간선의 가중치가 w
			int s = get<0>(edges[j]);
			int d = get<1>(edges[j]);
			int w = get<2>(edges[j]);

			// 아직 시작점에서 s로 가는 경로가 발견되지 않은 경우(갱신 불가)
			if (dist[s] == INF){
				continue;
			}

			ll next_weight = dist[s] + w;
			if (next_weight < dist[d]){
				if (i == n){ // n번째 갱신이었다면(음의 사이클 발생)
					return {-1};
				}
				dist[d] = next_weight;
				flag = false;
			}
		}

		if (flag){ // 갱신되지 않았다면 종료
			break;
		}
	}
	return dist;
}

int main() {
	int n, m, a, b, c;

	// 입력
	cin >> n >> m;
	vector<tp> edges(m); // 간선 정보 저장
	for (int i=0; i<m; i++){
		cin >> a >> b >> c;
		edges[i] = {a, b, c};
	}

	// 연산
	vector<ll> dist = bellmanFord(1, n, m, edges);

	// 출력
	if (dist[0] == -1){ // 음의 사이클
		cout << -1;
		return 0;
	}

	for (int i=2; i<=n; i++){
		cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
	}
}