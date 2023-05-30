// 실버3
// Created by KangMinji on 2023-03-30.
// https://www.acmicpc.net/problem/8911

#include <iostream>
using namespace std;
typedef pair<int, int> ci;

int dx[4] = {0, 1, 0, -1}; // 북동남서(시계)
int dy[4] = {1, 0, -1, 0};

int calcArea(string input) {
	int dir = 0; // 북쪽

	int maxx = 0, maxy = 0, minx = 0, miny = 0; // 특정 값으로 하지 말고 0, 0으로 해야 함
	ci state = {0, 0};

	for (char c : input){
		switch(c) {
			case 'F':
				state.first += dx[dir];
				state.second += dy[dir];
				break;
			case 'B':
				state.first -= dx[dir];
				state.second -= dy[dir];
				break;
			case 'L':
				dir = (dir + 3) % 4;
				break;
			case 'R':
				dir = (dir + 1) % 4;
				break;
		}
		maxx = max(maxx, state.first);
		maxy = max(maxy, state.second);
		minx = min(minx, state.first);
		miny = min(miny, state.second);
	}

	return (maxx - minx) * (maxy - miny);
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc;
	string input;

	// 입력
	cin >> tc;
	while(tc--){
		cin >> input;

		cout << calcArea(input) << "\n";
	}
}