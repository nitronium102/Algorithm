// 실버3
// Created by KangMinji on 2023-03-06.
// https://www.acmicpc.net/problem/1213

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	string input;

	// 입력
	cin >> input;
	map<char, int> m;

	for (char c: input) {
		m[c]++;
	}

	// 연산
	string center = "", str = "";
	for (auto info: m) {
		if (info.second % 2 == 1) {
			if (center.length()) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			center = info.first;
			info.second--;
//			m[info.first]--;
		}

		while(info.second > 0){
			str += info.first;
			info.second -= 2;
		}
	}
//
//	string front = "", back = "";
//	for (auto info: m) {
//		while (info.second > 0) {
//			front += info.first;
//			back = info.first + back;
//			info.second -= 2;
//		}
//	}

	string answer = str + center;
	reverse(str.begin(), str.end());
	answer += str;
	// 출력
	cout << answer;

}