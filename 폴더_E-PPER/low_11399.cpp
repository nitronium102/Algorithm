//
// Created by KangMinji on 2022-03-07.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &time, int n){
    int sum = 0;

    sort(time.begin(), time.end());

    // 첫 번째 사람 : time[0]
    // 두 번째 사람 : time[0] + time[1]
    // time[i] * (n-i)
    for (int i=0; i<n; i++)
        sum += time[i] * (n-i);

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