//
// Created by KangMinji on 2022-03-16.
//

/* 17회 맞아라OX */

#include <iostream>
using namespace std;

int solution(string result){
    int answer = 0;
    int sum = 0;
    for (int i=0; i<result.length(); i++){
        if (result[i] == 'O')
            sum++;
        else
            sum=0;
        answer += sum;
    }
    return answer;
}

int main() {
    string result;
    // 입력
    cin >> result;

    // 출력
    cout << solution(result);
}