// LV3
// Created by KangMinji on 2023-11-17.
// https://school.programmers.co.kr/learn/courses/30/lessons/132266

#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;

const int MAX = 100005;

/*
n : 총 지역의 수
roads : 왕복 길 정보
sources : 각 부대원이 위치한 서로 다른 지역 (해당 원소 순서대로 강철부대 복귀)
destination : 강철부대의 지역
*/
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
	vector<int> answer;

	// 그래프 초기화
	vector<int> graph[MAX];
	for (vector<int> road : roads) {
		int n1 = road[0];
		int n2 = road[1];
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}

	// 연산
	queue<ci> q;
	vector<int> cost(MAX, -1); // destination에서 source까지의 거리

	// 초기화
	q.push({destination, 0});
	cost[destination] = 0;
	while(!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();

		for (int next : graph[cur]) {
			if (cost[next] == -1 || cost[next] > cost[cur] + 1){
				cost[next] = cost[cur] + 1;
				q.push({next, dist + 1});
			}
		}
	}

	for (int source : sources){
		answer.push_back(cost[source]);
	}

	return answer;
}