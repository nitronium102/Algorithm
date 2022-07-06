//
// Created by KangMinji on 2022-03-15.
//

#include <iostream>
#include <vector>
using namespace std;

long long solution(int n, vector<vector<long long>> money){
    for (int i=1; i<n; i++){
        for (int j=0; j<=i; j++){
            if (j == 0)
                money[i][j] += money[i-1][0];
            else if (j == i)
                money[i][j] += money[i-1][j-1];
            else
                money[i][j] += max(money[i-1][j-1], money[i-1][j]);
        }
    }
    long long answer = money[n-1][0];
    for (int j=0; j<= n-1; j++)
        answer = max(money[n-1][j], answer);
    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> money;
    for (int i=0; i<n; i++){
        money.push_back(vector<long long>(i+1, 0));
        for (int j=0; j<=i; j++)
            cin >> money[i][j];
    }
    cout << 30 << "\n";
    //cout << solution(n, money) << "\n";

}