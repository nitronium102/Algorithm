// D3
// Created by KangMinji on 2023-11-18
// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do

#include <iostream>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
const int PARKING_SIZE = 105;
const int CAR_SIZE = 2005;

int n, m, x;
bool parkinglot[PARKING_SIZE];
int money[PARKING_SIZE]; // 단위 무게 당 요금
int weight[CAR_SIZE]; // 차량 i의 무게
int car[CAR_SIZE];

int checkParkingLot() {
	for (int i=1; i<=n; i++){
		if (!parkinglot[i]){
			return i;
		}
	}
	return -1;
}

int main() {
	int T;

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++){
		// 초기화
		memset(parkinglot, false, CAR_SIZE);

		long long answer = 0;

		// 입력
		cin >> n >> m;
		for (int i=1; i<=n; i++) cin >> money[i];
		for (int i=1; i<=m; i++) cin >> weight[i];

		queue<int> q; // 차 대기 목록
		for (int i=0; i<2*m; i++) {
			cin >> x; // 차량의 번호
			// 1) 음수이면 -x번 차가 나감
			if (x < 0) {
				int parking_idx = car[-x];
				parkinglot[parking_idx] = false;
				// 대기하고 있던 차 한 대 들어가도록
				if (!q.empty()){
					parkinglot[parking_idx] = true;
					int new_car = q.front();
					car[new_car] = parking_idx;
					answer += weight[new_car] * money[parking_idx];
					q.pop();
				}
			}
			// 2) 양수이면 x번 차 들어옴
			else {
				int parking_idx = checkParkingLot();
				// 2-1) 주차 가능한 경우
				if (parking_idx != -1) {
					parkinglot[parking_idx] = true;
					car[x] = parking_idx;
					answer += weight[x] * money[parking_idx];
				}
				// 2-2) 주차 못하는 경우
				else {
					q.push(x);
				}
			}
		}
		cout << "#" << test_case << ' ' << answer << "\n";
	}
}