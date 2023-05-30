// 실버5
// Created by KangMinji on 2023-03-30.
// https://www.acmicpc.net/problem/1316

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	string input;

	// 입력
	cin >> n;

	int answer = 0;
	while(n--){
		cin >> input;
		vector<bool> alphabet(26, false);
		bool flag = true;

		char ch = input[0];
		alphabet[ch-'a'] = true;
		for (int i=1; i<input.size(); i++){
			if (ch != input[i]){ // 다른 문자일 때
				if (alphabet[input[i]-'a']){ // 이미 나온 적이 있는 경우 -> 그룹 단어 아님
					flag = false;
					break;
				}
				ch = input[i];
				alphabet[ch - 'a'] = true;
			}
		}

		if (flag){
			answer++;
		}
	}

	// 출력
	cout << answer << '\n';
}