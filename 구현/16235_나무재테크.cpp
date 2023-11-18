// 골드3
// Created by KangMinji on 2023-02-27.
// https://www.acmicpc.net/problem/16235

#include <iostream>
#include <vector>
#include <deque>

using namespace std;
typedef pair<int, int> ci;
typedef vector<vector<int>> matrix;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int countTrees(int n, vector<deque<int>> &trees) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum += trees[i * 10 + j].size();
		}
	}
	return sum;
}

void reproduceTree(int n, int x, int y, vector<deque<int>> &trees) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 1 && ny >= 1 && nx <= n && ny <= n) {
			trees[nx * 10 + ny].push_front(1);
		}
	}
}

void solution(int n, vector<deque<int>> &trees, matrix &food, matrix &arr, vector<ci> &breeding_tree) {
	// 봄 : 자신의 나이만큼 양분을 먹을 수 있으면 +1, 없으면 죽고 arr[x][y] += 나이/2
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int leftover = 0; // 여름용
			deque<int> dq;
			// 봄
			for (int age: trees[i * 10 + j]) {
				if (food[i][j] < age) {
					leftover += age / 2;
					continue;
				}
				food[i][j] -= age;
				dq.push_back(age + 1);

				if ((age + 1) % 5 == 0) {
					breeding_tree.push_back({i, j});
				}
			}
			// 겨울
			food[i][j] += (arr[i][j] + leftover);
			trees[i * 10 + j] = dq;
		}
	}
}

int main() {
	// n : 땅 크기, m : 나무의 초기 수, k : k년 후 살아있는 나무 구하기
	int n, m, k, x, y, z;

	// 입력
	cin >> n >> m >> k;
	matrix arr(n + 1, vector<int>(n + 1));
	matrix food(n + 1, vector<int>(n + 1, 5));
	vector<deque<int>> trees((n + 1) * 10 + (n + 1)); // 나이, 행, 열

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	while (m--) {
		cin >> x >> y >> z;
		trees[x * 10 + y].push_back(z);
	}

	// 연산
	while (k--) {
		vector<ci> breeding_tree;
		solution(n, trees, food, arr, breeding_tree);

		for (ci t: breeding_tree) {
			reproduceTree(n, t.first, t.second, trees);
		}
	}

	// 출력
	cout << countTrees(n, trees) << '\n';

}