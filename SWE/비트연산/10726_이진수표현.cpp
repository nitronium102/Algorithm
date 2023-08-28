//
// Created by KangMinji on 2023-08-28.
//

#include <iostream>
using namespace std;

int T, n, m;
string answer;

int main() {
	cin >> T;

	for (int t = 1; t<=T; t++){
		cin >> n >> m;

		int bitmask = (1 << n) - 1; // n개의 bit를 1로 표현

		if ((m & bitmask) == bitmask)
			answer = "ON";
		else
			answer = "OFF";

		cout << "#" << t << " " << answer << '\n';
	}
}