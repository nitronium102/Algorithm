// 플레5
// Created by KangMinji on 2023-08-10.
// https://www.acmicpc.net/problem/2243

#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000001;

int n, m, s;
int a, b, c;
int tree[MAX * 4]; // new int[2*s]

int query(int left, int right, int node, int target) {
	if (left == right) { // 리프노드인 경우
		return left; // right여도 상관없음
	} else {
		int mid = (left + right) / 2;
		if (tree[node * 2] >= target) { // 왼쪽으로 가는 경우
			return query(left, mid, node * 2, target);
		} else { // 오른쪽으로 가는 경우
			target -= tree[node * 2]; // 왼쪽 자식의 값을 빼줘야 함
			return query(mid + 1, right, node * 2 + 1, target);
		}
	}
}

void update(int left, int right, int node, int target, long diff) {
	if (target < left || right < target) {
		return;
	} else {
		tree[node] += diff;
		if (left != right) { // 리프노드 아닌 경우
			int mid = (left + right) / 2;
			update(left, mid, node * 2, target, diff);
			update(mid + 1, right, node * 2 + 1, target, diff);
		}
	}
	return;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
//	s = 1;
//	while (s < MAX) {
//		s *= 2;
//	}
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			int taste = query(1, MAX, 1, b);
			cout << taste << '\n';
			update(1, MAX, 1, taste, -1);
		} else {
			cin >> b >> c;
			update(1, MAX, 1, b, c);
		}
	}
}