// LV2
// Created by KangMinji on 2023-04-30.
// https://school.programmers.co.kr/learn/courses/30/lessons/172927

#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int answer = 1e8;
int fatigue[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
map<string, int> m = {{"diamond", 0}, {"iron", 1}, {"stone", 2}};

void dfs(int idx, int total, vector<int> &picks, vector<string> &minerals){
	// 종료조건
	if (idx >= (int)minerals.size()
		|| (picks[0] == 0 && picks[1] == 0 && picks[2] == 0)){
		answer = min(answer, total);
		return;
	}

	for (int i=0; i<3; i++){
		if (picks[i]){
			picks[i]--;

			int sum = 0, limit = min(idx+5, (int)minerals.size());
			for (int j=idx; j<limit; j++){
				sum += fatigue[i][m[minerals[j]]];
			}
			dfs(limit, total + sum, picks, minerals);

			picks[i]++;
		}
	}
}

// pick 순서대로 깨면 됨
int solution(vector<int> picks, vector<string> minerals) {

	// 연산 : 5개씩 묶어서 진행
	dfs(0, 0, picks, minerals);

	return answer;
}