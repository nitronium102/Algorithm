//
// Created by KangMinji on 2022-04-13.
//

/*
 * [숫자 카드 게임]
 * 행 -> 가장 숫자 낮은 카드
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, num;
    int result;

    cin >> n >> m;

    for (int i=0; i<n; i++) {
        min_val = 10001;
        for (int j=0; j<m; j++){
            cin >> num;
            min_val = min(min_val, num);
        }
        result = max(min_val, result);
    }

    cout << result;
}
