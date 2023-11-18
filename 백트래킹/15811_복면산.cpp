// 골드4
// Created by KangMinji on 2023-03-31.
// https://www.acmicpc.net/problem/15811

#include <iostream>
#include <vector>
using namespace std;

vector<string> word(3, "");
vector<int> alphabet;
vector<bool> num(10, false);
vector<int> atonum(26, -1);

void findUsedAlphabet(){
	vector<bool> all_alphabet(26, false);

	for (int i=0; i<3; i++){
		for (char c : word[i]){
			if (!all_alphabet[c-'A']){
				all_alphabet[c-'A'] = true;
				alphabet.push_back(c - 'A');
			}
		}
	}
	return;
}

long long wordToNum(string w){
	long long answer = 0;

	for (char c : w){
		answer = answer * 10 + atonum[c - 'A'];
	}
	return answer;
}

bool findSolution(int cnt) {
	// 종료조건
	if (cnt == alphabet.size()){
		if (wordToNum(word[0]) + wordToNum(word[1]) == wordToNum(word[2])){
			return true;
		}
		return false;
	}

	for (int i=0; i<10; i++){
		if (num[i]){ // 이미 숫자가 사용된 경우
			continue;
		}
		num[i] = true;
		atonum[alphabet[cnt]] = i;

		if (findSolution(cnt + 1)){
			return true;
		}

		num[i] = false;
		atonum[alphabet[cnt]] = -1;
	}
	return false;
}

int main() {

	// 입력
	cin >> word[0] >> word[1] >> word[2];

	// 연산
	findUsedAlphabet();

	cout << (findSolution(0) ? "YES" : "NO");
}