// 골드5
// Created by KangMinji on 2023-03-29.
// https://www.acmicpc.net/problem/14891

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;
const int LEFT = 6;
const int RIGHT = 2;

deque<int> wheel[5];
vector<int> rotation;
/*
 * 서로 다른 극일 때만 반대방향으로 움직임(2번 & 6번)
 */
void rotate(){
	for (int i=1; i<=4; i++){
		// 시계방향
		if (rotation[i] == 1){
			wheel[i].push_front(wheel[i].back());
			wheel[i].pop_back();
		} else if (rotation[i] == -1) {
			wheel[i].push_back(wheel[i].front());
			wheel[i].pop_front();
		}
	}
	return;
}

void decideRotate(int idx, int dir){
	if (rotation[idx]){ // 이미 회전한 경우
		return;
	}
	rotation[idx] = dir;

	// 오른쪽 바퀴 회전
	if (idx < 4 && wheel[idx][RIGHT] != wheel[idx+1][LEFT]){
		decideRotate(idx+1, -dir);
	}

	// 왼쪽 바퀴 회전
	if (idx > 1 && wheel[idx][LEFT] != wheel[idx-1][RIGHT]){
		decideRotate(idx-1, -dir);
	}
}

int calcScore() {
	int answer = 0;
	int cnt = 1;
	for (int i=1; i<=4; i++){
		answer += pow(2, i-1) * wheel[i][0];
	}
	return answer;
}

int main() {
	string str;
	for (int i=1; i<=4; i++){
		cin >> str;

		for (int j=0; j<8; j++){
			wheel[i].push_back(str[j] - '0');
		}
	}

	// 연산
	int k, idx, dir;
	cin >> k;
	while(k--){
		cin >> idx >> dir;
		rotation.assign(5, 0);
		decideRotate(idx, dir);
		rotate();
	}

	// 출력
	cout << calcScore();
}