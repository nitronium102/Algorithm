// LV2
// Created by KangMinji on 2023-04-29.
// https://school.programmers.co.kr/learn/courses/30/lessons/178870

#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	vector<int> answer;

	int start = 0, end = 0, len = 1e6 +1;
	int sum = sequence[0];
	pair<int, int> result;
	while(start <= end && end < sequence.size()){
		// 1) 합이 동일한 경우
		if (sum == k){
			// 길이가 더 짧은 수열인 경우
			if (end - start + 1 < len){
				len = end - start + 1;
				result = {start, end};
			}
			sum -= sequence[start++]; // 다음으로 이동
		}
			// 2) 합이 k보다 작은 경우
		else if (sum < k){
			sum += sequence[++end];
		}
			// 3) 합이 k보다 큰 경우
		else {
			sum -= sequence[start++];
		}
	}
	answer = {result.first, result.second};
	return answer;
}