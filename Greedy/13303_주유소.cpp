// 실버3
// Created by KangMinji on 2023-02-01.
// https://www.acmicpc.net/problem/13305

#include <iostream>
using namespace std;
const int MAX = 1e9;

int dist[100000];
int cost[100000];

int main() {
	int n;
	// 입력
	cin >> n;
	for (int i=0; i<n-1; i++){
		cin >> dist[i];
	}
	for (int i=0; i<n; i++){
		cin >> cost[i];
	}

	// 연산
	long long sum = 0;
	long long min_cost = MAX;
	for (int i=0; i<n-1; i++){
		if (cost[i] < min_cost){
			min_cost = cost[i];
			cout << "엽\n";
		}
		cout << min_cost << "\n";
		sum += min_cost * dist[i];
	}

	// 출력
	cout << sum << "\n";

}