//
// Created by KangMinji on 2022-03-07.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &time, int n){
    int sum = 0, answer = 0;

    sort(time.begin(), time.end());

    // 0번째 사람 : 0번째 사람의 인출 시간
    // 1번째 사람 : 0번째 사람의 인출 시간 + 1번째 사람의 인출 시간
    // 2번째 사람 : 0번째 사람의 인출 시간 + 1번째 사람의 인출 시간 + 2번째 사람의 인출 시간
    // sum = i번째 사람의 인출 시간 * 대기 시간의 반복 수(n-i)
    for (int i=0; i<n; i++){
        sum += answer * (n-i);
    }

    return sum;
}

int main() {
    int n;
    int answer;
    cin >> n;

    vector<int> time(n);

    for (int i=0; i<n; i++)
        cin >> time[i];

    answer = solution(time, n);
    cout << answer;
}