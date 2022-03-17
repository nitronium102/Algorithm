//
// Created by KangMinji on 2022-03-16.
//

/*
 * 사다리
 * 1 <= n <= 100,000 -> long long 사용
 * 사다리를 만나면 좌우 번호가 swap된다!
 * => bubble sort를 이용해서 정렬
 */

#include <iostream>
#include <vector>
using namespace std;

long long solution(int n, vector<int> &people){
    long long answer = 0;

    for (int i=1; i<=n; i++){ // 빼기 쉬우라고 1부터 시작
        for (int j=i-1; j>=0; j--){
            if (people[j] > people[i]) { // people[j] > people[j+1]
                answer++;
            }
        }
    }

    return answer;
}

int main(){
    int n;

    // 입력
    cin >> n;
    vector<int> people(n, 0);
    for (int i=0; i<n; i++)
        cin >> people[i];

    // 연산 & 출력
    cout << solution(n, people);
}