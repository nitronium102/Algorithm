// 🔥 골드4 / BFS
// Created by KangMinji on 2023-02-14.
// https://www.acmicpc.net/problem/19538

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int n, vector<vector<int>> &adj, vector<int> &init){
	vector<int> time(n+1, -1);
	vector<int> res(n+1, 0);

	queue<int> q;

	// 시작점 초기화
	for (int i=0; i<init.size(); i++){
		q.push(init[i]);
		time[init[i]] = 0;
	}

	// 루머 믿기까지 남은 사람 수 초기화
	for (int i=1; i<=n; i++){
		res[i] = (adj[i].size() + 1) / 2;
	}

	while(!q.empty()){
		int cur = q.front();
		int t = time[cur];
		q.pop();

		for (int target : adj[cur]){
			// 이미 루머를 믿는다면
			if (time[target] > -1){
				continue;
			}
			res[target]--;
			// 주변인의 절반 이상이 루머를 믿는 경우
			if (!res[target]){
				q.push(target);
				time[target] = t + 1;
			}
		}
	}
	return time;
}

int main() {
	int n, m, num;

	// 입력
	cin >> n;
	vector<vector<int>> adj(n+1, vector<int>());
	for (int i=1; i<=n; i++){
		while(true){
			cin >> num;

			if (!num){
				break;
			}
			adj[i].push_back(num);
		}
	}

	cin >> m;
	vector<int> init(m, 0);
	for (int i=0; i<m; i++){
		cin >> init[i];
	}

	// 연산
	vector<int> time = bfs(n, adj, init);

	// 출력
	for (int i=1; i<=n; i++){
		cout << time[i] << ' ';
	}
}