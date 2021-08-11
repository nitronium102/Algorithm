#include <iostream>
using namespace std;

int main(){
    int T, H, W, N;
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> H >> W >> N;
        int room, floor;
        room = N/H;
        floor = N%H;
        
        if (floor == 0)
            floor = H;
        else
            room += 1;
        
        cout << floor*100 + room << endl;
    }
}