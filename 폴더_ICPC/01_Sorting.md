# 01. Sorting

## 1. 안정 정렬
정렬을 했을 때, 같은 값들은 정렬하기 전의 상대적 위치를 유지하는 정렬
### 1) 버블 정렬
1. 인접한 두 수를 선택한 뒤, 만약 그 두 수가 정렬되었다면 놔두고 아니라면 두 수를 바꾼다
2. 1.을 배열의 처음부터 끝까지 반복한다
3. 위 알고리즘을 배열에 아무 변화가 없을 때까지 반복한다
- 매번 반복할 때마다 가장 큰 수가 제일 뒤로 간다!
- 시간 복잡도 : O(N^2)

```
void bubbleSort(int arr[], int n){
    int i, j;
    for (i=0; i<n-1; i++)
        for (j=0; j<n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}
```

### 2) 삽입 정렬
1. k번째 원소를 앞의 원소들과 역순으로 비교하며, 처음으로 등장하는 k번째 원소보다 크지 않은 원소 뒤에 위치시킨다.
2. 1.을 배열의 처음부터 끝까지 반복한다.
3. 위 알고리즘을 배열에 아무 변화가 없을 때까지 반복한다.
- 매번 반복할 때마다 앞의 배열이 정렬된다!
- 시간 복잡도 : O(N^2)

```
void insertionSort(int arr[], int n){
    int i, key, j;
    for (i=1; i<n; i++){
        key = arr[i]; // 앞의 원소들과 비교할 원소
        j = i-1;
        
        // 앞의 원소가 key보다 크면 swap
        while(j>0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

```

### 3) 합병 정렬
1. 정렬되지 않은 배열의 크기가 1이 될 때까지 절반으로 잘라 나눈다.
2. 인접한 두 개의 배열을 정렬하면서 합친다.
3. 위 알고리즘을 배열이 모두 합쳐질 때까지 반복한다.
- 시간 복잡도 : O(NlogN)

리스트의 길이가 1 이하이면 이미 정렬된 것으로 본다. 그렇지 않은 경우에는
1. 분할 divide
2. 정복 conquer
3. 결합 combine
4. 복사 copy

## 2. 불안정 정렬
정렬을 했을 때, 같은 값들이 정렬하기 전의 상대적 위치와 달라질 수도 있는 정렬

### 1) 퀵 정렬
1. 임의의 index를 pivot으로 잡는다
2. 피봇 좌측에는 피봇보다 작은 수, 우측에는 큰 수가 오게끔 배치한다
3. 피봇을 제외한 피봇의 좌측과 우측 두 개의 리스트에 대해서 위 과정을 재귀적으로 반복한다
- 시간 복잡도 : O(N^2)

### 2) 선택 정렬
1. 정렬되지 않은 배열의 최솟값을 선택한다
2. 그 최솟값을 배열의 맨 앞의 값과 바꾼다
3. 최솟값이 저장된 index의 다음부터 위 과정을 반복한다
- 시간 복잡도 : O(N^2)

### 3) 힙 정렬
1. 정렬해야 할 n개의 원소들로 최대/최소 힙을 만든다
2. 한 번에 하나씩 원소를 힙에서 꺼내서 배열의 뒤부터 저장한다
3. 2.를 원소가 모두 꺼내질 때까지 반복한다
- 시간 복잡도 : O(NlogN)

-----
# std::sort
### 오름차순 정렬
- not stable : Intro sort(Insertion + Quick + Heap sort)
- stable : std::stable_sort
```
#include <algorithm>
sort(arr, arr+n);
```

### 내림차순 정렬
```
#include <algorithm>

bool compare(int a, int b){
    return a>b;
}

sort(arr, arr+n, cmp)
```

-----
# 기본 템플릿
```
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    // c의 stdio와 cpp의 iostream 동기화 비활성화
    ios_base::sync_with_stdio(false);
    
    // cin과 cout의 연결을 끊어줌
    // 원래는 cin이 들어오면 cout input buffer flush 해야 함
    cin.tie(NULL);
    
    return 0;
}
```