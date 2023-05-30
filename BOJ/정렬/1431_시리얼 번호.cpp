// 실버2
// Created by KangMinji on 2023-02-27.
// https://www.acmicpc.net/problem/1431

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calcSum(string s){
	int sum = 0;
	for (int i=0; i<s.length(); i++){
		if (isdigit(s[i])){
			sum += s[i] - '0';
		}
	}
	return sum;
}

bool cmp(const string &a, const string &b){
	if (a.length() != b.length()){
		return a.length() < b.length();
	}
	int sum_a = calcSum(a);
	int sum_b = calcSum(b);
	if (sum_a != sum_b){
		return sum_a < sum_b;
	}
	return a < b;
}

int main() {
	int n;

	// 입력
	cin >> n;
	vector<string> sereal(n, "");
	for (int i=0; i<n; i++){
		cin >> sereal[i];
	}

	// 연산
	sort(sereal.begin(), sereal.end(), cmp);

	// 출력
	for (string s : sereal){
		cout << s << "\n";
	}
}