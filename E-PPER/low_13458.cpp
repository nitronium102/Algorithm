//
// Created by KangMinji on 2022-03-18.
//

#include <iostream>
using namespace std;

// 시험장의 개수 * 각 시험장의 응시자 수  : 10^6 * 10^6
// -> long long 타입 사용
long long solution(int n, int people[], int b, int c){
    long long answer = 0;
    for (int i=0; i<n; i++){
        people[i] -= b;
        answer++;

        if (people[i] > 0){
            answer += people[i] / c;
            if (people[i] % c != 0)
                answer++;
        }
    }
    return answer;
}

int main(){
    int n, b, c;
    int people[1000001] = {0};

    // 입력
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> people[i];
    cin >> b >> c;

    // 연산 & 출력
    cout << solution(n, people, b, c);
}