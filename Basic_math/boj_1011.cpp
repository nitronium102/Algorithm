#include <iostream>
using namespace std;

int main(){
    int T, x, y;
    cin >> T;
    for (int i =0; i<T; i++){
        cin >> x >> y;
        int max_distance = 1;
        int cnt = 0;
        int distance = y-x;
        
        // 1 > 2 > 1 = 1+2+1 = 4 -> 2*
        // 1 > 2 > 3 > 2 > 1 = 1+2+3+2+1 = 9
        while(distance>0){
            if (distance > max_distance){
                cnt += 1;
                max_distance+=1;
            }
            else {
                if (distance == 1){
                    cnt += 1;
                    max_distance = 1;
                    break;
                }
                else {
                    distance -= max_distance;
       
                    cnt+=1;
                }
            }
        }
        cout << cnt << endl;
    }
}