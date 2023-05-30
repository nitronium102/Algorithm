//
// Created by KangMinji on 2023-01-10.
//

#include <iostream>
using namespace std;
const int MAX = 21;

// 동, 서, 남, 북
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
char board[MAX][MAX];
int alphabet[26] = {0,};
int row, col;
int max_cnt = 0;

bool isRange(int r, int c) {
    return (r >= 0) && (r < row) && (c >= 0) && (c < col);
}

void dfs(int r, int c, int cnt) {
    max_cnt = max(max_cnt, cnt);

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (isRange(nr, nc) && !alphabet[((int) board[nr][nc]) - 65]) {
            alphabet[((int) board[nr][nc]) - 65]++;
            dfs(nr, nc, cnt + 1);
            alphabet[((int) board[nr][nc]) - 65]--;
        }
    }
}

int main() {
    int t;

    // 입력
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        cin >> row >> col;

        // 초기화
        max_cnt = 0;
        fill(&alphabet[0], &alphabet[26], 0);
        for (int i = 0; i < MAX; i++) {
            fill(&board[i][0], &board[i][MAX], ' ');
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> board[i][j];
            }
        }

        // 연산
        alphabet[((int) board[0][0]) - 65]++;
        dfs(0, 0, 1);

        // 출력
        cout << "#" << test_case << " " << max_cnt << "\n";
    }
}