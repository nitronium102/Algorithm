// 골드5
// Created by KangMinji on 2023-04-03.
// https://www.acmicpc.net/problem/22251

#include <iostream>
#include <vector>
using namespace std;
const int NUMBER = 10;
const int LED_LENGTH = 7;

vector<int> number_bit = {0b1111110, 0b0110000, 0b1101101, 0b1111001,
						  0b0110011, 0b1011011, 0b1011111, 0b1110000,
						  0b1111111, 0b1111011};

int calcDiff(vector<int> &start_number, int n, int k){
	int cnt = 0;

	for (int i=0; i<k; i++){
		// XOR 연산을 통해 비트가 다른 부분만 1이 남는다
		unsigned char diff = (start_number[i] ^ number_bit[n % 10]);
		for (int j=0; j<LED_LENGTH; j++){
			cnt += (diff & 1);
			diff >>= 1;
		}
		n/= NUMBER;
	}
	return cnt;
}

int solution(int n, int k, int p, int x){
	vector<int> start_number(k);
	int tmp_x = x;

	// 처음 LED에 켜져있는 숫자 bit 저장
	for (int i=0; i<k; i++){
		start_number[i] = number_bit[tmp_x % NUMBER];
		tmp_x /= NUMBER;
	}

	// 1~N까지 숫자 바꿔보고 반전 개수가 1~P개에 포함되는지 확인
	int answer = 0;
	for (int i=1; i<=n; i++){
		if (i == x){
			continue;
		}
		int diff = calcDiff(start_number, i, k);
		if (diff >= 1 && diff <= p){
			answer++;
		}
	}
	return answer;
}

int main() {
	/*
	 * n : 반전된 후 숫자 범위 최댓값
	 * k : 자리수
	 * p : 반전시킬 수 있는 최대 개수
	 * x : 엘리베이터가 멈춰있는 층
	 * */
	int n, k, p, x;

	// 입력
	cin >> n >> k >> p >> x;

	// 연산
	cout << solution(n, k, p, x);
}