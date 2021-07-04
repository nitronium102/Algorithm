#include <iostream>
using namespace std;

int main()
{
    int length;
    int min = 1000000;
    int max = -1000000;
    cin >> length;
    int arr[length];
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];
    }

    cout << min << ' ' << max;
    return 0;
}