// 골드4
// Created by KangMinji on 2023-03-07.
// https://www.acmicpc.net/problem/17281

#include <iostream>
#include <vector>

using namespace std;

/*
 * 한 이닝에 3아웃 발생하면 이닝 종료 & 공수 변경
 * 타순은 이닝이 변경되어도 순서 유지
 *
 * 공격은 1, 2, 3, 홈 -> 1점
 * 이닝 시작 시에 주자 없음
 */

vector<int> order(10, 0);
vector<bool> visited(10, false);

int hit(vector<bool> &state, int result) {
	int score = 0;
	// 1) 타자를 제외한 주자들의 위치 변경(3루, 2루, 1루)
	for (int i = 3; i > 0; i--) {
		if (!state[i]) {
			continue;
		}
		// 현재 자리는 공석
		state[i] = false;

		// 다음 자리 결정
		if (i + result >= 4) { // 홈으로 들어오는 경우
			score++;
		} else {
			state[i + result] = true;
		}
	}

	// 2) 타자의 위치 결정
	if (result == 4){ // 홈런을 친 경우
		return score + 1; // 타자도 홈에 들어온다
	}

	state[result] = true; // 타자 이동
	return score;
}

// 점수 계산
int calcScore(vector<vector<int>> &ball, int n) {
	int score = 0;
	vector<bool> state; // 각 루의 수

	int i = 1; // 순서
	for (int cur = 0; cur < n; cur++) {
		state.assign(4, false); // 출루 리셋
		int out = 0;

		while (out < 3) {
			int player = order[i];
			i = i % 9 + 1;

			// 1) 아웃인 경우
			if (ball[cur][player] == 0) {
				out++;
				continue;
			}
			// 2) 공을 친 경우
			score += hit(state, ball[cur][player]);
		}
	}
	return score;
}

// 타순 정하기
void playGame(int cnt, int n, vector<vector<int>> &ball, int &max_score) {
	if (cnt == 4) { // 4번 타자는 이미 순서 정해짐
		playGame(cnt + 1, n, ball, max_score);
		return;
	}

	if (cnt == 10) {
		int score = calcScore(ball, n);
		max_score = max(max_score, score);
		return;
	}
	for (int i = 2; i <= 9; i++) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		order[cnt] = i;
		playGame(cnt + 1, n, ball, max_score);
		visited[i] = false;
	}
}

int main() {
	int n;

	// 입력
	cin >> n;
	vector<vector<int>> ball(n, vector<int>(10, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> ball[i][j];
		}
	}

	order[4] = 1;
	visited[1] = true;

	// 연산
	int max_score = 0;
	playGame(1, n, ball, max_score);

	// 출력
	cout << max_score;
}