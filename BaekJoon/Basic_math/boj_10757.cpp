#include <iostream>
#include <algorithm> // reverse
#include <string>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    
    int lenA = a.length();
    int lenB = b.length();
    
    // 무조건 A를 더 긴 문자열로!
    if (lenB > lenA){
        swap(a, b);
        swap(lenA, lenB);
    }
    
    // 자릿수 다르면 맞춰주기 ex) 1234 0059
    string tmp = "";
    for (int i = 0; i<(lenA-lenB); i++){
        tmp += "0";
    }
    b = tmp+b;
    
    // 끝에서부터 하나씩 나눠주기
    int carry = 0; // 반올림 수
    int x, y, digits;
    string ans=""; // 결과값
    for (int i = a.length()-1; i>=0; i--){
        x = a[i]-'0';
        y = b[i]-'0';
        digits = x+y;
        if (carry == 1){
            digits += 1;
            carry = 0;
        }
        if (digits > 9){
            carry = 1;
            ans += to_string(digits%10);
        }
        else {
            ans += to_string(digits);
        }
    }
    // 추가되는 한 자리 ex) 23+95 = (1)18
    if (carry == 1)
        ans += "1";
  
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    
}