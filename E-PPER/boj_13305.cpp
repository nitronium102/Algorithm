// 13305번 주유소
#include <iostream>
#include <vector>
using namespace std;

long long solution(int city, vector<int> distance, vector<int> price){
  long long totalPrice = 0;
  long long minCost = price[0];

  for (int i=0; i<city-1; i++){
    if (minCost > price[i]){
      minCost = price[i];
    }
    totalPrice += minCost*distance[i];
  }
  return totalPrice;

}

int main(){
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