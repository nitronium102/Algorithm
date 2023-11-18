//
// Created by KangMinji on 2023-02-18.
// MST

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ci;

vector<bool> visited;

int main() {
	int n, m, a, b, c, d;

	// 입력
	cin >> n >> m;
	vector<vector<ci>> like(n+1, vector<ci>());
	vector<ci> couple;
	while(m--){
		cin >> a >> b >> c >> d;
		if (d == 1){
			couple.push_back({a, b});
		}
		like[a].push_back({b, c});
		like[b].push_back({a, c});
	}

	// cycle 끊기
	int answer = 0;
	for (int i=1; i<=n; i++){
		if (!visited[i]){
			dfs
		}
	}
}