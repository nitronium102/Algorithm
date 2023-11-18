//
// Created by KangMinji on 2023-01-20.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int findParent(int node){
    // 루트 정점은 음수값을 가짐
    if (parent[node] < 0){
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y){
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp){
        return;
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cmd, a, b;

    // 입력
    cin >> n >> m;
    parent.assign(n+1, -1); // weighted union find
    while(m--){
        cin >> cmd >> a >> b;

        // 연산
        if (!cmd){
            unionInput(a, b);
        } else {
            // union 수행 시에는 루트 정점으로 업데이트되는 것이 아니기 때문에
            // 그냥 parent[a] == parent[b]로 하면 안 됨!
            if (findParent(a)== findParent(b)){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

}