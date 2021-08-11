// 프로그래밍5: [E-PPER]1507,1607-도서관 좌석 예약 
#include <iostream>
#include <vector>
#include <algorithm> // sort -> greedy
using namespace std;

vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b){
  // first = 희망 시작 시간
  // second = 희망 종료 시간
  if (a.second == b.second){ // 끝나는 시간 같으면 시작 시간 빠른 것을 앞으로
    return a.first < b.first;
  }
  else
    return a.second < b.second; // 종료 시간 빠른 것을 앞으로
}


int solution(int s[], int e[], int student){
  int ans=0;

  int s1= -1, s2=-1;
  // 01. vector에 match
  for (int i=0; i<student; i++){
    v.push_back({s[i], e[i]});
  }
  // 02. 시작 시간, 종료 시간 빠른 순으로 정렬
  sort(v.begin(), v.end(), compare);
  
  // 03. 배치
  for (int i=0; i<student; i++){
    if (s1 <= v[i].first){
      ans++;
      s1 = v[i].second;
    }
    else if (s2 <= v[i].first){
      s2 = s1;
      s1 = v[i].second;
      ans++;
    }
  }

  return ans;
}

int main(){
  int s[] = {30140, 23679, 17663, 8492, 9777, 17803, 55388, 7420, 23107, 37469};
  int e[] = {55374, 33664, 43614, 12763, 85637, 58156, 
79170, 60252, 52676, 48022};
  int student = sizeof(s)/sizeof(int);
  cout << solution(s, e, student);
}