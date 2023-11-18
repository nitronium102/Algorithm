// 실버1
// Created by KangMinji on 2023-07-28.
// https://www.acmicpc.net/problem/5525

#include <iostream>
using namespace std;

int main() {
	int n, m;
	string s;

	// 입력
	cin >> n >> m >> s;

	// 연산
	int answer = 0;
	for (int i=1; i<s.size()-1; i++){
		int cnt = 0;
		if (s[i-1] == 'I'){
			while(s[i] == 'O' && s[i+1] == 'I'){
				i+=2;
				cnt++;
				if (cnt == n){
					cnt--;
					answer++;
				}
			}
		}
	}

	// 출력
	cout << answer << '\n';
}