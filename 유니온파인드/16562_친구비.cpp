//
// Created by KangMinji on 2023-01-20.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findFriendCost(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0) {
            // 음수인 친구비를 더해준다
            sum -= parent[i];
        }
    }
    return sum;
}

int findParent(int node) {
    if (parent[node] < 0) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) {
        return;
    }

    // xp의 친구비가 더 적은 경우
    if (parent[xp] > parent[yp]) {
        parent[yp] = xp;
    } else {
        parent[xp] = yp;
    }
}

/*
 * 각 정점을 (-친구비)로 초기화
 * 친구비가 더 적은 루트를 선택!
 */
int main() {
    int n, m, k, cost, v, w;

    // 입력
    cin >> n >> m >> k;
    parent.assign(n+1, 0);
    for (int i=1; i<=n; i++){
        cin >> cost;
        parent[i] = -cost;
    }
    while (m--) {
        cin >> v >> w;
        unionInput(v, w);
    }

    int ans = findFriendCost(n);

    // 출력
    // 삼항 연산자 출력 시 자료형 일치
    cout << (ans <= k? to_string(ans) : "Oh no");
    return 0;
}