// 플레5
// Created by KangMinji on 2023-08-15.
// https://www.acmicpc.net/problem/3955

#include <iostream>
#include <cmath>
using namespace std;

struct EGResult {
	long long s;
	long long t;
	long long r;

	EGResult(long long s, long long t, long long r) : s(s), t(t), r(r) {}
};

int n;
long long A, B;

EGResult calcGcd(long long a, long long b) {
	// s, t, r
	long long s0 = 1, t0 = 0, r0 = a;
	long long s1 = 0, t1 = 1, r1 = b;

	long long tmp;
	while (r1 != 0) { // r1이 0되면 r0이 gcd됨
		long long q = r0 / r1; // 몫

		// 유클리드 호제법
		tmp = r0 - q * r1; // 나머지
		r0 = r1;
		r1 = tmp;

		tmp = s0 - q * s1;
		s0 = s1;
		s1 = tmp;

		tmp = t0 - q * t1;
		t0 = t1;
		t1 = tmp;
	}

	// r0가 gcd고 s0, t0이 확장 유클리드 호제법의 해
	return EGResult(s0, t0, r0);
}

int main() {
	// x : 인당 나눠줄 사탕의 수
	// y : 사탕 봉지의 수
	// A*x + 1 = B*y

	// -Ax + By = 1
	// A(-x) + By = 1 음수처리, x범위가 반대가 된다

	// D = gcd(A, B)
	// 베주의 항등식 : Ax + By = C일 때 C % D == 0 이어야만 해를 가질 수 있다

	cin >> n;

	for (int i=0; i<n; i++){
		cin >> A >> B;

		EGResult result = calcGcd(A, B); // 확장된 유클리드 호제법을 사용하여 베주 항등식의 해를 찾음

		if (result.r != 1) { // 베주 항등식의 값을 만족하는 해가 없는 경우
			cout << "IMPOSSIBLE\n";
		} else {
			// 베주 항등식의 해 중 하나
			// x0 = s * C/D
			// y0 = t * C/D
			long long x0 = result.s;
			long long y0 = result.t;

			// x, y의 범위를 계산하여 각각의 범위에서의 k값을 구함
			// 해당 해가 범위 안에 들어오는지 확인
			// 일반해의 공식
			// x = x0 + B/D * k
			// y = y0 - A / D * k

			// x < 0
			// x0 + B/1 * k < 0
			// => k < -x0 / B

			// 0 < y <= 1e9
			// 0 < y0 - A*k <= 1e9
			// -y0 < -A * k <= 1e9 - y0
			// (y0 - 1e9) / A <= k < y0 / A
			long long kFromY = (long long) ceil((double) y0 / (double) A) - 1; // y의 최소값
			long long kFromX = (long long) ceil((double) -x0 / (double) B) - 1;

			// x, y 범위의 교차점에서의 k값
			long long k = min(kFromY, kFromX);

			// y에 관한 한계 k값
			long long kLimitFromY = (long long) ceil((y0 - 1e9) / (double) A);

			if (kLimitFromY <= k) { // 범위 안에 있어 해를 찾을 수 있는 경우
				cout << y0 - A * k << '\n';
			} else { // 우측 k의 범위가 좌측 k의 범위와 일치하지 않는 경우
				cout << "IMPOSSIBLE\n";
			}
		}
	}
}