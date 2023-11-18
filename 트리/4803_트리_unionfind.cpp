// 골드4
// Created by KangMinji on 2023-01-20.
// https://www.acmicpc.net/problem/4803

#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<bool> cycle;

void print(int tc, int cnt){
    cout << "Case " << tc << ": ";
    switch (cnt) {
        case 0:
            cout << "No trees.\n";
            break;
        case 1:
            cout << "There is one tree.\n";
            break;
        default :
            cout << "A forest of "<< cnt << " trees.\n";
            break;
    }
}

int cntTree(int n){
    // 정점의 개수를 돌면서 루트 정점 구함(루트 정점의 개수 == 집합의 개수)
    int cnt = 0;
    for (int i=1; i<=n; i++){
        // 루트 정점이고 사이클이 없는 경우에만 트리
        if (parent[i] < 0 && !cycle[i]){
            cnt++;
        }
    }
    return cnt;
}

int findParent(int node){
    if (parent[node] < 0){
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

// union 연산
void unionInput(int x, int y){
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp){ // 사이클 발생
        cycle[xp] = true;
        return;
    }

    // 서로 다른 집합이지만, 하나라도 사이클이 있는 집합이라면
    if (cycle[xp] || cycle[yp]){
        cycle[xp] = cycle[yp] = true;
    }

    if (parent[xp] < parent[yp]){
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int main() {
    int n, m, a, b, tc=0;

    // 입력
    while(cin >> n >> m){
        if (n == 0 && m == 0){
            break;
        }
        // 연산
        tc++;
        parent.assign(n+1, -1);
        cycle.assign(n+1, false);

        while(m--){
            cin >> a >> b;
            unionInput(a, b);
        }
        // 연산 & 출력
        print(tc, cntTree(n));
    }

}