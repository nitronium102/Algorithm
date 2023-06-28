// 골드5
// Created by KangMinji on 2023-06-28.
// https://www.acmicpc.net/problem/15686

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

int n, m;
int board[51][51];
vector<ci> chicken;
vector<ci> house;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				house.push_back({i, j});
			if (board[i][j] == 2)
				chicken.push_back({i, j});
		}
	}

	vector<int> arr(chicken.size(), 1);
	fill(arr.begin(), arr.begin() + chicken.size() - m, 0);

	int answer = 1e9;
	do {
		// 치킨집에서 m개 골라서 치킨 거리 결정하기
		int total = 0; // 치킨 거리 합
		for (ci h : house) {
			int dist = 1e9;
			for (int i=0; i<chicken.size(); i++){
				if (arr[i] == 0) continue;
				dist = min(dist, abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second));
			}
			total += dist;
		}
		answer = min(answer, total);
	}while(next_permutation(arr.begin(), arr.end()));

	// 출력
	cout << answer;
}