// 실버2 / BFS
// Created by KangMinji on 2023-02-13.
// https://www.acmicpc.net/problem/18352

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 3000001;

int n, m, k, x;
vector<int> adj[MAX];
int dist[MAX];

void dijkstra(int start){
	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for (int next : adj[cur]){
			if (dist[next] > dist[cur] + 1){
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	// 입력
	cin >> n >> m >> k >> x;

	int a, b;
	while(m--){
		cin >> a >> b;
		adj[a].push_back(b); // 단방향
	}

	fill_n(dist, MAX, MAX);

	// 연산
	dijkstra(x);

	// 출력
	bool flag = false;
	for (int i=1; i<=n; i++){
		if (dist[i] == k){
			cout << i << "\n";
			flag = true;
		}
	}

	if (!flag){
		cout << -1;
	}
}

//int n, m, k, x;
//vector<int> adj[MAX];
//bool visited[MAX];
//vector<int> ans;
//
//void bfs(int start){
//
//	queue<ci> q;
//	q.push({start, 0});
//	visited[start] = true;
//
//	while(!q.empty()){
//		int cur = q.front().first;
//		int cnt = q.front().second;
//		q.pop();
//
//		for (int next : adj[cur]){
//			if (!visited[next]){
//				if (cnt + 1 == k){
//					ans.push_back(next);
//				}
//				q.push({next, cnt+1});
//				visited[next] = true;
//			}
//		}
//	}
//}
//
//int main() {
//	// 입력
//	cin >> n >> m >> k >> x;
//
//	int a, b;
//	while(m--){
//		cin >> a >> b;
//		adj[a].push_back(b); // 단방향
//	}
//
//	// 연산
//	bfs(x);
//
//	// 출력
//	if (ans.size() == 0){
//		cout << -1;
//	} else {
//		sort(ans.begin(), ans.end());
//		for (int n : ans){
//			cout << n << "\n";
//		}
//	}
//}