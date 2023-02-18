//
// Created by KangMinji on 2023-02-18.
// sort : 중간목표1 + 세부목표1-1처럼 문자열을 결합시켜 하나의 문자열로 만들고 정렬 / <중간목표1, 세부목표1> pair를 만들어 정렬

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string board[10][10];
map<string, vector<string>> goal_list;

bool cmp(const string &a, const string &b) {
	if (a.length() != b.length()) {
		bool is_equal = true;
		for (int i = 0; i < min(a.length(), b.length()); i++) {
			if (a[i] != b[i]) {
				is_equal = false;
				break;
			}
		}
		if (is_equal) {
			return a.length() < b.length();
		}
	}
	return a < b;
}

void fillGoal(int x, int y) {
	string mid_goal = board[x * 3 + 1][y * 3 + 1];

	vector<string> goals;
	for (int i = x * 3; i < x * 3 + 3; i++) {
		for (int j = y * 3; j < y * 3 + 3; j++) {
			// 중간 목표인 경우
			if (i == x * 3 + 1 && j == y * 3 + 1) {
				continue;
			}
			goals.push_back(board[i][j]);
		}
	}

	sort(goals.begin(), goals.end(), cmp);
	goal_list[mid_goal] = goals;
}

int main() {

	// 입력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
		}
	}

	// 연산
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// 최종 & 중간 목표 pass
			if (i == 1 && j == 1) {
				continue;
			}
			fillGoal(i, j);
		}
	}

	// 출력
	int idx = 1;
	for (auto iter: goal_list) {
		cout << "#" << idx << ". " << iter.first << "\n";
		for (int i = 1; i < 9; i++) {
			cout << "#" << idx << "-" << i << ". " << iter.second[i - 1] << "\n";
		}
		idx++;
	}
}