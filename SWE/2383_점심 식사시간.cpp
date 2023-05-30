//
// Created by KangMinji on 2023-04-03.
// https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AV6kld8aisgDFASb&contestProbId=AV5-BEE6AK0DFAVl&probBoxId=AV732SG66sEDFAW7&type=PROBLEM&problemBoxTitle=%EC%82%BC%EC%84%B1+%EC%8B%A0%EC%9E%85+%EB%AA%A8%EC%9D%98+sw+%EC%97%AD%EB%9F%89%ED%85%8C%EC%8A%A4%ED%8A%B8+%EB%AC%B8%EC%A0%9C%EB%AA%A8%EC%9D%8C&problemBoxCnt=10

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
typedef pair<int, ci> pi;
const int MAX = 20 * 10 * 10 * 3;

int answer = MAX;
vector<ci> people;
vector<pi> stair;
vector<vector<int>> board;
queue<pi>

void dfs(int cnt) {
	if (cnt == people.size()) {
		downStair();
		return;
	}
	for (int i = 0; i < 2; i++) {
		int time = abs(people[cnt].first - stair[i].second.first)
				   + abs(people[cnt].second - stair[i].second.second)
				   + stair[i].first + 1; // 1분 후 계단 이용 시작
		dfs(cnt + 1);
	}
}

int main() {
	int t, n;

	cin >> t;
	while (t--) {
		// 초기화
		people.clear();
		stair.clear();

		// 입력
		cin >> n;
		board.assign(n, vector<int>());
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];

				if (board[i][j] == 1) {
					people.push_back({i, j});
				} else if (board[i][j] >= 2) {
					stair.push_back({board[i][j], {i, j}});
				}
			}
		}

		// 연산
		answer = MAX;
		dfs(0);

	}
}