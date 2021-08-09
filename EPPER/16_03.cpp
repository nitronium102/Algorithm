// 프로그래밍3: [E-PPER]1505,1605-문자열압축 
// 비트가 0으로 시작 -> 그냥 알파벳 환산
// 비트 1로 시작 -> 앞에 1 붙이기

// 동일 문자 26회 이상 -> Z로 처리
#include <iostream>
#include <string>
using namespace std;

int main() {
    string src, result = "";
    cin >> src;

    char check = src[0]; //'0'
    int cnt = 1;

    if (src[0] == '1')
        result += "1";
    for (int i = 1; i < src.length(); i++) {
        if (check == src[i])
            cnt += 1;
        else {
            check = src[i];
            if (cnt >= 26)
                result += "Z";
            else
                result += char(cnt + 64);
            cnt = 1;
        }
    }
    result += char(cnt + 64);
    cout << result;
}