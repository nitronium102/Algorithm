// 실버2
// Created by KangMinji on 2023-01-23.
// https://www.acmicpc.net/problem/23304

#include <iostream>
#include <algorithm>
using namespace std;

bool akaraka(string s){
	string a = s;
	// 1) 문자의 길이가 1이면 A.P
	if (s.length() == 1){
		return true;
	}

	// 2) 펠린드롬 확인
	string left, right;
	left = s.substr(0, s.length()/2);
	if (s.length() % 2 == 1){
		right = s.substr(s.length()/2+1);
	} else {
		right = s.substr(s.length()/2);
	}

	if (left == right && akaraka(left) && akaraka(right)){
		return true;
	}
	return false;
}

int main() {
	// 속ㄷ
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;

	// 입력
	cin >> s;

	if (akaraka(s)){
		cout << "AKARAKA\n";
	} else {
		cout << "IPSELENTI\n";
	}
}