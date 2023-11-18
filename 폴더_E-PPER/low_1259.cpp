//
// Created by KangMinji on 2022-03-17.
//

/*
 * 팰린드롬수
 */

#include <iostream>
using namespace std;

bool solution(int input) {
    int original_input = input;
    int reversed_input = 0;

    while (input > 0){
        reversed_input = reversed_input*10 + input%10;
        input /= 10;
    }

    return original_input == reversed_input;
}

int main() {
    int input;
    bool isPelindrome;

    while (true) {
        cin >> input;
        if (input == 0)
            return 0;
        isPelindrome = solution(input);
        if (isPelindrome)
            cout << "yes";
        else
            cout << "no";
        cout << "\n";
    }
}
