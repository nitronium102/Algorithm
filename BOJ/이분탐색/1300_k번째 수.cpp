// 골드2
// Created by KangMinji on 2023-02-06.
// https://www.acmicpc.net/problem/1300

#include <iostream>

using namespace std;

int main() {
	int n, k;

	// 입력
	cin >> n >> k;

	// 연산
	int left = 1, right = k;
	int mid, ans;
	while (left <= right) {
		long long cnt = 0;
		mid = (left + right) / 2;

		// 행 별로 mid보다 작은 숫자 개수 파악
		// i*j <= mid -> j <= mid/i
		// N이 1000보다 크면 mid / i 가 N보다 커질 수 있으므로 mid/i 와 N 중 작은 값을 더해 mid보다 작은 숫자의 개수를 파악
		// [참고] http://wookje.dance/2017/02/20/boj-1300-K%EB%B2%88%EC%A7%B8-%EC%88%98/
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}

		if (cnt < k) {
			left = mid + 1;
		} else {
			right = mid - 1;
			ans = mid;
		}
	}

	// 출력
	cout << ans << "\n";
}