// [01] 16-3-똑똑한 이화
#include <iostream>
using namespace std;

int main() {
  int time, hour=0, min=0, sec=0;
  cin >> time;
  if (time >= 3600){
    hour = time/3600;
    min = (time%3600)/60;
    sec = (time%60);
  }
  else if ( time >= 60 ){
    min = time/60;
    sec = time%60;
  }
  else
    sec = time;

  cout << hour+min+sec << "\n";
}