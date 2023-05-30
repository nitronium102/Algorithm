//
// Created by KangMinji on 2023-05-23.
// https://school.programmers.co.kr/learn/courses/30/lessons/161988

#include <string>
#include <vector>
using namespace std;

vector<long long> makePulse(vector<int> sequence, int start){
	vector<long long> pulse;

	for (int seq : sequence){
		pulse.push_back(seq * start);
		start *= -1;
	}

	return pulse;
}

long long solution(vector<int> sequence) {

	int len = sequence.size();
	// 펄스를 적용한 배열
	vector<long long> plus_pulse = makePulse(sequence, 1);
	vector<long long> minus_pulse = makePulse(sequence, -1);

	// dp 배열
	vector<long long> plus_dp(len+1, 0);
	vector<long long> minus_dp(len+1, 0);
	plus_dp[0] = plus_pulse[0];
	minus_dp[0] = minus_pulse[0];

	long long answer = 0;

	for (int i=1; i<len; i++){
		// 1) -1로 시작하는 pulse
		minus_dp[i] = max(minus_dp[i-1] + (long long)minus_pulse[i], (long long)minus_pulse[i]);
		// 2) 1로 시작하는 pulse
		plus_dp[i] = max(plus_dp[i-1] + (long long)plus_pulse[i], (long long)plus_pulse[i]);

		answer = max(answer, max(minus_dp[i], plus_dp[i]));
	}

	// size가 1인 경우
	if (len == 1) {
		answer = max(answer, max(minus_dp[0], plus_dp[0]));
	}
	return answer;
}