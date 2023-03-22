// 실버1
// Created by KangMinji on 2023-03-06.
// https://www.acmicpc.net/problem/9421

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<bool> findPrime(int n){
	vector<bool> is_prime(n+1, true);

	for (int i=2; i*i<=n; i++){
		if (!is_prime[i]){
			continue;
		}
		for (int j=i*i; j<=n; j+=i){
			if (is_prime[j]){
				is_prime[j] = false;
			}
		}
	}

	return is_prime;
}

bool check(int num){
	map<int, bool> m;

	while(true){
		int sum = 0;
		while(num > 0){
			sum += pow(num%10, 2);
			num /= 10;
		}
		if (sum == 1){
			return true;
		}
		if (m[sum]){
			return false;
		}
		m[sum] = true;
		num = sum;
	}
}

void findAns(int n, vector<bool> &is_prime){
	for (int i=2; i<=n; i++){
		if (!is_prime[i]){
			continue;
		}
		if (check(i)){
			cout << i << '\n';
		}
	}
}

int main() {
	int n;

	// 입력
	cin >> n;

	// 소수 구하기
	vector<bool> is_prime = findPrime(n);

	// 상근수 구하기
	findAns(n, is_prime);
}