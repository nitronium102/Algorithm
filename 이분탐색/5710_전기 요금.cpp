// 골드4
// Created by KangMinji on 2023-02-06.
// https://www.acmicpc.net/problem/5710

#include <iostream>

using namespace std;

int a, b;

int findPrice(int wh) {
	if (wh <= 100) {
		return wh * 2;
	} else if (wh <= 10000) {
		return 200 + (wh - 100) * 3;
	} else if (wh <= 1000000) {
		return 29900 + (wh - 10000) * 5;
	} else {
		return 4979900 + (wh - 1000000) * 7;
	}
}

int findWh(int price) {
	int wh = 0;
	wh += min(price, 200) / 2;
	price -= 200;

	if (price > 0){
		wh += min(price, 29700) / 3;
		price -= 29700;
		if (price > 0){
			wh += min(price, 4950000) / 5;
			price -=  990000 * 5;
			if (price > 0){
				wh += price / 7;
			}
		}
	}
	return wh;
//	if (price <= 200) {
//		return price / 2;
//	} else if (price <= 29900) { // 200 + 9900*3
//		return 100 + (price - 200) / 3;
//	} else if (price <= 4979900) { // 200 + 9900*3 + 990000*5
//		return 10000 + (price - 29900) / 5;
//	} else {
//		return 1000000 + (price - 4950000) / 7;
//	}
}

int binarySearch(int wh) {
	int mid, left = 0, right = wh;

	while (left <= right) {
		mid = (left + right) / 2;
		int my_price = findPrice(mid);
		int n_price = findPrice(wh - mid); // 그냥 price - my_price하면 안 나옴!

		int diff = n_price - my_price;
		if (diff == b){
			return my_price;
		}

		if (diff < b) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
}

int main() {

	while (cin >> a >> b) {
		if (a == 0 && b == 0) {
			break;
		}
		int wh = findWh(a);
		cout << binarySearch(wh) << "\n";
	}

	return 0;
}