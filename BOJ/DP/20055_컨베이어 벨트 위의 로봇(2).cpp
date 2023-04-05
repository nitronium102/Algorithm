// 골드5
// Created by KangMinji on 2023-04-05.
// https://www.acmicpc.net/problem/20055

#include <iostream>
#include <deque>

using namespace std;

struct info {
	int power;
	bool is_on;
};

void rotate(int n, deque<info> &belt) {
	belt.push_front(belt.back());
	belt.pop_back();

	// n번째 칸 로봇 내리기
	if (belt[n - 1].is_on) {
		belt[n - 1].is_on = false;
	}
}

void move(int n, deque<info> &belt) {
	int cur = n * 2 - 1;
	int next;

	while(cur--){
		next = (cur + 1) % (2 * n);
		if (belt[cur].is_on && !belt[next].is_on && belt[next].power >= 1){
			belt[cur].is_on = false;
			belt[next].power--;
			belt[next].is_on = true;
		}
	}

	// n번째 칸 로봇 내리기
	if (belt[n-1].is_on){
		belt[n-1].is_on = false;
	}
}

void put_robot(deque<info> &belt){
	if (belt[0].power){
		belt[0].power--;
		belt[0].is_on = true;
	}
}

int countPowerZero(int n, deque<info> &belt){
	int cnt = 0;

	for (int i=0; i<2*n; i++){
		if (!belt[i].power){
			cnt++;
		}
	}

	return cnt;
}

int main() {
	int n, k;

	// 입력
	cin >> n >> k;
	deque<info> belt(2 * n, {0, 0});

	for (int i = 0; i < 2 * n; i++) {
		cin >> belt[i].power;
	}

	// 연산
	int step = 0;
	while (true) {
		rotate(n, belt);
		move(n, belt);
		put_robot(belt);

		step++;
		if (countPowerZero(n, belt) >= k) {
			break;
		}
	}

	// 출력
	cout << step << "\n";
}