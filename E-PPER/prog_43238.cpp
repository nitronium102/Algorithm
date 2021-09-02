// 입국 심사
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = LLONG_MAX;
    
    sort(times.begin(), times.end());
    long long start = 1;
    long long end = n*times[times.size()-1];
    long long mid, temp=0;
    
    while (start <= end){
        mid = (start + end)/2;
        temp = 0;
        for (int i=0; i<times.size(); i++){
            temp += mid/times[i];
        }
        
        if (temp >= n){
            answer = min(answer, mid);
            end = mid + 1;
        }
        else 
            start = mid-1;
    }
    return answer;
}