// 골드5
// Created by KangMinji on 2023-06-23.
// https://www.acmicpc.net/problem/13549

#include <iostream>
#include <deque>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
const int MAX = 2*1e5 + 1;

int dist[MAX];
int n, k;

void bfs(){
	deque<int> dq;

	dq.push_back(n);
	dist[n] = 0;

	while(!dq.empty()){
		int x = dq.front();
		dq.pop_front();

		if (x == k){
			cout << dist[x];
			return;
		}

		for (int nx : {x-1, x+1, 2*x}){
			if (nx < 0 || nx >= MAX || dist[nx] != -1) continue;
			if (nx == 2*x) {
				dist[nx] = dist[x];
				dq.push_front(nx);
			}
			else {
				dist[nx] = dist[x] + 1;
				dq.push_back(nx);
			}
		}
	}
}

int main() {
	cin >> n >> k;

	fill(dist, dist+MAX, -1);

	bfs();
}