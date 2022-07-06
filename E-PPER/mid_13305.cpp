//
// Created by KangMinji on 2022-03-17.
//

/*
 * 주유소 : 그리디
 */

#include <iostream>
#include <vector>
using namespace std;

long long solution(int city, vector<int> distance, vector<int> price) {
    long long total_price = 0;
    long long min_price = price[0];

    for (int i=0; i<city-1; i++){
        if (min_price > price[i])
            min_price = price[i];
        total_price += min_price * distance[i];
    }
    return total_price;
}

int main() {
    int city, d, p;
    vector<int> distance;
    vector<int> price;

    cin >> city;
    for (int i=0; i<city-1; i++){
        cin >> d;
        distance.push_back(d);
    }

    for (int i=0; i<city; i++){
        cin >> p;
        price.push_back(p);
    }

    cout << solution(city, distance, price);
}