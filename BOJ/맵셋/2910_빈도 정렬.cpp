// 실버3
// Created by KangMinji on 2023-03-02.
// https://www.acmicpc.net/problem/2910

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

map<int, int> order;

bool cmp(const ci &a, const ci &b){
	if (a.second != b.second){
		return a.second > b.second;
	}
	return order[a.first] < order[b.first];
}

int main() {
	int n, c, input;

	// 입력
	cin >> n >> c;
	map<int, int> freq;
	for (int i=0; i<n; i++){
		cin >> input;

		if (!freq[input]){
			order[input] = i;
		}
		freq[input]++;
	}

	// 연산
	vector<ci> freq_v(freq.begin(), freq.end());
	sort(freq_v.begin(), freq_v.end(), cmp);


	// 출력
	for (ci answer : freq_v){
		while(answer.second--) {
			cout << answer.first << ' ';
		}
	}
}