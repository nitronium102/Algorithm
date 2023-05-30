//
// Created by KangMinji on 2023-04-03.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;

int t, n, m, k, a, b; // 접수, 정비 차량번호
vector<int> reception_time, repair_time, customer;
vector<ci> reception;
vector<ci> repair;

queue<int> reception_waiting;
queue<int> repair_waiting;
vector<int> a_answer, b_answer;

int findCustomerNo(){
	int reception_cnt = 0, repair_cnt = 0;

	int time = 0;
	while(time++) {
		// 1) 접수 대기열 추가
		while(reception_cnt < k && customer[reception_cnt] == time) {
			reception_waiting.push(++reception_cnt);
		}

		// 2) 접수 진행 & 수리 대기열 추가
		for (int i=0; i<n; i++){
			// 채워져 있는 창구 시간 증가
			if (reception[i].first){
				// 창구에서 처리 완료된 경우 -> 수리 대기열 추가
				if (reception[i].second == reception_time[i]){
					repair_waiting.push(reception[i].first);
					reception[i] = {0, 0};
				} else {
					reception[i].second++;
				}
			}

			// 빈 창구 존재하는 경우
			if (!reception_waiting.empty() && reception[i].first == 0){
				reception[i].first = reception_waiting.front();
				reception_waiting.pop();

				if (i + 1 == a){ // 동일한 창고에서 접수한 경우
					a_answer.push_back(reception[i].first);
				}
			}
		}
		// 3) 수리 진행
		for (int i=0; i<m; i++){
			if (repair[i].second == repair_time[i]){
				repair[i] = {0, 0};
				repair_cnt++;
			}

			if (!repair_waiting.empty() && repair[i].first == 0){
				repair[i].first = repair_waiting.front();
				repair_waiting.pop();

				if (i + 1 == b){
					b_answer.push_back(repair[i].first);
				}
			}

			if (repair[i].first){
				repair[i].second++;
			}
		}

		// 종료 조건 확인
		if (repair_cnt == k && reception_waiting.empty() && repair_waiting.empty()){
			bool check = true;
			for (int i=0; i<n; i++){
				if (reception[i].first){
					check = false;
					break;
				}
			}

			if (check){
				break;
			}
		}
		t++;
	}
	answer = 0;
	sort(a_list.begin(), a_list.end());
	sort(b_list.begin(), b_list.end());
	vector<int> result(a_list.size() + b_list.size());
	set_intersection(a_list.begin(), a_list.end(), b_list.begin(), b_list.end(), result.begin());
	for (int a : result)
		answer += a;
	if (answer == 0)
		answer = -1;

	cout << "#" << test_case << " " << answer<< endl;
}

int main() {

	cin >> t;
	while(t--) {
		// 입력
		cin >> n >> m >> k >> a >> b;

		// 초기화
		reception_time.assign(n, 0);
		repair_time.assign(m, 0);
		customer.assign(k, 0);
		reception.assign(n, {0, 0});
		repair.assign(m, {0, 0});

		for (int i=0; i<n; i++){
			cin >> a_time[i];
		}
		for (int i=0; i<m; i++){
			cin >> b_time[i];
		}
		for (int i=0; i<k; i++){
			cin >> customer[i];
		}

		// 연산
		answer = findCustomerNo(a, b);

		// 출력
	}
}