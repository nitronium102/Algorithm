// 골드2
// Created by KangMinji on 2023-06-07.
// https://www.acmicpc.net/problem/4195

#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int MAX = 1e5 * 2 + 1;

vector<int> parent;

int findParent(int node){
	if (parent[node] < 0){
		return node;
	}
	return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y){
	int px = findParent(x);
	int py = findParent(y);

	if (px == py){
		return;
	}
	if (parent[px] < parent[py]){
		parent[px] += parent[py];
		parent[py] = px;
	} else {
		parent[py] += parent[px];
		parent[px] = py;
	}
}

int main() {
	// 시간 초과
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, f;
	string s1, s2;

	// 입력
	cin >> t;
	while(t--){
		// 초기화
		int idx = 1;
		parent.assign(MAX+1, -1);
		map<string, int> people;

		cin >> f;
		while(f--){
			cin >> s1 >> s2;
			if (!people[s1]){
				people[s1] = idx++;
			}
			if (!people[s2]){
				people[s2] = idx++;
			}
			// 연산
			unionInput(people[s1], people[s2]);

			// 출력
			// weighted union find : 음수값인 경우
			// 해당 정점이 루트 정점 & 저장된 값의 절댓값이 집합의 크기
			int root = findParent(people[s1]);
			cout << -parent[root] << '\n';
		}
	}
}