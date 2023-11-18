// 실버4
// Created by KangMinji on 2023-02-13.
// https://www.acmicpc.net/problem/9372

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visited;
vector<vector<int>> flight;
int answer = 0;

void countMinFlight(int start, int n){

	visited[start] = true;
	queue<int> q;
	q.push(start);

	while(!q.empty()){
		int node = q.front();
		q.pop();
		answer++;

		for (int i=0; i<flight[node].size(); i++){
			if (!visited[flight[node][i]]){
				visited[flight[node][i]] = true;
				q.push(flight[node][i]);
			}
		}
	}
}

int main() {
	int t, n, m, a, b;

	// 입력
	cin >> t;
	while(t--){
		cin >> n >> m;

		// 초기화
		answer = 0;
		flight.assign(n+1, vector<int>());
		visited.assign(n+1, false);

		for (int i=0; i<m; i++){
			cin >> a >> b;
			flight[a].push_back(b);
			flight[b].push_back(a);
		}

		// 연산
		countMinFlight(1, n);

		// 출력
		cout << answer - 1 << '\n';
	}
}