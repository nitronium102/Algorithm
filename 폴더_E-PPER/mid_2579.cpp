//
// Created by KangMinji on 2022-03-12.
//

#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> &score){
    int answer = 0;

    vector<int> stairs(n+1, 0);

    stairs[1] = score[1];
    stairs[2] = score[1] + score[2];

    for (int i=3; i<=n; i++){
        stairs[i] = max(stairs[i-3]+score[i-1], stairs[i-2])+score[i];
    }

    answer = stairs[n];
    return answer;
}

int main() {
    int n;
    cin >> n;
    int answer;

    vector<int> score(n+1, 0);

    for (int i=1; i<=n; i++)
        cin >> score[i];

    answer = solution(n, score);
    cout << answer;
}