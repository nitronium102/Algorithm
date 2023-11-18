// 실버3
// Created by KangMinji on 2023-03-29.
// https://www.acmicpc.net/problem/1063

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

ci findNextCoord(string move, ci king) {
	ci next_king = king;
	if (move == "R") {
		next_king.first++;
	} else if (move == "L") {
		next_king.first--;
	} else if (move == "B") {
		next_king.second--;
	} else if (move == "T") {
		next_king.second++;
	} else if (move == "RT") {
		next_king.first++;
		next_king.second++;
	} else if (move == "LT") {
		next_king.first--;
		next_king.second++;
	} else if (move == "RB") {
		next_king.first++;
		next_king.second--;
	} else {
		next_king.first--;
		next_king.second--;
	}
	return next_king;
}

bool inRange(ci next){
	int x = next.first;
	int y = next.second;
	if (x <= 0 || y <= 0 || x > 8 || y > 8){
		return false;
	}
	return true;
}

void makeMove(string move, ci &king, ci &stone) {
	ci next_king = findNextCoord(move, king);
	// 1) 범위에서 벗어난 경우
	if (!inRange(next_king)){
		return;
	}
	// 2) 돌과 같은 경우 -> 돌 이동
	if (stone == next_king){
		ci next_stone = findNextCoord(move, stone);
		// 2-1) 돌이 범위에서 벗어난 경우
		if (!inRange(next_stone)){
			return;
		}
		stone = next_stone;
	}
	king = next_king;
}

int main() {
	string k, st, move;
	int n;

	// 입력
	cin >> k >> st >> n;
	ci king = {k[0] - 'A' + 1, k[1] - '0'};
	ci stone = {st[0] - 'A' + 1, st[1] - '0'};

	// 연산
	while (n--) {
		cin >> move;
		makeMove(move, king, stone);
	}

	// 출력
	cout << char(king.first + 'A' - 1) << king.second <<'\n';
	cout << char(stone.first + 'A' - 1) << stone.second;
}