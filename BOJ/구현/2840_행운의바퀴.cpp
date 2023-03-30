// 실버4
// Created by KangMinji on 2023-03-30.
// https://www.acmicpc.net/problem/2840

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k, s;
	char c;

	// 입력
	cin >> n >> k;
	vector<char> wheel(n, '?');
	vector<bool> alphabet(26, false);

	int idx = 0;
	while(k--){
		cin >> s >> c;
		idx = (idx + s) % n; // 화살표를 시계방향으로 이동시킴
		if (wheel[idx] == c){
			continue;
		}

		// 해당 자리에 문자가 있거나 중복되는 문자가 있는 경우
		if (wheel[idx] != '?' || alphabet[c-'A']){
			cout << '!';
			return 0;
		}

		wheel[idx] = c;
		alphabet[c-'A'] = true;
	}

	// 출력 : 화살표 반시계방향으로
	string answer = "";
	for (int i=n; i>0; i--){
		answer += wheel[(i+idx)%n];
	}
	cout << answer;
}