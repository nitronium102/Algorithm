// 실버4
// Created by KangMinji on 2023-03-31.
// https://www.acmicpc.net/problem/19636

#include <iostream>
#include <cmath>

using namespace std;

// 체중 before_w, 섭취향 before_e, 기초 대사량 before_e, 활동 대사량 a0 = 0
// 다이어트 기간 : 섭취량 diet_e, 활동 대사량 a
// 체중 += (l - (l0 + a))
// abs(l - (l0 + a)) > t -> l0 += floor((l - (l0 + a))/2)
int main() {
	int before_w, before_e, t, d, energy, a;

	// 입력
	cin >> before_w >> before_e >> t >> d >> energy >> a;

	// 연산
	// 1) 일일 기초 대사량의 변화 고려 X
	int weight = before_w + (energy - (before_e + a)) * d;
	if (weight <= 0) {
		cout << "Danger Diet\n";
	} else {
		cout << weight << " " << before_e << "\n";
	}

	// 2) 일일 기초 대사량 변화 고려 O
	int diet_weight = before_w;
	int diet_energy = before_e;
	bool is_die = false;
	while (d--) {
		int energy_out = diet_energy + a;
		diet_weight += (energy - energy_out);
		if (abs(energy - energy_out) > t) {
			// c++에서 음수를 나누면 소수점은 그냥 버려지므로 내림함수 적용
			diet_energy += floor((double) (energy - energy_out) / 2);
		}
		if (diet_weight <= 0 || diet_energy <= 0) {
			is_die = true;
			break;
		}
	}

	// 출력
	if (is_die) {
		cout << "Danger Diet\n";
	} else {
		cout << diet_weight << " " << diet_energy << " ";
		if (before_e > diet_energy) {
			cout << "YOYO\n";
		} else {
			cout << "NO\n";
		}
	}
}