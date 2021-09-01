// 주울 수 있는 돈
#include <iostream>
#include <vector>
using namespace std;

// 돈의개수 n과 크기가 n인 수열 M이 주어졌을 때 
// 주울 수 있는 최대 돈을 구하는 함수
int max(int a, int b, int c){
	return (a>b)?(a>c)?a:c:(b>c)?b:c;
}

int solution(int n, vector<int> M)
{
	vector<int> dp(n+1, 0);
	dp[1] = M[0];
	if (n>1)
		dp[2] = M[0]+M[1];
	if (n>2){
		for (int i=3; i<=n; i++){
			// 01. N번째 돈을 줍지 않은 경우
			// 02. N-1번쨰와 N번째 돈을 주운 경우
			// 03. N번째와 N-2번째 돈을 주운 경우
			dp[i] = max(dp[i-1], dp[i-2]+M[i-1], dp[i-3]+M[i-2]+M[i-1]);
		}
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	
	vector<int> M(n, 0);
	for(int i=0; i<n; i++){
       cin >> M[i];  
   }
	
	int ans=solution(n,M);
	cout << ans << endl;
	return 0;
}