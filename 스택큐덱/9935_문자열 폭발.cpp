// 골드4
// Created by KangMinji on 2023-01-23.
// https://www.acmicpc.net/problem/9935

#include <iostream>

using namespace std;

/*
 * 폭발은 다음과 같은 과정으로 진행된다.

문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다. 남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.
상근이는 모든 폭발이 끝난 후에 어떤 문자열이 남는지 구해보려고 한다. 남아있는 문자가 없는 경우가 있다. 이때는 "FRULA"를 출력한다.

폭발 문자열은 같은 문자를 두 개 이상 포함하지 않는다.
 */

int main() {
	string target, bomb;
	string answer = "";

	// 입력
	cin >> target >> bomb;

	// 연산
	// 들어온 char이 bomb의 마지막과 같다면 이전 문자열을 확인
	// -> 마지막 n글자가 폭발 문자열과 같다면 뒷부분 삭제
	int bomb_len = bomb.length();
	for (int i = 0; i < target.length(); i++) {
		answer += target[i];

		if (target[i] == bomb.back()) {
			// 폭발 문자열보다 짧은 경우
			if (answer.length() < bomb.length()) {
				continue;
			}

			// 폭발 문자열과 같은 부분의 길이 확인
			int cnt = 0;
			for (int j = 0; j < bomb_len; j++) {
				if (answer[answer.length() - 1 - j] == bomb[bomb_len - 1 - j]) {
					cnt++;
				}
			}

			// 폭발시킬 수 있는 경우
			if (cnt == bomb_len) {
				for (int k = 0; k < bomb_len; k++) {
					answer.pop_back();
				}
			}
		}
	}

	// 출력
	if (answer.length() == 0) {
		cout << "FRULA\n";
	} else {
		cout << answer;
	}
}