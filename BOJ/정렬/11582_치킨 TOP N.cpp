//
// Created by KangMinji on 2023-01-12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> taste_score;

void divide(int N, int k){
    int num = N;

    while(num > 0){
        // 0) 분할
        num /= 2;

        // 1) 합병 정렬 진행
        int cnt = N/num;
        for (int i=0; i<N; i+=cnt){
            sort(taste_score.begin()+i, taste_score.begin()+i+cnt);
        }

        // 2) 인원 수가 k와 동일하면 해당 단계의 결과갑 출력
        if (num == k){
            break;
        }
    }
}

int main() {
    int N, k;

    // 입력
    cin >> N;
    taste_score.assign(N, 0);
    for (int i=0; i<N; i++){
        cin >> taste_score[i];
    }
    cin >> k;

    // 연산
    divide(N, k);

    // 출력
    for (int i=0; i<N; i++){
        cout << taste_score[i] << ' ';
    }
    cout << "\n";
}