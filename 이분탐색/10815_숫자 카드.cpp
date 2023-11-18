// 실버5 / 이분 탐색
// Created by KangMinji on 2023-02-06.
// https://www.acmicpc.net/problem/10815

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> card;

int checkHave(long long num) {
	long long left, right, mid;
	left = 0;
	right = card.size() - 1;

	while (left <= right) {
		mid = (left + right) / 2;

		if (card[mid] > num) {
			right = mid - 1;
		} else if (card[mid] < num) {
			left = mid + 1;
		} else { // 카드를 가지고 있는 경우
			return 1;
		}
	}
	// 카드가 없는 경우
	return 0;
}

int main() {
	int n, m;

	// 입력
	cin >> n;
	card.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card.begin(), card.end());

	cin >> m;
	vector<int> check(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> check[i];
	}

	for (int i=0; i<m; i++){
		cout << checkHave(check[i]) << " ";
	}
}