// 실버3
// Created by KangMinji on 2023-03-29.
// https://www.acmicpc.net/problem/2607

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26;

vector<int> countAlpha(string word) {
	vector<int> v(SIZE, 0);
	for (char c: word) {
		v[c - 'A']++;
	}
	return v;
}

bool isSimilar(string target, string str, vector<int> target_alpha, vector<int> word_alpha) {
	int diff = 0;

	for (int i = 0; i < SIZE; i++) {
		diff += abs(target_alpha[i] - word_alpha[i]);
	}

	if (diff <= 1 || (diff == 2 && target.length() == str.length())) {
		return true;
	}
	return false;
}

int main() {
	int n;
	string target, str;

	// 입력
	cin >> n >> target;
	vector<int> target_alpha = countAlpha(target);

	int answer = 0;
	while (--n) {
		cin >> str;
		vector<int> word_alpha = countAlpha(str);
		answer += isSimilar(target, str, target_alpha, word_alpha);
	}

	// 출력
	cout << answer;
}