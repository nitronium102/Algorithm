// 실버1
// Created by KangMinji on 2023-06-20.
// https://www.acmicpc.net/problem/5014

#include <iostream>
#include <queue>
using namespace std;

int dist[1000001];

int main() {
	int f, start, target, u, d;

	// 입력
	cin >> f >> start >> target >> u >> d;

	// 연산
	fill(dist, dist + f + 1, -1);

	queue<int> q;

	dist[start] = 0;
	q.push(start);

	while(!q.empty()){
		int x = q.front();
		q.pop();

		for (int i : {x + u, x - d}){
			if (i < 1 || i > 1000000) continue;
			if (dist[i] >= 0) continue;
			dist[i] = dist[x] + 1;
			q.push(i);
		}
	}

	// 출력
	if (dist[target] == -1) cout << "use the stairs";
	else cout << dist[target];
}