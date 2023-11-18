// 실버1
// Created by KangMinji on 2023-03-30.
// https://www.acmicpc.net/problem/1713

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;
typedef pair<int, ci> pi;

bool cmp(const pi &a, const pi &b){
	if (a.second.first != b.second.first){
		return a.second.first < b.second.first;
	}
	return a.second.second < b.second.second;
}

// 학생 번호, 추천 수, 추천 시작 시간
// 삭제되는 경우 해당 학생의 추천 횟수는 0으로 바뀜
int main() {
	int n, total_kudos, id;

	// 입력
	cin >> n >> total_kudos;
	map<int, ci> candidate; // 번호, {추천 수, 추천 시간}
	for (int i=0; i<total_kudos; i++){
		cin >> id;

		// 사진틀 꽉 찬 경우
		if (candidate.size() == n && candidate.find(id) == candidate.end()){
			candidate.erase(min_element(candidate.begin(), candidate.end(), cmp));
		}

		// 처음 등록하는 경우
		if (candidate.find(id) == candidate.end()){
			candidate[id].second = i;
		}
		candidate[id].first++; // 추천 횟수 증가
	}

	// 출력
	for (auto c : candidate){
		cout << c.first << ' ';
	}
}