//
// Created by KangMinji on 2022-04-13.
//

/*
 * [큰 수의 법칙]
 * 주어진 수들을 M번 더하여 가장 큰 수를 만드는 법칙
 * 배열의 특정한 인덱스에 해당하는 수가 연속 k번을 초과하여 더해질 수 없음
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, k;

    cin >> n >> m >> k;
    vector<int> v(n, 0);

    for (int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int first = v[n-1];
    int second = v[n-2];

    // 가장 큰 수가 등장하는 횟수 : K * (M/(K+1)) + M%(K+1)
    int cnt = k*(m/(k+1)) + m%(k+1);

    int result = 0;
    result += cnt * first; // 가장 큰 수
    result += (m-cnt) * second; // 두 번째로 큰 수 더하기

    cout << result << "\n";


//    int result = 0;
//
//    while(true){
//        for (int i=0; i<k; i++){
//            if (m == 0)
//                break;
//            result += first;
//            m -= 1;
//        }
//        if (m == 0)
//            break;
//        result += second;
//        m-=1;
//    }
//
//    cout << result;
}
