//
// Created by KangMinji on 2023-02-24.
// https://school.programmers.co.kr/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값
int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(), greater<>());

	// 연산
	for (int i=0; i<citations.size(); i++){
		if (i+1 <= citations[i]){
			answer = i+1;
		}
	}

	return answer;
}