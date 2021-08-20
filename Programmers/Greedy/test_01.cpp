// 01. 체육복
#include <string>
#include <vector>

using namespace std;
int student[35];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for (int i:lost) student[i]--;
    for (int i:reserve) student[i]++;
    for (int i=1; i<=n; i++){
        if (student[i] < 0){
            if (student[i-1] == 1)
                student[i] = student[i-1] = 0;
            else if (student[i+1]==1){
                student[i]++;
                student[i+1]--;
            }
        }
    }
    
    for (int i=1;i<=n;i++){
        if (student[i] >= 0)
            answer++;
    }
    
    return answer;
}