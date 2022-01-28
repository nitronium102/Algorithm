//
// Created by KangMinji on 2022-01-28.
//

/* [반복되는 수열 파악]
 * 반복되는 수열의 길이 : k+1
 * 수열이 반복되는 횟수 : m/(k+1)
 * => 가장 큰 수가 더해지는 횟수 : int(m/(k+1)*K + m%(k+1)
 * => 두 번째로 큰 수가 더해지는 횟수 : m - (가장 큰 수가 더해지는 횟수)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, k, x;
    vector<int> v;
    int first, second;

    // 입력
    cin >> n >> m >> k;

    for (int i=0; i<n; i++){
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    first = v[n-1]; // 가장 큰 수
    second = v[n-2]; // 두 번째로 큰 수

    // 연산(단순)
//    int cnt = 0;
//    int sum = 0;
//    for (int i=0; i<m; i++){
//        if (cnt < k){ // k 미만인 경우
//            sum += first;
//        }
//        else { // k번 연속해서 더해진 경우
//            sum += second;
//            cnt = 0;
//        }
//        cnt++;
//    }
//      cout << sum << "\n";

    // 연산(해설)
    // 가장 큰 수가 더해지는 횟수
    int cnt = (m/(k+1))*k;
    cnt += m%(k+1);

    int result = 0;
    result += cnt*first; // 가장 큰 수
    result += (m-cnt)*second; // 두 번째로 큰 수

    cout << result << "\n";
}