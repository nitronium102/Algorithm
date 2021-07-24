#include <iostream>
using namespace std;

int main(){
    int n, i=1;
    cin >> n;
    
    if (n == 1)
        cout << i;
    else{
        for (int sum=2; sum<=n; i++)
            sum += i*6;
        cout << i;
    }
}