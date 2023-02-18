// BruteForce
// Created by KangMinji on 2023-02-18.
//

#include <iostream>
using namespace std;

int main() {
	int n;

	// 입력
	cin >> n;

	if (n < 2023){
		cout << 0;
		return 0;
	}

	// 연산
	// 모든 정수의 각 자릿수를 확인하면서 2023을 만들 수 있는지 확인하면 된다
	int answer = 0;
	char target[4] = {'2', '0', '2', '3'};
	for (int i = 2023; i<=n; i++){
		int idx = 0;
		bool flag = false;
		string num = to_string(i);

		for (int j=0; j<num.length(); j++){
			if (target[idx] == num[j]){
				idx++;
			}
			if (idx > 3){
				flag = true;
				break;
			}
		}

		if (flag){
			answer++;
		}
	}

	// 출력
	cout << answer << "\n";
}