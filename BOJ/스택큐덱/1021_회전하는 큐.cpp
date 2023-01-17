//
// Created by KangMinji on 2023-01-13.
//

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int findTargetIdx(int num, deque<int> &dq){
    int idx = 0;
    for (int i = 0; i<dq.size(); i++){
        if (num == dq[i]){
            idx = i;
            break;
        }
    }
    return idx;
}

int main() {
    int n, m;
    deque<int> dq;
    vector<int> v;

    // 입력
    cin >> n >> m;
    v.assign(m, 0);
    for (int i=1; i<=n; i++){ // index
        dq.push_back(i);
    }
    for (int i=0; i<m; i++){
        cin >> v[i];
    }

    // 연산
    int cnt = 0;
    for (int i=0; i<m; i++){
        int idx = findTargetIdx(v[i], dq);
        // 3번 사용(뒤에서 pop)
        if (idx > dq.size() - idx){
            while(v[i]!=dq.front()){
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
        // 2번 사용(앞에서 pop)
        else {
            while(v[i]!=dq.front()){
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }
        dq.pop_front();
    }

    // 출력
    cout << cnt << "\n";
}