// 골드4
// Created by KangMinji on 2023-06-07.
// https://www.acmicpc.net/problem/20040

#include <iostream>
#include <vector>
using namespace std;

bool cycle_flag = false;
vector<int> parent;

int findParent(int node){
	if (parent[node] < 0){ // 루트 정점 도달하면
		return node;
	}
	return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y){
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp){
		cycle_flag = true;
		return;
	}

	if (parent[xp] < parent[yp]){
		parent[xp] += parent[yp];
		parent[yp] = xp;
	} else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b;

	// 입력
	cin >> n >> m;
	parent.assign(n+1, -1);

	for (int i=1; i<=m; i++){
		cin >> a >> b;
		unionInput(a, b);

		if (cycle_flag){
			cout << i << '\n';
			break;
		}
	}

	if (!cycle_flag){
		cout << 0;
	}
}