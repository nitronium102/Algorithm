// 시험감독
#include <iostream>
#define MAX 1000001
using namespace std;
int A[MAX];

long long solution(int A[], int B, int C, int N){
  long long answer = 0;
  for (int i=0; i<N; i++){
    A[i] -= B;
    answer++;

    if (A[i] > 0){
      answer += A[i]/C;
      if (A[i]%C != 0)
        answer += 1;
    }
  }
  return answer;
}

int main() {
  int N, B, C;
  cin >> N;
  for (int i=0; i<N; i++){
    cin >> A[i];
  }
  cin >> B >> C;
  cout << solution(A, B, C, N);
}