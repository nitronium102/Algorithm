// LV3
// Created by KangMinji on 2023-11-12.
// https://school.programmers.co.kr/learn/courses/30/lessons/118668

#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int MAX = 155;

/*
같은 문제 0번, 여러 번 푸는 것 가능
*/
int solution(int alp, int cop, vector<vector<int>> problems) {
	int answer = 0;

	// 모든 문제를 풀 수 있는 알고력, 코딩력
	int max_alp = 0, max_cop = 0;
	for (vector<int> problem : problems) {
		max_alp = max(max_alp, problem[0]);
		max_cop = max(max_cop, problem[1]);
	}

	alp = min(alp, max_alp);
	cop = min(cop, max_cop);

	int dp[MAX][MAX];
	for (int i=0; i<MAX; i++){
		fill(dp[i], dp[i] + MAX, 1e9);
	}

	dp[alp][cop] = 0;

	for (int i=alp; i<=max_alp; i++){
		for (int j=cop; j<=max_cop; j++){
			// 혼자 공부하는 경우
			dp[i+1][j] = min(dp[i][j] + 1, dp[i+1][j]);
			dp[i][j+1] = min(dp[i][j] + 1, dp[i][j+1]);

			// 문제 푸는 경우
			for (vector<int> problem : problems) {
				int alp_req = problem[0];
				int cop_req = problem[1];
				int alp_rwd = problem[2];
				int cop_rwd = problem[3];
				int cost = problem[4];

				// 문제 못 푸는 경우
				if (i < alp_req || j < cop_req) continue;
				int next_alp = min(max_alp, i + alp_rwd);
				int next_cop = min(max_cop, j + cop_rwd);
				dp[next_alp][next_cop] = min(dp[i][j] + cost, dp[next_alp][next_cop]);
			}
		}
	}

	answer = dp[max_alp][max_cop];
	return answer;
}