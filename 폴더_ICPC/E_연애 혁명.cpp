//
// Created by KangMinji on 2023-02-18.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

vector<vector<ci>> like_list; // {좋아하는 사람, 애정도}

int keep_couple(vector<ci> &couple_list) {
	int sum = 0;
	for (ci couple : couple_list){
		int lover1 = couple.first;
		int lover2 = couple.second;
		for (int i=0; i<like_list[lover1].size(); i++){
			int student = like_list[lover1][i].first;
			int love_cnt = like_list[lover1][i].second;
			if (student != lover2){
				sum += love_cnt; // 애정도 박탈
				// 애정도 0으로 초기화
				like_list[lover1][i] = {student, 0};
				like_list[student][lover1] = {lover1, 0};
			}
		}

		for (int i=0; i<like_list[lover2].size(); i++){
			int student = like_list[lover2][i].first;
			int love_cnt = like_list[lover2][i].second;
			if (student != lover1){
				sum += love_cnt; // 애정도 박탈
				// 애정도 0으로 초기화
				like_list[lover2][i] = {student, 0};
				like_list[student][lover2] = {lover2, 0};
			}
		}
	}
	cout << sum << "\n";
	return sum;
}

bool cmp(const ci &a, const ci &b){
	if (a.second != b.second){
		return a.second > b.second;
	}
	return a > b;
}

int main() {
	int n, m, a, b, c, d;

	// 입력
	cin >> n >> m;
	like_list.assign(n+1, vector<ci>());
	vector<ci> origin_couple;
	for (int i=0; i<m; i++){
		cin >> a >> b >> c >> d;
		if (d == 1){
			origin_couple.push_back({a, b});
		}
		else {
			like_list[a].push_back({b, c});
			like_list[b].push_back({a, c});
		}
	}

	// 연산
	// 1) 이미 커플인 경우 : 다른 사랑 관계 다 끊어야 함
	int answer = 0;
	answer += keep_couple(origin_couple);

	// 2) 커플이 아닌 경우 : 인접리스트 타고 가서 제일 애정도 높은 놈 찾기 -> 걔 빼고 다 끊기
	for (int i=1; i<like_list.size(); i++){
		sort(like_list[i].begin(), like_list[i].end(), cmp);
	}

	vector<ci> new_couple;
	for (int i=1; i<like_list.size(); i++){
		for (int j=0; j<like_list[i].size(); j++) {
			if (!like_list[i][j].second){
				continue;
			}
			int lover = like_list[i][j].first;
			int love_cnt = like_list[i][j].second;
			// 서로가 서로를 좋아하는 것이 애정도 최대인 경우
			if (love_cnt == like_list[lover][0].second && lover == like_list[lover][0].first){
				new_couple.push_back({i, lover});
				break;
			}
		}
	}

	answer += keep_couple(new_couple);

	// 출력
	cout << answer << "\n";
}