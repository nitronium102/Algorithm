// 골드5 / 브루트포스
// Created by KangMinji on 2023-02-10.
// https://www.acmicpc.net/problem/1038

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

ll arr[1000000];
int n, idx;

void addDesc() {
	queue<ll> q;

	// 초기값
	arr[0] = 0;
	for (int i = 1; i <= 9; i++) {
		arr[i] = i;
		q.push(i);
	}

	// 2자리 이상 숫자
	idx = 10;
	while (!q.empty() && idx <= n) {
		ll num = q.front();
		q.pop();

		int last = num % 10; // 마지막 자릿수
		for (int i = 0; i < last; i++) {
			cout << idx << " " << num << " " << num*10 + i << " \n";
			q.push(num * 10 + i);
			arr[idx++] = num * 10 + i;
		}
		cout << "\n";
	}
}

int main() {
	// 입력
	cin >> n;

	// 연산
	addDesc();

	// 출력
	if (n == 0) {
		cout << 0;
	} else if (idx >= n && arr[n] != 0) {
		cout << arr[n];
	} else {
		cout << -1;
	}
}