#include <iostream>
using namespace std;

int main()
{
    int c, n, num = 0;
    double result, avg = 0;
    int score[1000] = {0};
    cin >> c; // 테스트케이스 개수

    for (int i = 0; i < c; i++)
    {
        cin >> n; // 학생의 수
        // N명의 점수 받기
        for (int j = 0; j < n; j++)
        {
            cin >> score[j];
            avg += score[j];
        }
        avg = avg / n;
        // 평균을 넘는 학생들 비율 반올림
        for (int j = 0; j < n; j++)
        {
            if (score[j] > avg)
                num++;
        }
        result = (double)num / n * 100;
        cout << fixed;
        cout.precision(3);
        cout << result << "%" << endl;

        avg = 0;
        num = 0;
    }
}