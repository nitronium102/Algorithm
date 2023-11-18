// 실버2
// Created by KangMinji on 2023-03-29.
// https://www.acmicpc.net/problem/14620

#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> visited;
vector<vector<int>> price;
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
int answer = 2e2 * 5 * 3+ 1;

bool check(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visited[nx][ny]) {
			return false;
		}
	}
	return true;
}

void plant(int x, int y, bool flag) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		visited[nx][ny] = flag;
	}
}

void countPrice(int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) {
				sum += price[i][j];
			}
		}
	}
	answer = min(answer, sum);
}

/*
 * 서로 다른 세 씨앗 만개 & 최소 비용
 * 빌릴 때는 상하좌우중 가격으로 따져야 함
 */
void dfs(int cnt, int n) {
	if (cnt == 3) { // 가격체크
		countPrice(n);
		return;
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (check(i, j)) {
				plant(i, j, 1);
				dfs(cnt + 1, n);
				plant(i, j, 0);
			}
		}
	}
}

int main() {
	int n;

	// 입력
	cin >> n;
	price.assign(n, vector<int>(n, 0));
	visited.assign(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> price[i][j];
		}
	}

	// 연산
	dfs(0, n);

	// 출력
	cout << answer << '\n';
}