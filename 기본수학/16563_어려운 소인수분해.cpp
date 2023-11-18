// 골드4
// Created by KangMinji on 2023-03-06.
// https://www.acmicpc.net/problem/16563

#include <iostream>
#include <vector>
using namespace std;
const int MAX = 5e6 + 1;

vector<int> makePrime() {
	vector<int> prime(MAX, 0);

	for (int i=2; i*i<=MAX; i++){
		if (prime[i]){
			continue;
		}
		for (int j=i*i; j<=MAX; j+=i){
			if (!prime[j]){
				prime[j] = i;
			}
		}
	}
	return prime;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, input;

	vector<int> prime = makePrime(); // prime[i] == 0이어야 소수

	// 입력
	cin >> n;
	while(n--){
		cin >> input;

		while(prime[input]){
			cout << prime[input] << ' ';
			input /= prime[input];
		}
		cout << input << '\n';
	}
}