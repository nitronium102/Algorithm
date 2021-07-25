#include <iostream>
using namespace std;

int main(){
    int A, B, V, day;
    cin >> A >> B >> V;
    
    day = (V-A)/(A-B);
    if ((V-A)%(A-B) == 0)
        cout << day+1;
    else
        cout << day+2;
}