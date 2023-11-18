//
// Created by KangMinji on 2023-05-03.
// https://school.programmers.co.kr/learn/courses/30/lessons/169198?language=cpp

#include <cmath>
#include <vector>
using namespace std;

vector<pair<int,int>> points;

int calc_dist(int m, int n, int startX, int startY, int x, int y){
	int answer = 1e9;
	for (int i=0; i<4; i++){
		int sx = points[i].first;
		int sy = points[i].second;
		// sx, sy가 아니라 원래의 startX, startY 기준으로 비교해줘야 함
		if ((i==0 && sy == y && startX >= x)
			|| (i==1 && sy == y && startX < x)
			|| (i==2 && sx == x && startY >= y)
			|| (i==3 && sx == x && startY < y)){
			continue;
		}
		int total = pow(sx-x, 2) + pow(sy-y, 2);
		answer = min(answer, total);
	}
	return answer;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
	vector<int> answer;

	points.push_back({-startX, startY});
	points.push_back({2*m-startX, startY});
	points.push_back({startX, -startY});
	points.push_back({startX, 2*n-startY});

	for(int i=0; i<balls.size(); i++)
		answer.push_back(calc_dist(m, n, startX, startY, balls[i][0], balls[i][1]));

	return answer;
}