#include <iostream>
using namespace std;

int main()
{
    int c, n, num = 0;
    double result, avg = 0;
    int score[1000] = {0};
    cin >> c; // �׽�Ʈ���̽� ����

    for (int i = 0; i < c; i++)
    {
        cin >> n; // �л��� ��
        // N���� ���� �ޱ�
        for (int j = 0; j < n; j++)
        {
            cin >> score[j];
            avg += score[j];
        }
        avg = avg / n;
        // ����� �Ѵ� �л��� ���� �ݿø�
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