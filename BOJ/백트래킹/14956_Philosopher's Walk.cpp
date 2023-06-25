// 골드3
// Created by KangMinji on 2023-06-21.
// https://www.acmicpc.net/problem/14956

#include <iostream>
using namespace std;
typedef pair<int, int> ci;

ci philo(int n, int cnt){
	if (n == 2){
		switch(cnt) {
			case 1:
				return {1, 1};
			case 2:
				return {1, 2};
			case 3:
				return {2, 2};
			case 4:
				return {2, 1};
		}
	}

	int half = n/2;
	int section = half * half;

	// https://atez.tistory.com/m/36
	if (cnt <= section) { // 좌하단 : y = x에 대칭
		ci result = philo(half, cnt);
		return {result.second, result.first};
	} else if (cnt <= 2* section) { // 좌상단
		ci result = philo(half, cnt-section);
		return {result.first, result.second + half};
	} else if (cnt <= 3*section) { // 우상단
		ci result = philo(half, cnt - 2*section);
		return {result.first + half, result.second + half};
	} else { // 우하단 : y = -x에 대칭 -> {-result.second, -result.first}
		// x좌표는 전체에서 빼주고 y좌표는 중간선 있으니까 half에서 뺴준다
		ci result = philo(half, cnt - 3*section);
		return {2 * half - result.second + 1, half - result.first + 1};
	}
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int n, cnt;
	cin >> n >> cnt;

	// 연산
	ci answer = philo(n, cnt);

	// 출력
	cout << answer.first << ' ' << answer.second;
}