// lv2
// Created by KangMinji on 2023-05-04.
// https://school.programmers.co.kr/learn/courses/30/lessons/154538

#include <string>
#include <vector>
#include <queue>
using namespace std;
const int SIZE = 1e6 + 1;

vector<int> cnt(SIZE, -1);

int solution(int x, int y, int n) {
	int answer = 0;

	queue<int> q;

	q.push(x);
	cnt[x] = 0;

	while(!q.empty()){
		int num = q.front();
		q.pop();

		for (auto next : {num + n, num*2, num*3}){
			// 어차피 앞에서부터 찾는 거라 자동으로 최솟값 -> min으로 안 잡아도 됨
			if (next > y || cnt[next] != -1){
				continue;
			}
			cnt[next] = cnt[num]+1;
			q.push(next);
		}
	}

	answer = cnt[y];

	return answer;
}