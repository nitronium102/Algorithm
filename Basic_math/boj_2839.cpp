#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int three, left;
    int five = N/5;
    while(true){
        if (five < 0){
            cout << -1;
            break;
        } 
        if ((N-5*five)%3 == 0){
             three = (N-5*five)/3;
             cout << five+three;
             break;
         }
        five--;
    }
}