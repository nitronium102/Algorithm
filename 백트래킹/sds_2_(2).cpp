//
// Created by KangMinji on 2023-07-08.
//

#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

int n, m, k;
int answer;
string bulb;
vector<vector<int>> connect;
vector<vector<int>> switchList;
bool visited[19];
map<string, int> mp;
int freq = 0;

bool check() {
	for (int i=1; i<=n; i++){
		if (bulb[i] == '0') return false;
	}
	return true;
}

void turnSwitch(int idx, int cnt) {
	freq++;
	cout << idx << " 전구상태출력 : ";
	for (int i=1; i<=n; i++){
		cout << bulb[i];
	}
	cout << '\n';

	// 종료조건
	if (check()) {
		answer = min(answer, cnt);
		cout << "여기" << answer << "\n";
		return;
	}

	if (idx == n+1) {
		return;
	}

	for (int switchNo : switchList[idx]) {
		for (int num : connect[switchNo]) {
			bulb[num] = bulb[num] == '0' ? '1' : '0';
		}
		mp[bulb] += 1;

		if (mp[bulb]) {
			turnSwitch(idx+1, cnt+1);
		}

		for (int num : connect[switchNo]) {
			bulb[num] = bulb[num] == '0' ? '1' : '0';
		}
		mp[bulb] -=1;
	}
	// 해당 전구 안 켠 경우
	turnSwitch(idx+1, cnt);
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int idx=1; idx<=t; idx++){
		// 입력
		cin >> n >> m >> k;


		fill(visited, visited+19, false);
		char c;
		bulb = "0";
		for (int i=0; i<n; i++){
			cin >> c;
			bulb += c;
		}

		// cout << "전구 : " <<  bulb << "\n";

		// 선언
		answer = 1e9;
		connect.assign(m+1, vector<int>(k, 0)); // 스위치로 바꿀 수 있는 전구 리스트
		switchList.assign(n+1, vector<int>()); // 하나의 전구 당 연결되어 있는 스위치 번호

		for (int i=1; i<=m; i++){
			for (int j=0; j<k; j++) {
				cin >> connect[i][j];
				switchList[connect[i][j]].push_back(i);
			}
		}

		for (int i=1; i<=m; i++) {
			for (int j=0; j<k; j++) {
				cout << connect[i][j] << ' ';
			}
			cout << '\n';
		}

		for (int i=1; i<=n; i++){
			for (int s : switchList[i])
				cout << s << ' ';
			cout << '\n';
		}
		// 연산
		// 첫 번째부터 켜보고 그 다음 하나씩 해보던가....
		turnSwitch(1, 0);

		// 출력
		if (answer == 1e9) answer = -1;
		cout << '#' << idx << ' ' << answer << '\n';
		cout << freq << '\n';
	}
}
