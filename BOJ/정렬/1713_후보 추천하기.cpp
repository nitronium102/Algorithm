// 실버1
// Created by KangMinji on 2023-07-25.
// https://www.acmicpc.net/problem/1713

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;
typedef pair<int, ci> pi;

bool cmp(const pi &a, const pi &b){
	if (a.second.first == b.second.first) {
		return a.second.second < b.second.second;
	}
	return a.second.first < b.second.first;
}


int main() {
	int n, m, idx;

	cin >> n >> m;

	map<int, ci> picture; // 추천 받은 학생, {추천 수, 들어온 시각}
	for (int i=1; i<=m; i++){
		cin >> idx;

		// 꽉 찬 경우 & 등록하는 경우
		if (picture.size() == n && picture.find(idx) == picture.end()) {
			picture.erase(min_element(picture.begin(), picture.end(), cmp));
		}

		// 사진첩 안 찼고 처음 등록하는 경우
		if (picture.find(idx) == picture.end()){
			picture[idx].second = i;
		}
		picture[idx].first++; // 추천 횟수 증가
	}

	// 출력
	for (auto student : picture)
		cout << student.first << ' ';
}