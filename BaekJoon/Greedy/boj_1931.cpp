// 회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

bool compare(pair<int, int>a, pair<int, int> b){
  // first : 시작 시간(첫 번째 인수)
  // second : 종료 시간(두 번째 인수)

  // 끝나는 시간 같으면 시작 시간 빠른 것을 앞으로
  if (a.second == b.second){ 
    return a.first < b.first;
  }
  // 기본적으로는 종료 시간 빠른 것을 앞으로
  else
    return a.second < b.second;

}

int main(){
  int N, start, end;
  cin >> N;
  // vector에 넣기
  for (int i=0; i<N; i++){
    cin >> start >> end;
    v.push_back({start, end});
  }

  // 정렬
  sort(v.begin(), v.end(), compare);

  int occupy = v[0].second;
  int cnt = 1;
  for (int i=1; i<N; i++){
    if (occupy <= v[i].first){
      cnt++;
      occupy = v[i].second;
    }
  }
  cout << cnt;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
	}
	sort(a.begin(), a.end());
	int savetime = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (savetime <= a[i].second) {
			savetime = a[i].first;
			ans++;
		}
	}
	printf("%d", ans);

}
*/