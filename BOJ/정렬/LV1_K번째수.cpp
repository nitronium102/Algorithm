//
// Created by KangMinji on 2023-02-24.
// https://school.programmers.co.kr/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i=0; i<commands.size(); i++){
		int start = commands[i][0];
		int end = commands[i][1];
		int k = commands[i][2];

		// 1) array 자르기
		vector<int> v;
		for (int j=start-1; j<end; j++){
			v.push_back(array[j]);
		}

		// 2) 배열 정렬하기
		sort(v.begin(), v.end());

		// 3) 배열의 k번째 수 구하기
		answer.push_back(v[k-1]);
	}

	return answer;
}