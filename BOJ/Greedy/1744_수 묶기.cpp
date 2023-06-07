// 골드4
// Created by KangMinji on 2023-06-07.
// https://www.acmicpc.net/problem/1744

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pos, neg;
bool zero_flag = false;
int answer = 0;

void greedy() {
	sort(pos.begin(), pos.end(), greater<>());
	sort(neg.begin(), neg.end());

	// 양수 묶음 계산
	for (int i = 0; i < (int)pos.size() - 1; i += 2) {
		answer += pos[i] * pos[i + 1];
	}

	if (pos.size() % 2 == 1) {
		answer += pos.back();
	}

	// 음수 묶음 계산
	// 벡터의 size메소드는 unsigend long long 타입입니다
	// 따라서 0일때 -1을 하면 언더플로우가 나게 되고 unsigend long long이 가질수 있는 최댓값 즉 2^64 - 1이 나오게 됩니다
	for (int j = 0; j < (int)neg.size() - 1; j += 2) {
		answer += neg[j] * neg[j + 1];
	}

	if (neg.size() % 2 == 1) {
		if (!zero_flag) {
			answer += neg.back();
		}
	}
}

int main() {
	int n, num;

	// 입력
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 1) {
			answer++;
		} else if (num == 0) {
			zero_flag = true;
		} else if (num > 0) {
			pos.push_back(num);
		} else {
			neg.push_back(num);
		}
	}

	// 연산
	greedy();

	// 출력
	cout << answer << '\n';
}