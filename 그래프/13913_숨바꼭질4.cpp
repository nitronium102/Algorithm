// 골드4
// Created by KangMinji on 2023-06-25.
// https://www.acmicpc.net/problem/13913

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1e5 + 1;

int time[2*MAX];
int parent[2*MAX];
vector<int> path;

void bfs(int start, int target){
	queue<int> q;

	time[start] = 1;
	parent[start] = start;
	q.push(start);

	while(!q.empty()){
		int x = q.front();
		q.pop();

		if (x == target) {
			int idx = x;
			while(x != start){
				path.push_back(x);
				x = parent[x];
			}
			path.push_back(start);
			return;
		}

		for (int nx : {x-1, x+1, 2*x}){
			if (nx < 0 || nx >= MAX) continue;
			if (time[nx]) continue;
			time[nx] = time[x] + 1;
			parent[nx] = x;
			q.push(nx);
		}
	}
}

int main() {
	int n, k;

	cin >> n >> k;

	bfs(n, k);

	cout << time[k] - 1 << '\n';
	for (int i=path.size()-1; i>=0; i--)
		cout << path[i] << ' ';
	cout << '\n';
}