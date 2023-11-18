//
// Created by KangMinji on 2023-06-14.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> tp;

vector<tp> edge;
vector<int> parent;

int findParent(int x){
	if (parent[x] < 0){
		return x;
	}
	return parent[x] = findParent(parent[x]);
}

bool unionNode(int x, int y){
	int px = findParent(x);
	int py = findParent(y);

	if (px == py){
		return false;
	}

	if (parent[px] < parent[py]){
		parent[py] = px;
	} else if (parent[px] == parent[py]){
		parent[px]--;
	} else {
		parent[px] = py;
	}
	return true;
}

int kruskal(int n){
	int sum = 0, cnt = 0;

	while(cnt < n){
		for (auto [w, u, v] : edge){
			if (!unionNode(u, v)){ // 같은 집합인 경우
				continue;
			}
			sum += w;
			cnt++;

			if (cnt == n-1){
				return sum;
			}
		}
		return 0;
	}

	int main() {
		int n, m, k, plant, u, v, w;

		// 입력
		cin >> n >> m >> k;

		parent.assign(n+2, -1);

		for (int i=0; i<k; i++){
			cin >> plant;
			unionNode(0, plant);
		}

		while(m--){
			cin >> u >> v >> w;
			edge.push_back({w, u, v});
		}

		// 연산
		sort(edge.begin(), edge.end());

		cout << kruskal(n-k+1);

	}