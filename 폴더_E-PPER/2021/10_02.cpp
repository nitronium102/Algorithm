// 맞아라 OX
#include <iostream>
#include <cstring>
using namespace std;

int solution(char input[]){
	int size = strlen(input);
	int total = 0, cnt = 0;
	
	for (int i=0; i<size; i++){
		if(input[i] == 'O'){
			cnt++;
			total += cnt;
		}
		else{
			cnt = 0;
		}
	}
	return total;
}

int main() {
	char input[100];
	cin >> input;
	int answer = solution(input);
	cout << answer;
	return 0;
}