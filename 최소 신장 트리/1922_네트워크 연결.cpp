// 골드4
// Created by KangMinji on 2023-05-23.
// https://www.acmicpc.net/problem/1922

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

int findParent(int node) {
	if (parent[node] < 0) { // 값이 음수면 루트 정점
		return node;
	}
	return parent[node] = findParent(parent[node]); // 그래프 압축
}

bool unionNode(int x, int y) {
	int px = findParent(x);
	int py = findParent(y);

	if (px == py) { // 같은 트리에 있다면
		return false;
	}

	if (parent[px] < parent[py]) { // 새로운 루트 px
		parent[px] += parent[py];
		parent[py] = px;
	} else { // 새로운 루트 py
		parent[py] += parent[px];
		parent[px] = py;
	}
	return true;
}

int kruskal(int n, vector<tp> &edge) {
	int sum = 0, cnt = 0;

	for (auto t: edge) {
		int w, u, v;
		tie(w, u, v) = t;
		if (!unionNode(u, v)) { // 같은 노드에 있는 경우
			continue;
		}
		sum += w;
		cnt++;

//		if (parent[findParent[v]] == -N) {
//			return sum;
//		}

		if (cnt == n - 1) { // 스패닝 트리 구성됨
			return sum;
		}
	}
	return 0;
}

int main() {
	int n, m, u, v, w;

	// 입력
	cin >> n >> m;

	vector<tp> edge;
	parent.assign(n + 1, -1);

	while (m--) {
		cin >> u >> v >> w;
		edge.push_back({w, u, v});
	}

	sort(edge.begin(), edge.end());

	// 연산 & 출력
	cout << kruskal(n, edge);
}