// 직사각형에서 탈출
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int x, int y, int w, int h){
  int vertical = min(x, w-x);
  int horizontal = min(y, h-y);

  return min(vertical, horizontal);
}

int main() {
  int x, y, w, h;
  cin >> x >> y >> w >> h;
  cout << solution(x, y, w, h);
}