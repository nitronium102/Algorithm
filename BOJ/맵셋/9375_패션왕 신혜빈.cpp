// 실버3
// Created by KangMinji on 2023-03-02.
// https://www.acmicpc.net/problem/9375

#include <iostream>
#include <map>
using namespace std;

int main() {
	int t, n;
	string clothes, type;

	// 입력
	cin >> t;
	while(t--){
		cin >> n;

		map<string, int> mp;
		while(n--){
			cin >> clothes >> type;
			mp[type]++;
		}

		// 연산
		int answer = 1; // 조합해서 입을 수 있는 경우
		for (auto m : mp){
			answer *= (m.second + 1);
		}

		// 출력
		cout << answer -1<< "\n";
	}
}