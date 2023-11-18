# Shortest Path
> 그래프에서 정점 사이의 최단 경로를 구하는 알고리즘

- Single Source(SSP) : 하나의 시작점에 대한 모든 정점까지의 최단 경로
  - Single Destination : 모든 정점으로부터 하나의 도착점까지의 최단 경로(SSP reverse)
  - Single Pair : 특정 정점 2개 사이의 최단 경로(SSP-sub)
- All-Pairs(ASP) : 가능한 모든 정점 2개의 조합에 대한 최단 경로

- SSP : Dijkstra, Bellman-Ford
- ASP : Floyd-Warshall

# Dijkstra
> 하나의 시작점에서 모든 정점까지의 최단 경로를 구하는 SSP (가중치 모두 양수)

- 시작 정점으로부터 가장 가까운 정점부터 탐색(Greedy)
- 가중치가 음수인 간선이 있다면, 경우에 따라 무한 루프 가능 (음의 사이클 잡아낼 수 없다)
- O(VlogV + ElogV) 
  - 모든 간선 한 번씩 검사 O(E) * 우선순위큐 삽입연산 O(logE)
  - 대개의 그래프의 경우 V^2 > E이므로 O(logE) = O(logV)

```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
const int INF = 2e5;

vector<int> dijkstra(int start, int v, vector<vector<ci>> &graph){

	vector<int> dist(v+1, INF);
	priority_queue<ci, vector<ci>, greater<>> pq; // 최소힙 {가중치, 노드}

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
```

# Bellman-Ford
> 가중치가 음수일 때 다익스트라 대신 사용할 수 있는 SSP 알고리즘
- 모든 정점을 V-1번 갱신한 후, 한 번 더 갱신을 시도하는 브루트포스
  - 정점이 V일 때 정점 A->B의 경로에는 최대 V-1개의 간선이 있을 수 있음
  - V번 이상 갱신되는 간선이 있으면 사이클 생겼다는 뜻!
- 시간 복잡도 O(VE)

# Floyd-Warshall
> ASP 알고리즘으로, DP적 접근
- 중간 정점을 기준으로 최단 거리를 구함
  - 정점 A에서 정점 B로 가는 최소 비용 VS (정점 A에서 정점 P로 가는 비용) + (정점 P에서 정점 B로 가는 비용)
- 시간 복잡도 O(V^3)

```
#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e7;

void floydWarshall(int n, vector<vector<int>> &graph) {
	for (int k = 1; k <= n; k++) { // 중간
		for (int i = 1; i <= n; i++) { // 출발
			for (int j = 1; j <= n; j++) { // 도착
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);;
			}
		}
	}
}

int main() {
	int n, m, a, b, c;

	// 입력
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

	// 자기 자신과의 거리 초기화
	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}

	while (m--) {
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}

	// 연산
	floydWarshall(n, graph);

	// 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (graph[i][j] == INF ? 0 : graph[i][j]) << ' ';
		}
		cout << "\n";
	}
}
```