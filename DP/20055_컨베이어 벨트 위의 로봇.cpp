// 골드5
// Created by KangMinji on 2023-04-05.
// https://www.acmicpc.net/problem/20055

#include <iostream>
#include <vector>

using namespace std;

struct info {
	int power;
	bool is_on;
};

vector<info> belt;
int zero_cnt = 0;

int minusPosition(int n, int pos) { // 인덱스 감소
	if (--pos >= 0) {
		return pos;
	}
	return n * 2 - 1;
}

void second(int n, int start, int end){
	int cur = end;
	while(cur != start){
		cur = minusPosition(n, cur);
		int next = (cur + 1) % (n * 2); // 다음 위치
		if (belt[cur].is_on && belt[next].power >= 1 && !belt[next].is_on){
			belt[cur].is_on = false;
			belt[next].power--;
			if (next != end){ // 내리는 위치 아닌 경우
				belt[next].is_on = true;
			}
			if (belt[next].power == 0){
				zero_cnt++;
			}
		}
	}
}

void third(int start){
	if (belt[start].power){
		belt[start].power--;
		belt[start].is_on = true;
		if (belt[start].power == 0){
			zero_cnt++;
		}
	}
}

/*
 * 벨트는 시계방향으로 돌지만,
 * 우리는 로봇을 냅두고 벨트를 반시계방향으로 돌린다
 */
int main() {
	int n, k;

	// 입력
	cin >> n >> k;
	belt.assign(n * 2, {0, false});
	for (int i = 0; i < n * 2; i++) {
		cin >> belt[i].power;
	}

	// 연산
	int start = 0;
	int end = n - 1;
	int step = 0;

	while (true) {
		// 1) 벨트 회전
		start = minusPosition(n, start);
		end = minusPosition(n, end);

		// 0) 언제든지 로봇이 내리는 위치에 도달하면 그 즉시 내린다
		if (belt[end].is_on){
			belt[end].is_on = false;
		}

		// 2) 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동
		// 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상
		second(n, start,  end);

		// 3) 올리는 위치의 내구도가 1 이상이라면 로봇을 올린다
		third(start);

		step++;
		if (zero_cnt >= k){
			break;
		}
	}

	// 출력
	cout << step;
}