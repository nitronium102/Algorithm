// 덩치
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i=0; i<n; i++){
    int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }

  int x1, x2, y1, y2;
  int cnt=1;
  for (int i=0; i<n; i++){
    x1 = v[i].first;
    y1 = v[i].second;
    for (int j=0; j<n; j++){
      x2 = v[j].first;
      y2 = v[j].second;
      if (x1 < x2 && y1 < y2)
        cnt++;
    }
    cout << cnt << " ";
    cnt = 1;
  }
}