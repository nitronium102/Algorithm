// 블랙잭
#include <iostream>
#define MAX 100
using namespace std;

int main(){
  int N, max, result=0, min = -1;
  int arr[MAX]= {0,};
  cin >> N >> max;
  
  for (int i=0; i<N; i++){
    cin >> arr[i];
  }

  for (int i=0; i<N; i++){
    for (int j=i+1; j<N; j++){
      for (int k=j+1; k<N; k++){
        int temp = arr[i]+arr[j]+arr[k];
        if (temp <= max && temp > min){
          min = temp;
          result = temp;
        }
      }
    }
  }

  cout << result;

}