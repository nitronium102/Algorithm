// 직각삼각형
#include <iostream>
#include <algorithm> // swap
using namespace std;

int main() {
  while(1){
    int a, b, c, max;
    cin >> a >> b >> c;
    
    if (a==0&&b==0&&c==0)
      break;
    
    if (a>b)
      swap(a, b);

    if (b>c)
      swap(b, c);

    if (c*c == a*a + b*b)
      cout << "right" << "\n";
    else
      cout << "wrong" << "\n";  
  }
}