// 실버2 / 이분탐색
// Created by KangMinji on 2023-02-06.
// https://www.acmicpc.net/problem/1654

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int k, n;
vector<ll> wire;
ll ans = -1;

void findMaxLen() {
	ll left = 1;
	ll right = wire[k - 1];
	ll mid;

	while (left <= right) {
		mid = (left + right) / 2;

		long long cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += wire[i] / mid;
		}

		if (cnt < n) {
			right = mid - 1;
		} else {
			left = mid + 1;
			ans = max(ans, mid);
		}
	}
}

int main() {

	// 입력
	cin >> k >> n;
	wire.assign(k, 0);
	for (int i = 0; i < k; i++) {
		cin >> wire[i];
	}

	// 연산
	sort(wire.begin(), wire.end());
	findMaxLen();

	// 출력
	cout << ans << "\n";

}