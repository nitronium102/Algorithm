//
// Created by KangMinji on 2022-01-28.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m, num;
    int min_val, result;

    // 입력
    cin >> n >> m;
    for (int i=0; i<n; i++){
        min_val = 10001;
        for (int j=0; j<m; j++) {
            cin >> num;
            min_val = min(min_val, num); // 각 행에서 제일 작은 숫자 선택
        }
        result = max(min_val, result); // 그 중 제일 큰 수 선택
    }

    // 출력
    cout << result << "\n";
}