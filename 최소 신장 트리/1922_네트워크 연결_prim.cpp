//
// Created by KangMinji on 2023-08-16.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
const int MAX = 1111;

int n, m;
vector<ci> arr[MAX];
bool visited[MAX];
int cnt, ans;

struct cmp {
	bool operator() (const ci &a, const ci &b) {
		return a.second > b.second;
	}
};

int main() {
	cin >> n >> m;

	int u, v, w;
	for (int i=0; i<m; i++){
		cin >> u >> v >> w;
		arr[u].push_back({v, w});
		arr[v].push_back({u, w});
	}

	priority_queue<ci, vector<ci>, cmp> pq;
	pq.push({1, 0});

	while(cnt < n) {
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (visited[cur]) continue;

		cnt++;
		ans += cost;
		visited[cur] = true;

		for (ci next : arr[cur]){
			if (visited[next]) continue;
			q.push(next);
		}
	}

	cout << ans << "\n";
}