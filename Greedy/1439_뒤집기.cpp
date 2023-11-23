// 실버5
// Created by KangMinji on 2023-11-23.
// https://www.acmicpc.net/problem/1439

#include <iostream>
using namespace std;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	string s;
	cin >> s;

	// 연산
	int zero_cnt = 0;
	int one_cnt = 0;
	for (int i=0; i<s.length(); i++){
		if (s[i] != s[i+1]){
			if (s[i] == '0') zero_cnt++;
			else one_cnt++;
		}
	}

	cout << min(zero_cnt, one_cnt);
}