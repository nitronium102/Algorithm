// 터렛(두 원 간의 교점)
#include <iostream>
#include <algorithm> // swap
#include <cmath> // sqrt, pow
using namespace std;

int main() {
  int T, x1, y1, r1, x2, y2, r2;
  cin >> T;
  for (int i=0; i<T; i++){
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if (r2 > r1){ // 항상 r1이 r2보다 크도록
      swap(r1, r2);
    }
    double distance = sqrt(pow(x1-x2,2) + pow(y1-y2, 2));
    // 00. 교점 무한개(동일한 원)
    if (distance == 0 && r1==r2)
      cout << -1;
    // 01. 교점 2개( R-r < d < R+r )
    else if (distance < (r1+r2) && distance > (r1-r2))
      cout << 2;
    // 02. 교점 1개(외접, 내접)
    else if (distance == (r1+r2) || distance == (r1-r2))
      cout << 1;
    // 03. 교점 0개
    else
      cout << 0;

    cout << "\n";
  }
}