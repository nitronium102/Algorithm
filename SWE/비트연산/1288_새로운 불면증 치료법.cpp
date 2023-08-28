//
// Created by KangMinji on 2023-08-28.
//

#include <iostream>
using namespace std;

int test_case, n;

int main() {
	cin >> test_case;
	for (int t=1; t<=test_case; t++){
		cin >> n;

		// 초기화
		int cnt = 0;
		int check = 0, num;

		while(++cnt){
			num = n * cnt;
			while(num) {
				check |= 1 << (num % 10); // check에 값을 추가
				num /= 10;
			}

			if (check == (1 << 10) - 1) // 모두가 똑같으면
				break;
		}

		cout << "#" << t << ' ' << cnt * n << "\n"; // cnt * n번째 양
	}
}
