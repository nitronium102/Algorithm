#include <iostream>
using namespace std;

int main()
{
    int num;
    double max = 0;
    double avg = 0;
    cin >> num;

    int score[1000];

    for (int i = 0; i < num; i++)
    {
        cin >> score[i];
        if (max < score[i])
            max = score[i];
        avg += score[i];
    }

    avg = (avg / max * 100) / num;
    cout << fixed;
    cout.precision(2);
    cout << avg << endl;
    return 0;
}