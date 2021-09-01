// 문자열 압축
#include <iostream>
#include <string>
using namespace std;

string solution(string input){
	string answer = "";
	int cnt=0;
	if (input[0] == '1')
		answer += "1";
	
	for (int i=0; i<input.length() - 1; i++){
		if (input[i] != input[i+1]){
			//answer += (char)(cnt+65);
			answer += 'A'+cnt;
			cnt = 0;
		}
		else {
			cnt++;
		}
	}
	answer += 'A'+cnt; // 마지막 문자 저장
	return answer;
}

int main() {
	char input[100];
	cin >> input;
	string answer = solution(input);
	cout << answer;
	return 0;
}