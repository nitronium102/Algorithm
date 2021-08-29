// 영화감독
#include <iostream>
#include <string>
using namespace std;

int main(){
  int n, cnt=0, ans=0;
  cin >> n;
  for (int i=666; ;i++){
    if (to_string(i).find("666") != string::npos)
      cnt++;

    if (cnt == n){
      ans=i;
      break;
    }
  }

  cout << ans;
}