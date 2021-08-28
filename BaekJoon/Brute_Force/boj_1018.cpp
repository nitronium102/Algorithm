// 체스판 다시 칠하기
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string board[50];

string WB[8] = {
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW"
};

string BW[8] = {
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB"
};

int WB_cnt(int x, int y){
  int wb_cnt = 0;
  for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
      if (board[x+i][y+j] != WB[i][j])
        wb_cnt++;
    }
  }
  return wb_cnt;
}

int BW_cnt(int x, int y){
  int bw_cnt = 0;
  for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
      if (board[x+i][y+j] != BW[i][j])
        bw_cnt++;
    }
  }
  return bw_cnt;
}

int main(){
  int n, m, min_cnt=64;
  cin >> n >> m;
  for (int i=0; i<n; i++){
    cin >> board[i];
  }

  for (int i=0; i+8<=n; i++){
    for (int j=0; j+8<=m; j++){
      int cnt = min(WB_cnt(i, j), BW_cnt(i, j));
      if (min_cnt > cnt)
        min_cnt = cnt;
    }
  }

  cout << min_cnt;
}