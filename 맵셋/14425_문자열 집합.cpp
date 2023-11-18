// 실버3
// Created by KangMinji on 2023-03-02.
// https://www.acmicpc.net/problem/14425

#include <iostream>
#include <map>
using namespace std;

int main() {
	int n, m;
	string s;

	map<string, bool> mp;

	// 입력
	cin >> n >> m;
	while(n--){
		cin >> s;
		mp[s] = true;
	}

	int answer = 0;
	while(m--){
		cin >> s;
		if (mp[s]){
			answer++;
		}
	}

	// 출력
	cout << answer << "\n";
}