// 실버2
// Created by KangMinji on 2023-05-23.
// https://www.acmicpc.net/problem/12891

#include <iostream>
#include <vector>
#include <map>
using namespace std;

char alpha[4] = {'A', 'C', 'G', 'T'};
map<char, int> info;

bool checkPwd(map<char, int> m){
	for (auto iter = info.begin(); iter != info.end(); iter++){
		if (m[iter->first] < iter->second){
			return false;
		}
	}
	return true;
}

int main() {
	int s, p, cnt;
	string input;

	// 입력
	cin >> s >> p >> input;
	for (int i = 0; i < 4; i++) {
		cin >> cnt;
		info[alpha[i]] = cnt;
	}

	// 연산
	int answer = 0;
	map<char, int> m;

	// 초기 세팅
	for (int i=0; i<p; i++){
		m[input[i]]++;
	}
	if (checkPwd(m)){
		answer++;
	}

	for (int i=p; i<s; i++){
		m[input[i-p]]--;
		m[input[i]]++;
		if (checkPwd(m)){
			answer++;
		}
	}
	// 출력
	cout << answer;
}