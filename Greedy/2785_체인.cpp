#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  // 시간
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // 입력
  int n;
  cin >> n;
  vector<int> v;
  v.assign(n, 0);
  for (int i=0; i<n; i++){
    cin >> v[i];
  }

  // 연산
  sort(v.begin(), v.end());

  /* 체인의 길이가 가장 작은 곳에서 고리 1개씩 떼어서,
  가장 긴 체인 2개를 이어준다*/
  int answer = 0;
  while(v.size() > 1) {
    v[v.size() - 2] += v[v.size()-1];
    v.pop_back();
    answer++;
    v[0]--;

    if (v[0] == 0) {
      v.erase(v.begin());
    }
  }

  // 출력
  cout << answer << "\n";
}